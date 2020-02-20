#include <algorithm>
#include <cassert>
#include <numeric>

#include "arpa/inet.h"

#include "crc.h"
#include "spirent_pga/functions.h"

namespace pga::signature {

struct spirent_signature
{
    uint8_t data[16];
    uint16_t crc;
    uint16_t cheater;
} __attribute__((packed));

static uint16_t calculate_crc16(const uint8_t data[], uint16_t length)
{
    static constexpr DECLARE_ALIGNED(
        struct crc_pclmulqdq_ctx spirent_crc16_clmul, 16) = {
        0x45630000, /**< remainder X^128 / P(X) */
        0xd5f60000, /**< remainder X^192 / P(X) */
        0xaa510000, /**< remainder  X^64 / P(X) */
        0x11303471, /**< quotient   X^64 / P(X) */
        0x10210000, /**< polynomial */
        0ULL        /**< reserved */
    };

    return (~(crc32_calc_pclmulqdq(data, length, 0xffff, &spirent_crc16_clmul)
              >> 16));
}

static constexpr auto prefetch_offset = 8;

uint16_t
crc_filter(const uint8_t* payloads[], uint16_t count, int crc_matches[])
{
    /*
     * Unless the user has already done something with the payload, it is
     * unlikely to be in the CPU cache.  Hence, we explicitly prefetch
     * the payload before calculating the CRC.
     */
    auto offset = std::min(static_cast<int>(count), prefetch_offset);

    std::for_each(payloads, payloads + offset, [](const auto& payload) {
        __builtin_prefetch(payload);
    });

    std::transform(
        payloads, payloads + count, crc_matches, [&](const auto& payload) {
            if (offset < count) { __builtin_prefetch(payloads[offset++]); }

            auto signature =
                reinterpret_cast<const spirent_signature*>(payload);
            return (ntohs(signature->crc)
                    == calculate_crc16(signature->data, 16));
        });

    return (std::accumulate(crc_matches, crc_matches + count, 0));
}

uint16_t decode(const uint8_t* payloads[],
                uint16_t count,
                uint32_t stream_ids[],
                uint32_t sequence_numbers[],
                uint64_t timestamps[],
                int flags[])
{
    /* Note: decode_loop_count should be a multiple of all vector widths */
    static constexpr auto decode_loop_count = 32;
    std::array<uint32_t, decode_loop_count> timestamp_lo;
    std::array<uint32_t, decode_loop_count> timestamp_hi;

    auto& functions = functions::instance();

    uint16_t nb_signatures = 0;
    uint16_t begin = 0;

    while (begin < count) {
        auto end = begin + std::min(decode_loop_count, count - begin);
        auto loop_count = end - begin;

        /* Hand the payloads off to our decode function */
        auto loop_signatures =
            functions.decode_signatures_impl(payloads + begin,
                                             loop_count,
                                             stream_ids + begin,
                                             sequence_numbers + begin,
                                             timestamp_lo.data(),
                                             timestamp_hi.data(),
                                             flags + begin);

        /* Then merge hi/lo timestamp data together */
        std::transform(timestamp_hi.data(),
                       timestamp_hi.data() + loop_count,
                       timestamp_lo.data(),
                       timestamps + nb_signatures,
                       [](auto& hi, auto& lo) {
                           /* Only 38 bits of the timestamp are valid */
                           return (static_cast<uint64_t>(hi) << 32 | lo)
                                  & 0x3fffffffff;
                       });

        nb_signatures += loop_signatures;
        begin = end;
    }

    return (nb_signatures);
}

void encode(uint8_t* destinations[],
            const uint32_t stream_ids[],
            const uint32_t sequence_numbers[],
            uint64_t timestamp,
            int flags,
            uint16_t count)
{
    auto& functions = functions::instance();

    /* Write the signature data into place */
    functions.encode_signatures_impl(
        destinations, stream_ids, sequence_numbers, timestamp, flags, count);

    /*
     * And calculate the CRC for each signature.
     * Note: we just zero out the cheater since we expect hardware to
     * do the payload checksumming for us.
     */
    std::for_each(destinations, destinations + count, [](auto& destination) {
        auto signature = reinterpret_cast<spirent_signature*>(destination);
        signature->crc = calculate_crc16(signature->data, 16);
        signature->cheater = 0;
    });
}

} // namespace pga::signature