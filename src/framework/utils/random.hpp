#ifndef _OP_UTILS_RANDOM_HPP_
#define _OP_UTILS_RANDOM_HPP_

#include <random>

namespace openperf::utils {

template <class T> static T random_uniform(T lower_bound, T upper_bound)
{
    static std::mt19937_64 generator{std::random_device()()};
    std::uniform_int_distribution<T> dist(lower_bound, upper_bound - 1);
    return dist(generator);
}

template <class T>
static T random_uniform(T max = std::numeric_limits<T>::max())
{
    return random_uniform(T(0), max);
}

inline void op_prbs23_fill(uint32_t* seedp, void* buffer, size_t length)
{
    uint32_t seed = *seedp;
    uint32_t* ptr = reinterpret_cast<uint32_t*>(buffer);

    for (size_t i = 0; i < length / 4; i++) {
        uint32_t temp = (seed << 9) ^ (seed << 14);
        seed = temp ^ (temp >> 23) ^ (temp >> 18);
        *(ptr + i) = temp;
    }

    *seedp = seed;
}

inline void op_prbs23_fill(void* buffer, size_t length)
{
    auto seed = random_uniform<uint32_t>();
    op_prbs23_fill(&seed, buffer, length);
}

} // namespace openperf::utils

#endif // _OP_UTILS_RANDOM_HPP_
