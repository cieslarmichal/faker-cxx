#pragma once

#include <string>

namespace faker
{
struct ChemicalElement
{
    std::string name;
    std::string symbol;
    int atomicNumber;
};

inline bool operator==(const ChemicalElement& lhs, const ChemicalElement& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol && lhs.atomicNumber == rhs.atomicNumber;
}
}
