#pragma once

#include <string>

namespace faker
{
struct Currency
{
    std::string name;
    std::string code;
    std::string symbol;
};

inline bool operator==(const Currency& lhs, const Currency& rhs)
{
    return lhs.name == rhs.name && lhs.code == rhs.code && lhs.symbol == rhs.symbol;
}
}
