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

}
