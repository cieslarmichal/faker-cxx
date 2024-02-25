#pragma once

#include <string_view>

namespace faker {
enum class AircraftType {
    Regional,
    Narrowbody,
    Widebody,
};

struct Airplane {
    std::string_view name;
    std::string_view iataTypeCode;
};

inline bool operator==(const Airplane& lhs, const Airplane& rhs)
{
    return lhs.name == rhs.name && lhs.iataTypeCode == rhs.iataTypeCode;
}

inline bool operator!=(const Airplane& lhs, const Airplane& rhs) { return !(lhs == rhs); }

struct Airport {
    std::string_view name;
    std::string_view iataCode;
};

inline bool operator==(const Airport& lhs, const Airport& rhs)
{
    return lhs.name == rhs.name && lhs.iataCode == rhs.iataCode;
}

inline bool operator!=(const Airport& lhs, const Airport& rhs) { return !(lhs == rhs); }

struct Range {
    unsigned int min;
    unsigned int max;
};

inline bool operator==(const Range& lhs, const Range& rhs)
{
    return lhs.min == rhs.min && lhs.max == rhs.max;
}

inline bool operator!=(const Range& lhs, const Range& rhs) { return !(lhs == rhs); }

struct AirlineStruct {
    std::string_view name;
    std::string_view iataCode;
};

inline bool operator==(const AirlineStruct& lhs, const AirlineStruct& rhs)
{
    return lhs.name == rhs.name && lhs.iataCode == rhs.iataCode;
}

inline bool operator!=(const AirlineStruct& lhs, const AirlineStruct& rhs) { return !(lhs == rhs); }

}
