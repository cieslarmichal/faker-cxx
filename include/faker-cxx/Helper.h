#pragma once

#include <chrono>
#include <span>
#include <string_view>
#include <vector>

#include "Number.h"

namespace faker
{
class Helper
{
public:
    /**
     * @brief Get a random element from an STL container.
     *
     * @tparam T an element type of the container.
     *
     * @param data The container.
     *
     * @return T a random element from the container.
     *
     * @code
     * Helper::arrayElement<char>(std::string{"abcd"}) // "b"
     * Helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
     * @endcode
     */
    template <class T>
    static T arrayElement(std::span<const T> data)
    {
        const auto index = Number::integer<size_t>(data.size() - 1);

        return data[index];
    }

    /**
     * @brief Returns shuffled STL container.
     *
     * @tparam T an element type of the container.
     *
     * @param data The container.
     *
     * @return Container with shuffled elements.
     *
     * @code
     * Helper::arrayElement<char>(std::string{"abcd"}) // "dcba"
     * @endcode
     */
    template <class T>
    static std::vector<T> shuffle(std::vector<T> data)
    {
        std::shuffle(std::begin(data), std::end(data), pseudoRandomGenerator);

        return data;
    }

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}
