#pragma once

#include <concepts>
#include <random>
#include <stdexcept>

namespace faker::number
{
/**
 * @brief Generates a random integer number in the given range, bounds included.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @tparam I the type of the generated number, must be an integral type (int, long, long long, etc.).
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @return T a random integer number
 */
template <std::integral I>
I integer(I min, I max)
{
    if (min > max)
    {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    static std::mt19937 pseudoRandomGenerator{std::random_device{}()};

    std::uniform_int_distribution<I> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

/**
 * @brief Generates a random integer between 0 and the given maximum value, bounds included.
 *
 * @tparam I the type of the generated number, must be an integral type (int, long, long long, etc.).
 * @param max the maximum value of the range.
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @see integer<I>(I, I)
 *
 * @return T a random integer number
 */
template <std::integral I>
I integer(I max)
{
    return integer<I>(static_cast<I>(0), max);
}

/**
 * @brief Generates a random decimal number in the given range, bounds included.
 *
 * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @return F a random decimal number.
 */
template <std::floating_point F>
F decimal(F min, F max)
{
    if (min > max)
    {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    static std::mt19937 pseudoRandomGenerator{std::random_device{}()};

    std::uniform_real_distribution<F> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

/**
 * @brief Generates a random decimal number between 0 and the given maximum value, bounds included.
 *
 * @tparam F The type of the generated number, must be a floating point type (float, double, long double).
 * @param max The maximum value of the range.
 *
 * @throws std::invalid_argument if max is less than 0.
 *
 * @see decimal<F>(F, F)
 *
 * @return F, a random decimal number.
 */
template <std::floating_point F>
F decimal(F max)
{
    return decimal<F>(static_cast<F>(0.), max);
}
}
