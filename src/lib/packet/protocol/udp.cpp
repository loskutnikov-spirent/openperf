/**
 * udp implementation for the packet header C++ Library
 *
 * This file is automatically generated by the library code generator.
 * Do not edit this file manually.
 **/

#include "udp.hpp"

namespace libpacket::protocol {

/**
 * udp getter implementations
 **/

uint16_t get_udp_source(const udp& header) noexcept
{
    return (header.source.load());
}

uint16_t get_udp_destination(const udp& header) noexcept
{
    return (header.destination.load());
}

uint16_t get_udp_length(const udp& header) noexcept
{
    return (header.length.load());
}

uint16_t get_udp_checksum(const udp& header) noexcept
{
    auto tmp = header.checksum.load<uint16_t>();
    return (tmp);
}

/**
 * udp setter implementations
 **/

void set_udp_defaults(udp& header) noexcept
{
    set_udp_source(header, 3357);
    set_udp_destination(header, 3357);
}

void set_udp_source(udp& header, uint16_t value) noexcept
{
    header.source = value;
}

void set_udp_destination(udp& header, uint16_t value) noexcept
{
    header.destination = value;
}

void set_udp_length(udp& header, uint16_t value) noexcept
{
    header.length = value;
}

void set_udp_checksum(udp& header, uint16_t value) noexcept
{
    header.checksum.store(value);
}

/**
 * udp field translate implementation
 **/

template <typename Key, typename Value, typename... Pairs>
constexpr auto associative_array(Pairs&&... pairs)
    -> std::array<std::pair<Key, Value>, sizeof... (pairs)>
{
    return {{std::forward<Pairs>(pairs)...}};
}

enum udp::field_name udp::get_field_name(std::string_view name) noexcept
{
    constexpr auto field_names = associative_array<std::string_view, udp::field_name>(
        std::pair("source", udp::field_name::source),
        std::pair("destination", udp::field_name::destination),
        std::pair("length", udp::field_name::length),
        std::pair("checksum", udp::field_name::checksum));

    auto cursor = std::begin(field_names), end = std::end(field_names);
    while (cursor != end) {
        if (cursor->first == name) return (cursor->second);
        cursor++;
    }

    return (udp::field_name::none);
}

const std::type_info& udp::get_field_type(udp::field_name field) noexcept
{
    switch (field) {
        case udp::field_name::source:
            return (typeid(uint16_t));
        case udp::field_name::destination:
            return (typeid(uint16_t));
        case udp::field_name::length:
            return (typeid(uint16_t));
        case udp::field_name::checksum:
            return (typeid(uint16_t));
        default:
            return (typeid(nullptr));
    }
}

}
