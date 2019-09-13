#include <array>

#include "catch.hpp"

#include "spirent_pga/api.h"
#include "api_test.h"

TEST_CASE("PRBS functions", "[spirent-pga]")
{
    constexpr uint32_t seed = 0xffffffff;

    SECTION("implementations") {
        auto& functions = pga::functions::instance();
        /*
         * Start by generating scalar PRBS data.  We use it as the basis
         * for all further tests.
         */
        constexpr int buffer_size = 1024;
        std::array<uint32_t, buffer_size> ref_data;
        auto scalar_fn = pga::test::get_function(functions.fill_prbs_aligned_impl,
                                                 pga::instruction_set::type::SCALAR);
        REQUIRE(scalar_fn != nullptr);
        auto ref_next_seed = scalar_fn(ref_data.data(), ref_data.size(), seed);

        SECTION("generation") {
            /*
             * Check that all available PRBS functions generate the same data.
             * We do that by comparing the scalar reference data to what is
             * generated by all of the available vector functions.
             */
            std::array<uint32_t, buffer_size> data;
            unsigned vector_tests = 0;

            for (auto instruction_set : pga::test::vector_instruction_sets()) {
                auto vector_fn = pga::test::get_function(functions.fill_prbs_aligned_impl,
                                                         instruction_set);
                /*
                 * Obviously, we can't test a null function or an instruction set
                 * our CPU won't run.
                 */
                if (!(vector_fn && pga::instruction_set::available(instruction_set))) {
                    continue;
                }

                INFO("instruction set = " << pga::instruction_set::to_string(instruction_set));

                vector_tests++;

                auto next_seed = vector_fn(data.data(), data.size(), seed);
                REQUIRE(ref_next_seed == next_seed);
                REQUIRE(std::equal(std::begin(ref_data), std::end(ref_data),
                                   std::begin(data)));
            }

            /* We should have at least one vector function, right? */
            REQUIRE(vector_tests > 0);
        }

        SECTION("verification") {
            /*
             * All of our verify functions should return the reference seed,
             * since that's the next seed in the sequence, and 0 bit errors.
             */
            unsigned verify_tests = 0;
            uint64_t verify_result = static_cast<uint64_t>(ref_next_seed) << 32 | 0;

            for (auto instruction_set : pga::test::instruction_sets()) {
                auto verify_fn = pga::test::get_function(functions.verify_prbs_aligned_impl,
                                                         instruction_set);

                if (!(verify_fn && pga::instruction_set::available(instruction_set))) {
                    continue;
                }

                INFO("instruction set = " << pga::instruction_set::to_string(instruction_set));

                verify_tests++;

                /*
                 * Make sure that the verify function figures out the sequence (by returning
                 * the correct seed) and detects no errors.
                 */
                auto result = verify_fn(ref_data.data(), ref_data.size(), ~ref_data[0]);
                REQUIRE(verify_result == result);

                /*
                 * Now, flip one bit in each "quadlet" and make sure that the
                 * bit error is found.
                 */
                uint16_t offset = 0;
                std::for_each(ref_data.data(), ref_data.data() + ref_data.size(),
                          [&](auto& quadlet) {
                              /* Flip a bit */
                              quadlet ^= 1;

                              auto result = verify_fn(ref_data.data(), ref_data.size(), ~ref_data[0]);
                              uint32_t bit_errors = result & 0xffffffff;
                              if (instruction_set == pga::instruction_set::type::SCALAR) {
                                  /*
                                   * The scalar version requires two sequential quadlets without errors to sync
                                   * to the PRBS pattern, hence we'll have higher than expected error counts for
                                   * the first two quadlets as the verify function is comparing the payload data
                                   * to the wrong expected values.
                                   */
                                  REQUIRE(static_cast<bool>(offset > 2 ? bit_errors == 1 : bit_errors < 32));
                              } else {
                                  /*
                                   * Vector versions will only see erroneous errors counts for errors in the
                                   * first quadlet.  The most we could possibly see would be 15 * 32, so make
                                   * sure our count is below that.
                                   */
                                  REQUIRE(static_cast<bool>(offset > 1 ? bit_errors == 1 : bit_errors < (15 * 32)));
                              }

                              /* Unflip the bit */
                              quadlet ^= 1;

                              offset++;
                          });
            }
            /* scalar + at least 1 vector */
            REQUIRE(verify_tests > 1);
        }
    }

    SECTION("API") {
        /*
         * The API functions handle alignment issues that the aligned vector
         * functions can't handle.  As such, we only really need to make sure
         * alignment cases are handled correctly.  The previous section verified
         * the core implementations.
         */
        constexpr size_t buffer_size = 32;
        std::array<uint8_t, buffer_size> buffer;

        SECTION("unaligned start") {
            for (auto offset : { 1, 2, 3 }) {
                auto ptr = &buffer[offset];
                uint16_t length = buffer_size - offset;

                pga_fill_prbs(&ptr, &length, 1, seed);

                uint32_t bit_errors = 0;
                auto errors = pga_verify_prbs(&ptr, &length, 1, &bit_errors);
                REQUIRE(bit_errors == 0);
                REQUIRE(errors == false);
            }
        }

        SECTION("unaligned end") {
            for (auto offset : { 1, 2, 3 }) {
                auto ptr = buffer.data();
                uint16_t length = buffer_size - offset;

                pga_fill_prbs(&ptr, &length, 1, seed);

                uint32_t bit_errors = 0;
                auto errors = pga_verify_prbs(&ptr, &length, 1, &bit_errors);
                REQUIRE(bit_errors == 0);
                REQUIRE(errors == false);
            }
        }
    }
}
