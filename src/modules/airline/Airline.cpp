#include "faker-cxx/Airline.h"

#include <string>
#include <string_view>

#include "AirlineData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string_view airline::aircraftType()
{
    return Helper::arrayElement(aircraftTypes);
}

airline::Airplane airline::airplane()
{
    return Helper::arrayElement(airplanes);
}

airline::AirlineInfo airline::airline()
{
    return Helper::arrayElement(airlines);
}

airline::Airport airline::airport()
{
    return Helper::arrayElement(airports);
}

std::string airline::seat(airline::AircraftType aircraftType)
{
    return std::to_string(Number::integer(1, aircraftTypeMaxRows.at(aircraftType))) +
           Helper::arrayElement<char>(aircraftTypeSeatLetters.at(aircraftType));
}

std::string airline::recordLocator(bool allowNumerics)
{
    if (allowNumerics)
    {
        return String::alphanumeric(6, StringCasing::Upper);
    }

    return String::alpha(6, StringCasing::Upper);
}

std::string airline::flightNumber(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros)
    {
        return String::numeric(length, true);
    }

    return String::numeric(length, false);
}

std::string airline::flightNumberByRange(bool addLeadingZeros, airline::Range length)
{
    if (addLeadingZeros)
    {
        return String::numeric(Number::integer(length.min, length.max), true);
    }

    return String::numeric(Number::integer(length.min, length.max), false);
}
}
