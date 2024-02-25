#ifndef FAKER_TYPES_CURRENCY_H
#define FAKER_TYPES_CURRENCY_H

#include <string_view>

namespace faker {
struct Currency {
    std::string_view name;
    std::string_view code;
    std::string_view symbol;
};

inline bool operator==(const Currency& lhs, const Currency& rhs)
{
    return lhs.name == rhs.name && lhs.code == rhs.code && lhs.symbol == rhs.symbol;
}
}

#endif