#ifndef FAKER_TYPES_UNIT_H
#define FAKER_TYPES_UNIT_H

#include <string_view>

namespace faker {
struct Unit {
    std::string_view name;
    std::string_view symbol;
    std::string_view usedToMeasure;
};

inline bool operator==(const Unit& lhs, const Unit& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol
        && lhs.usedToMeasure == rhs.usedToMeasure;
}

inline bool operator!=(const Unit& lhs, const Unit& rhs) { return !(lhs == rhs); }

}

#endif