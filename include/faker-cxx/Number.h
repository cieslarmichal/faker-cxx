#pragma once

#include <concepts>
#include <random>
#include <stdexcept>
#include <string>

namespace faker
{
template <std::integral T>
class Number
{
public:
    /**
     * @brief Generates a random integer number in the given range, bounds included.
     *
     * @param min the minimum value of the range
     * @param max the maximum value of the range
     * @return T the type of the generated number, must be an integral type
     */
    static T integer(T min, T max)
    {
        if (min > max)
        {
            throw std::invalid_argument("Minimum value must be smaller than maximum value.");
        }

        std::uniform_int_distribution<T> distribution(min, max);

        return distribution(pseudoRandomGenerator);
    }

    /**
     * @brief Generates a random integer between 0 and the given maximum value, bounds included.
     *
     * @param max the maximum value of the range
     * @return T the type of the generated number, must be an integral type
     */
    static T integer(T max)
    {
        return integer(0, max);
    }

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};

template <std::integral T>
std::random_device Number<T>::randomDevice;

template <std::integral T>
std::mt19937 Number<T>::pseudoRandomGenerator(Number<T>::randomDevice());

}
