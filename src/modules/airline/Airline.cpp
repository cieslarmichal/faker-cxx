#include "faker-cxx/Airline.h"

#include <string>
#include <string_view>

#include "AirlineData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker::airline
{
std::string_view aircraftType()
{
    return Helper::arrayElement(aircraftTypes);
}

Airplane airplane()
{
    return Helper::arrayElement(airplanes);
}

AirlineInfo airline()
{
    return Helper::arrayElement(airlines);
}

Airport airport()
{
    return Helper::arrayElement(airports);
}

std::string seat(AircraftType aircraftType)
{
    return std::to_string(number::integer(1, aircraftTypeMaxRows.at(aircraftType))) +
           Helper::arrayElement<char>(aircraftTypeSeatLetters.at(aircraftType));
}

std::string recordLocator(bool allowNumerics)
{
    if (allowNumerics)
    {
        return String::alphanumeric(6, StringCasing::Upper);
    }

    return String::alpha(6, StringCasing::Upper);
}

std::string flightNumber(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros)
    {
        return String::numeric(length, true);
    }

    return String::numeric(length, false);
}

std::string flightNumberByRange(bool addLeadingZeros, Range length)
{
    if (addLeadingZeros)
    {
        return String::numeric(number::integer(length.min, length.max), true);
    }

    return String::numeric(number::integer(length.min, length.max), false);
}
}
