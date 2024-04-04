#pragma once

#include <string>

#include "../Airline.h"

namespace faker
{
enum class AircraftType
{
    Regional,
    Narrowbody,
    Widebody,
};

struct Airplane
{
    std::string name;
    std::string iataTypeCode;
};

struct Airport
{
    std::string name;
    std::string iataCode;
};

struct Range
{
    unsigned int min;
    unsigned int max;
};

struct AirlineStruct
{
    std::string name;
    std::string iataCode;
};
}
