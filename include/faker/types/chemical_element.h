#ifndef FAKER_TYPES_CHEMICAL_ELEMENT_H
#define FAKER_TYPES_CHEMICAL_ELEMENT_H

#include <string_view>

namespace faker {
struct ChemicalElement {
    std::string_view name;
    std::string_view symbol;
    int atomicNumber;
};

inline bool operator==(const ChemicalElement& lhs, const ChemicalElement& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol && lhs.atomicNumber == rhs.atomicNumber;
}
}

#endif