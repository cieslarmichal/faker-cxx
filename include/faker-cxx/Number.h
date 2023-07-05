/**
 * @file Number.h
 * @authors cieslarmichal, dario-loi
 * @brief Module that generates random numbers. by wrapping the C++ standard library random number generation utilities.
 * 
 * @date 2023-07-05
 * 
 * 
 */

#pragma once

#include <string>
#include <stdexcept>
#include <random>
#include <concepts>

namespace faker
{

/**
 * @brief A concept that checks if a type is a valid distribution.
 * 
 * @tparam DISTRIBUTION a distribution type, such as std::uniform_int_distribution
 */
template <class DISTRIBUTION>
concept Distribution = requires(DISTRIBUTION distribution) {
  true;
};

/**
 * @brief A concept that checks if a type is a valid integer distribution.
 * 
 * @tparam DISTRIBUTION a distribution type, must accept integral types as result_type
 */
template <class DISTRIBUTION>
concept IntegerDistribution = Distribution<DISTRIBUTION> && std::integral<typename DISTRIBUTION::result_type>;

/**
 * @brief A concept that checks if a type is a valid decimal distribution.
 * 
 * @tparam DISTRIBUTION a distribution type, must accept floating point types as result_type
 */
template <class DISTRIBUTION>
concept DecimalDistribution = Distribution<DISTRIBUTION> && std::floating_point<typename DISTRIBUTION::result_type>;


class Number
{

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;


public:

    /**
     * @brief Generates a random integer number in the given range, bounds included.
     * 
     * @param min the minimum value of the range
     * @param max the maximum value of the range
     * 
     * @tparam I the type of the generated number, must be an integral type (int, long, long long, etc.)
     * @tparam D the type of the distribution, must be a valid integer distribution (std::uniform_int_distribution, std::binomial_distribution, etc.)
     * 
     * @throws std::invalid_argument if min is greater than max
     * 
     * @see Distribution
     * 
     * @authors dario-loi, cieslarmichal
     * 
     * @return T a random integer number
     */
    template <std::integral I, IntegerDistribution D = std::uniform_int_distribution<I>>
    static I integer(I min, I max)
    {
        if (min > max)
        {
            throw std::invalid_argument("Minimum value must be smaller than maximum value.");
        }

        D distribution(min, max);

    return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random integer between 0 and the given maximum value, bounds included.
     *
     * The function invokes the integer<I>(I, I) function with min = 0, hence the distribution used is std::uniform_int_distribution.
     *
     * @tparam I the type of the generated number, must be an integral type (int, long, long long, etc.)
     * @param max the maximum value of the range
     * 
     * @throws std::invalid_argument if min is greater than max
     *
     * @see integer<I>(I, I)
     * 
     * @author dario-loi
     *
     * @return T a random integer number
     */
    template <std::integral I>
    static I integer(I max)
    {
        return Number::integer<I, std::uniform_int_distribution<I>>(static_cast<I>(0), max);
    }

    /**
     * @brief Generates a random decimal number in the given range, bounds included.
     * 
     * @tparam F the type of the generated number, must be a floating point type (float, double, long double)
     * @tparam D the type of the distribution, must be a valid float distribution (std::uniform_real_distribution, std::normal_distribution, etc.)
     * 
     * @param min the minimum value of the range
     * @param max the maximum value of the range
     * @param distribution the distribution to use
     * 
     * @throws std::invalid_argument if min is greater than max
     * @see Distribution
     * 
     * @author dario-loi
     *
     * @return F a random decimal number
     */
    template <std::floating_point F, DecimalDistribution D = std::uniform_real_distribution<F>>
    static F decimal(F min, F max)
    {
        if (min > max)
        {
            throw std::invalid_argument("Minimum value must be smaller than maximum value.");
        }

        D distribution(min, max);

        return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random decimal number between 0 and the given maximum value, bounds included.
     * 
     * The function invokes the decimal<F, D>(F, F) function with min = 0, hence the distribution used is std::uniform_real_distribution.
     * 
     * @tparam F the type of the generated number, must be a floating point type (float, double, long double)
     * @param max the maximum value of the range
     * 
     * @throws std::invalid_argument if min is greater than max
     * 
     * @see decimal<F, D>(F, F)
     * 
     * @return F, a random decimal number
     */
    template <std::floating_point F>
    static F decimal(F max)
    {
        return decimal<F>(static_cast<F>(0.), max);
    }

};


}