#pragma once

#include <algorithm>
#include <concepts>
#include <optional>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace faker
{
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
    static F decimal(F max)
    {
        return decimal<F>(static_cast<F>(0.), max);
    }

    /**
     * @brief Returns a lowercase hexadecimal number.
     *
     * @param min Optional parameter for lower bound of generated number.
     * @param max Optional parameter for upper bound of generated number.
     *
     * @return A lowercase hexadecimal number.
     *
     * @code
     * Number::hex() // "b"
     * Number::hex(0, 255) // "9d"
     * @endcode
     */
    static std::string hex(std::optional<int> min = std::nullopt, std::optional<int> max = std::nullopt);

    /**
     * @brief Returns a list (count) of 0 based indices between [0, max)
     * 
     * @param max Max index
     * @param count Number of indices requested
     * 
     * @return A sorted vector of indices [0, max)
     * 
     * @code
     * Number::indices(5, 2) // {2, 4}
     * Number::indices(5, 5) // {0, 1, 2, 3, 4}
    */
    static std::vector<unsigned long> indices(unsigned long max, unsigned long count)
    {
        std::vector<unsigned long> indices;
        std::vector<unsigned long> allIndices;
        
        for (unsigned long i = 0; i < max; i++) allIndices.push_back(i);

        for (unsigned long i = 0; i < count; i++) {
            unsigned long index = static_cast<unsigned long>(Number::integer(0, static_cast<int>(allIndices.size())));
            indices.push_back(index);
            const auto& iter = std::find(allIndices.begin(), allIndices.end(), allIndices[index]);
            if (iter != allIndices.end())
                allIndices.erase(iter);
        }

        return indices;
    }

private:
    static std::string convertToHex(int number);

    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}
