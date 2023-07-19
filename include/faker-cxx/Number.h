#pragma once

#include <algorithm>
#include <concepts>
#include <random>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace faker
{
/**
 * @brief A concept that checks if a type is a valid distribution.
 *
 * The concept enforces a good number of the requirements specified for a RandomNumberDistribution in the C++ standard
 * library. We check that the provided distribution has all the necessary member functions and nested types, and that it
 * is equality comparable, copy constructible and copy assignable.
 *
 * This provides compile-time guarantees that the distribution is valid and can be used with the Number module.
 *
 * @see https://en.cppreference.com/w/cpp/named_req/RandomNumberDistribution
 * @tparam DISTRIBUTION a distribution type, such as std::uniform_int_distribution.
 */
template <class D>
concept Distribution =
    requires {
        // check that the result of the distribution is the same as the result of the operator()
        // also checks for existence of the result_type and param_type nested types, as well as the operator()
        requires std::is_same_v<typename D::result_type,
                                decltype(std::declval<D>()(std::declval<typename D::param_type&>()))>;

        // check that the distribution has a min(), max() and reset() member functions
        {
            std::declval<D>().min()
            } -> std::same_as<typename D::result_type>;
        {
            std::declval<D>().max()
            } -> std::same_as<typename D::result_type>;
        {
            std::declval<D>().reset()
            } -> std::same_as<void>;

        // check that the distribution is equality comparable, copy constructible and copy assignable
        {
            std::equality_comparable<D>
        };
        {
            std::is_copy_constructible_v<D>
        };
        {
            std::is_copy_assignable_v<D>
        };
        // check that the parameter type is equality comparable, copy constructible and copy assignable
        {
            std::equality_comparable<typename D::param_type>
        };
        {
            std::is_copy_constructible_v<typename D::param_type>
        };
        {
            std::is_copy_assignable_v<typename D::param_type>
        };

        // Check that the distribution has a param() -> param_type
        // and param(const param_type&) member functions
        {
            std::declval<D>().param()
            } -> std::same_as<typename D::param_type>;
        {
            std::declval<D>().param(std::declval<typename D::param_type&>())
            } -> std::same_as<void>;

        // check that D is printable to std::ostream
        {
            std::declval<std::ostream&>() << std::declval<D>()
            } -> std::same_as<std::ostream&>;

        // check that D can receive a value from std::istream
        {
            std::declval<std::istream&>() >> std::declval<D&>()
            } -> std::same_as<std::istream&>;
    };

/**
 * @brief A concept that checks if a type is a valid integer distribution.
 *
 * @tparam DISTRIBUTION a distribution type, must accept integral types as result_type.
 */
template <class DISTRIBUTION>
concept IntegerDistribution = Distribution<DISTRIBUTION> && std::integral<typename DISTRIBUTION::result_type>;

/**
 * @brief A concept that checks if a type is a valid decimal distribution.
 *
 * @tparam DISTRIBUTION a distribution type, must accept floating point types as result_type.
 */
template <class DISTRIBUTION>
concept DecimalDistribution = Distribution<DISTRIBUTION> && std::floating_point<typename DISTRIBUTION::result_type>;

class Number
{
public:
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
    static I integer(I min, I max)
    {
        if (min > max)
        {
            throw std::invalid_argument("Minimum value must be smaller than maximum value.");
        }

        std::uniform_int_distribution<I> distribution(min, max);

        return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random integer between 0 and the given maximum value, bounds included.
     *
     * The function invokes the integer<I>(I, I) function with min = 0, hence the distribution used is
     * std::uniform_int_distribution.
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
    static I integer(I max)
    {
        return Number::integer<I>(static_cast<I>(0), max);
    }

    /**
     * @brief Generates a random integer in the given range with a given distribution, bounds included.
     *
     * Note that for any distribution other than std::uniform_int_distribution, the bounds are enforced
     * through a std::clamp call, hence the statistical properties of the distribution may be altered,
     * especially for long tailed distributions.
     *
     * @tparam I the type of the generated number, must be an integral type (int, long, long long, etc.).
     * @tparam D the type of the distribution, must be a valid integer distribution (std::uniform_int_distribution,
     * std::binomial_distribution, etc.).
     *
     * @throws std::invalid_argument if min is greater than max.
     *
     * @param distribution The distribution to use.
     * @param min The minimum value of the range.
     * @param max The maximum value of the range.
     *
     * @return I a random integer number.
     */
    template <std::integral I, IntegerDistribution D>
    static I integer(D distribution, I min, I max)
    {
        if constexpr (std::is_same_v<D, std::uniform_int_distribution<I>>)
        {
            return Number::integer<I>(min, max);
        }
        {
            if (min > max)
            {
                throw std::invalid_argument("Minimum value must be smaller than maximum value.");
            }

            return std::clamp(distribution(pseudoRandomGenerator), min, max);
        }
    }

    /**
     * @brief Generates a random integer between 0 and the given maximum value with a given distribution, bounds
     * included.
     *
     * Defaults to a min value of 0.
     *
     * @tparam I The type of the generated number, must be an integral type (int, long, long long, etc.).
     * @tparam D The type of the distribution, must be a valid integer distribution (std::uniform_int_distribution,
     * std::binomial_distribution, etc.).
     * @param distribution The distribution to use.
     * @param max The maximum value of the range.
     *
     * @see IntegerDistribution
     * @see integer<D>(D, I, I)
     *
     * @throws std::invalid_argument if max is smaller than 0.
     *
     * @return I A random integer number
     */
    template <std::integral I, IntegerDistribution D>
    static I integer(D distribution, I max)
    {
        return Number::integer<I>(distribution, static_cast<I>(0), max);
    }

    /**
     * @brief Generates a random integer, unbounded, with a given distribution.
     *
     * @tparam I The type of the generated number, must be an integral type (int, long, long long, etc.).
     * @tparam D The type of the distribution, must be a valid integer distribution (std::uniform_int_distribution,
     * std::binomial_distribution, etc.).
     *
     * @param distribution The distribution to use.
     *
     * @return I A random integer number.
     *
     */
    template <std::integral I, IntegerDistribution D>
    static I integer(D distribution)
    {
        return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random decimal number in the given range, bounds included.
     *
     * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
     * @tparam D the type of the distribution, must be a valid float distribution (std::uniform_real_distribution,
     * std::normal_distribution, etc.).
     *
     * @param min The minimum value of the range.
     * @param max The maximum value of the range.
     * @param distribution The distribution to use.
     *
     * @throws std::invalid_argument if min is greater than max.
     *
     * @return F a random decimal number.
     */
    template <std::floating_point F>
    static F decimal(F min, F max)
    {
        if (min > max)
        {
            throw std::invalid_argument("Minimum value must be smaller than maximum value.");
        }

        std::uniform_real_distribution<F> distribution(min, max);

        return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random decimal number in the given range with a given distribution, bounds included.
     *
     * Note that for any distribution other than std::uniform_real_distribution, the bounds are enforced
     * through a std::clamp call, hence the statistical properties of the distribution may be altered,
     * especially for long tailed distributions.
     *
     * @tparam D the type of the distribution, must be a valid decimal distribution (std::uniform_real_distribution,
     * std::normal_distribution, etc.).
     * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
     *
     * @throws std::invalid_argument if min is greater than max.
     *
     * @see DecimalDistribution
     *
     * @param distribution The distribution to use.
     * @param min The minimum value of the range.
     * @param max The maximum value of the range.
     *
     * @return F a random decimal number.
     */
    template <std::floating_point F, DecimalDistribution D>
    static F decimal(D distribution, F min, F max)
    {
        if constexpr (std::is_same_v<D, std::uniform_real_distribution<F>>)
        {
            return Number::decimal<F>(min, max);
        }
        {
            if (min > max)
            {
                throw std::invalid_argument("Minimum value must be smaller than maximum value.");
            }

            return std::clamp(distribution(pseudoRandomGenerator), min, max);
        }
    }

    /**
     * @brief Generates a random decimal number between 0 and the given maximum value, bounds included.
     *
     * The function invokes the decimal<F, D>(F, F) function with min = 0, hence the distribution used is
     * std::uniform_real_distribution.
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
    static F decimal(F max)
    {
        return decimal<F>(static_cast<F>(0.), max);
    }

    /**
     * @brief Generates a random decimal number between 0 and the given maximum value with a given distribution, bounds
     * included.
     *
     * @tparam F The type of the generated number, must be a floating point type (float, double, long double).
     * @tparam D The type of the distribution, must be a valid float distribution (std::uniform_real_distribution,
     * std::normal_distribution, etc.).
     *
     * @param distribution The distribution to use.
     * @param max The maximum value of the range.
     *
     * @see decimal<F, D>(D, F, F)
     * @see DecimalDistribution
     *
     * @throws std::invalid_argument if max is less than 0.
     *
     * @return F a random decimal number.
     *
     */
    template <std::floating_point F, DecimalDistribution D>
    static F decimal(D distribution, F max)
    {
        return Number::decimal<F>(distribution, static_cast<F>(0.), max);
    }

    /**
     * @brief Generates a random decimal number in the given range, bounds included.
     *
     * @tparam F the type of the generated number, must be a floating point type (float, double, long double).
     * @tparam D the type of the distribution, must be a valid float distribution (std::uniform_real_distribution,
     * std::normal_distribution, etc.).
     *
     * @see DecimalDistribution
     *
     * @param distribution the distribution to use.
     *
     * @return F a random decimal number.
     */
    template <std::floating_point F, DecimalDistribution D>
    static F decimal(D distribution)
    {
        return distribution(pseudoRandomGenerator);
    }

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}
