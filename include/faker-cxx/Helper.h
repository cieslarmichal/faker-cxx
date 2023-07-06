#pragma once

#include <vector>
#include <string_view>
#include <span>
#include "Number.h"

namespace faker
{
class Helper
{
public:
    /**
     * @brief Get a random element from an STL container
     * 
     * @tparam T an element type of the container
     * @param data a container
     * @return T a random element from the container
     */
    template <class T>
    static T arrayElement(std::span<const T> data)
    {
        const auto index = Number::integer<size_t>(data.size() - 1);

        return data[index];
    }
};
}
