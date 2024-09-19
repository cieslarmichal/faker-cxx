#pragma once

#include <concepts>
#include <random>
#include <stdexcept>
#include <map>
#include <limits>
#include<set>

#include "faker-cxx/export.h"


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
 *
 * @code
 * faker::number::integer(5, 10) // 7
 * @endcode
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
 * @see integer<I>(I)
 *
 * @return T a random integer number
 *
 * @code
 * faker::number::integer(10) // 5
 * @endcode
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
    if(standardDeviation < 0 || standardDeviation == INFINITY || mean == INFINITY)
    {
        throw std::invalid_argument("Standard Deviation cannot be negative");
    }
    else if(standardDeviation == 0)
    {
        return mean;
    }

	std::random_device randDev;
	std::mt19937 PSRNG(randDev());

	std::normal_distribution<F> dist(mean, standardDeviation);
	return dist(PSRNG);
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
    else if(sample < min)
    {
        sample = min;
    }
	return sample;
}


struct FAKER_CXX_EXPORT CharCount
{
    unsigned int atLeastCount{(std::numeric_limits<unsigned int>::min)()};
    unsigned int atMostCount{(std::numeric_limits<unsigned int>::max)()};
};

/**
 * A std::map where user can specify the count required for specific chars
 */
using GuaranteeMap = std::map<char, CharCount>;

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
 * @brief Generates a binary string.
 *
 * @param guarantee A map specifying char count constraints if any
 * @param length The number of digits to generate. Defaults to `1`.
 *
 * @returns Binary string.
 *
 * @code
 * faker::string::binary({'1',{7,8}}, 8) // "0b11110111"
 * @endcode
 */
FAKER_CXX_EXPORT std::string binary(GuaranteeMap&& guarantee, unsigned length = 1);

/**
 * @brief Checks if the given guarantee map is valid for given targetCharacters and length.
 *
 * @returns a bool.
 *
 * @param guarantee A std::map that maps the count range of specific characters required
 * @param targetCharacters A std::string consisting of all chars available for that string generating function
 * @param length The number of characters to generate.
 *
 * @code
 * GuaranteeMap guarantee = {{'0',{5,10}},{'1',{6,10}}};
 * std::string targetCharacters = "01";
 * unsigned int length = 10;
 * faker::string::isValidGuarantee(guarantee,targetCharacters,length) // false
 * @endcode
 */
FAKER_CXX_EXPORT bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length);

/**
 * @brief Generates the least required string for a given guarantee map
 *
 * @returns least required std::string
 *
 * @param guarantee A std::map<char,CharCount> which stores the guarantee specified by the user
 *
 * @code
 * GuaranteeMap guarantee { {'0',{3,10}},{'a',{6,8}} }; // "000aaaaaa"
 * faker::string::generateAtLeastString(guarantee);
 * @endcode
 */
FAKER_CXX_EXPORT std::string generateAtLeastString(const GuaranteeMap& guarantee);

}
