#pragma once

#include <concepts>
#include <optional>
#include <random>
#include <stdexcept>
#include <type_traits>

#include "faker-cxx/export.h"
#include "faker-cxx/generator.h"
#include "faker-cxx/types/hex.h"

namespace faker::number
{
/**
 * @brief Generates a random integer number in the given range, bounds included.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @tparam I the type of the generated number, must be an integral type whose size is not larger than sizeof(long long).
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @return T a random integer number
 *
 * @code
 * faker::number::integer(5, 10) // 7
 * @endcode
 */
template <std::integral I>
    requires(sizeof(I) <= sizeof(long long))
I integer(I min, I max)
{
    // std::uniform_int_distribution only accepts certain types, so we use signed or unsigned long long and don't allow
    // larger types
    using LongLongType = std::conditional_t<std::is_unsigned_v<I>, unsigned long long, long long>;

    if (min > max)
    {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::mt19937_64& pseudoRandomGenerator = getGenerator();

    std::uniform_int_distribution<LongLongType> distribution(min, max);

    return static_cast<I>(distribution(pseudoRandomGenerator));
}

/**
 * @brief Generates a random integer between 0 and the given maximum value, bounds included.
 *
 * @tparam I the type of the generated number, must be an integral type whose size is not larger than sizeof(long long).
 * @param max the maximum value of the range.
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @see integer<I>(I)
 *
 * @return T a random integer number
 *
 * @code
 * faker::number::integer(10) // 5
 * @endcode
 */
template <std::integral I>
    requires(sizeof(I) <= sizeof(long long))
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
 *
 * @code
 * faker::number::decimal(10.2, 17.7) // 15.6
 * @encode
 */
template <std::floating_point F>
F decimal(F min, F max)
{
    if (min > max)
    {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::mt19937_64& pseudoRandomGenerator = getGenerator();
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
 * @see decimal<F>(F)
 *
 * @return F, a random decimal number.
 *
 * @code
 * faker::number::decimal(20.5) // 17.2
 * @encode
 */
template <std::floating_point F>
F decimal(F max)
{
    return decimal<F>(static_cast<F>(0.), max);
}

/**
 * @brief Generates a number following a normal distribution given a mean and standard deviation.
 *
 * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
 *
 * @param mean The mean value of the normal distribution
 * @param standard_deviation the standard deviation of the normal distribution
 *
 * @throws std::invalid_argument if standard deviation is negative or infinity, or if mean is infinity
 *
 * @return F, a random floating point number following the specified normal distribution
 *
 * @code
 * faker::number::normalDistribution(10, 3) // 12.374
 * @encode
 */

template <std::floating_point F>
F normalDistribution(F mean, F standardDeviation)
{
    if (standardDeviation < 0 || standardDeviation == INFINITY || mean == INFINITY)
    {
        throw std::invalid_argument("Standard Deviation cannot be negative");
    }
    else if (standardDeviation == 0)
    {
        return mean;
    }

    std::mt19937_64& pseudoRandomGenerator = getGenerator();

    std::normal_distribution<F> distribution(mean, standardDeviation);
    return distribution(pseudoRandomGenerator);
}

/**
 * @brief Generates a number following a normal distribution within the specified range
 *
 * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
 *
 * @param mean The mean value of the normal distribution
 * @param standard_deviation The standard deviation of the normal distribution
 * @param min The lowest possible output
 * @param max The highest possible output
 *
 * @return F, a random floating point number following the specified normal distribution within the specified range
 *
 * @throws std::invalid_argument if min is greater than max
 *
 * @see normalDistribution<F>(F, F)
 *
 * @code
 * faker::number::normalDistribution(10, 3, 9, 11) // 9
 * @encode
 */

template <std::floating_point F>
F normalDistribution(F mean, F standardDeviation, F min, F max)
{
    if (min > max)
    {
        throw std::invalid_argument("min cannot be larger than max");
    }

    F sample = normalDistribution(mean, standardDeviation);

    if (sample > max)
    {
        sample = max;
    }
    else if (sample < min)
    {
        sample = min;
    }

    return sample;
}

/**
 * @brief Generates a hexadecimal string.
 *
 * @param length The number of digits to generate. Defaults to `1`.
 * @param casing Casing of the generated string. Defaults to `HexCasing::Lower`.
 * @param prefix Prefix for the generated string. Defaults to `0x`.
 *
 * @returns Hexadecimal string.
 *
 * @code
 * faker::string::hexadecimal() // "0xb"
 * faker::string::hexadecimal(10) // "0xae13d044cb"
 * faker::string::hexadecimal(6, HexCasing::Upper, HexPrefix::Hash) // "#E3F380"
 * faker::string::hexadecimal(6, HexCasing::Lower, HexPrefix::None) // "e3f380"
 * @endcode
 */
FAKER_CXX_EXPORT std::string hexadecimal(unsigned length = 1, HexCasing casing = HexCasing::Lower,
                                         HexPrefix prefix = HexPrefix::ZeroX);

/**
 * @brief Returns a lowercase hexadecimal number.
 *
 * @param min Optional parameter for lower bound of generated number.
 * @param max Optional parameter for upper bound of generated number.
 *
 * @return A lowercase hexadecimal number.
 *
 * @code
 * faker::string::hexadecimal() // "b"
 * faker::string::hexadecimal(0, 255) // "9d"
 * @endcode
 */
FAKER_CXX_EXPORT std::string hexadecimal(std::optional<int> min = std::nullopt, std::optional<int> max = std::nullopt);

/**
 * @brief Generates an octal string.
 *
 * @param length The number of digits to generate. Defaults to `1`.
 *
 * @returns Octal string.
 *
 * @code
 * faker::string::octal(8) // "0o52561721"
 * @endcode
 */
FAKER_CXX_EXPORT std::string octal(unsigned length = 1);

/**
 * @brief Generates a binary string of a specified length
 *
 * @param length The number of digits to generate. Defaults to `1`.
 *
 * @returns Binary string.
 *
 * @throws std::invalid_argument, if length is negative
 *
 * @code
 * faker::string::binary(8) // "0b01110101"
 * @endcode
 */
FAKER_CXX_EXPORT std::string binary(int length = 1);

/**
 * @brief Generates a random binary string which has its decimal equivalent between min and max inclusive
 *
 * @param min the minimum possible decimal equivalent of the output
 * @param max the maximum possible decimal equivalent of the output
 *
 * @returns Binary string.
 *
 * @throws std::invalid_argument, if min > max, std::invalid_argument if min or max are negative
 *
 * @code
 * faker::string::binary(0, 1024) // "0b10110"
 * @endcode
 */
FAKER_CXX_EXPORT std::string binary(int min, int max);

/**
 * @brief Returns a roman numeral in String format.
 *
 * @param min Optional parameter for lower bound of generated number.
 * @param max Optional parameter for upper bound of generated number.
 *
 * @return roman number
 *
 *
 * @throws std::invalid_argument, if min > max, std::invalid_argument if min or max are negative
 * @throws std::invalid_argument, if min<1, value less than 1 cannot be represented
 * @throws std::invalid_argument, if max>3999, value greater than 3999 cannot be represented
 * 
 * @code
 * faker.number.romanNumeral() // 'MDCCCXIX'
 * faker.number.romanNumeral(5) // 'II'
 * faker.number.romanNumeral({ min: 10 }) // 'CCCXXXIX'
 * faker.number.romanNumeral({ max: 20 }) // 'III'
 * faker.number.romanNumeral({ min: 5, max: 10 }) // 'V'
 * @endcode
 */
FAKER_CXX_EXPORT std::string roman(std::optional<int> min = std::nullopt, std::optional<int> max = std::nullopt);


}