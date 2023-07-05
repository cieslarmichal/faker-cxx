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
        const auto index = Number<size_t>::integer(data.size() - 1);

        return data.at(index);
    }

    static char arrayElement(const std::string& data)
    {
        const std::integral auto index = Number<size_t>::integer(data.size() - 1);

        return data.at(index);
    }
};
}
