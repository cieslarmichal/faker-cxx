#pragma once

#include <vector>

#include "./Number.h"

namespace faker
{
class Helper
{
public:
    template <class T>
    static T arrayElement(const std::vector<T>& data)
    {
        const auto index = number::Number::integer(data.size() - 1);

        return data.at(index);
    }
};
}
