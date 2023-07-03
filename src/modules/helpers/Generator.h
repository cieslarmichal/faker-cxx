#pragma once

#include <vector>

#include "../number/Generator.h"

namespace faker::helpers
{
template <class T>
static T arrayElement(const std::vector<T>& data)
{
    const auto index = number::integer(data.size() - 1);

    return data.at(index);
}
}
