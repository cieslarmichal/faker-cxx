#pragma once

#include <vector>

#include "../number/NumberDataGenerator.h"

namespace faker::helpers
{
class HelperDataGenerator
{
public:
    template <class T>
    static T arrayElement(const std::vector<T>& data)
    {
        const auto index = number::NumberDataGenerator::integer(data.size() - 1);

        return data.at(index);
    }
};
}
