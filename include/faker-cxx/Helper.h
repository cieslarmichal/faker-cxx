#pragma once

#include <vector>

#include "Number.h"

namespace faker
{
class Helper
{
public:
    template <class T>
    static T arrayElement(const std::vector<T>& data)
    {
        const auto index = Number::integer<size_t>(data.size() - 1);

        return data.at(index);
    }

    static char arrayElement(const std::string& data)
    {
        const auto index = Number::integer<size_t>(static_cast<int>(data.size()) - 1);

        return data.at(index);
    }
};
}
