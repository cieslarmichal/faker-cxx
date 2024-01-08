#pragma once

#include <string>

namespace faker
{
struct Unit
{
    std::string name;
    std::string symbol;
    std::string usedToMeasure;
};

inline bool operator==(const Unit& lhs, const Unit& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol && lhs.usedToMeasure == rhs.usedToMeasure;
}
}
