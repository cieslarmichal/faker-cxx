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
    return helper::arrayElement(aircraftTypes);
}

Airplane airplane()
{
    return helper::arrayElement(airplanes);
}

AirlineInfo airline()
{
    return helper::arrayElement(airlines);
}

Airport airport()
{
    return helper::arrayElement(airports);
}

std::string seat(AircraftType aircraftType)
{
    return std::to_string(number::integer(1, aircraftTypeMaxRows.at(aircraftType))) +
           helper::arrayElement<char>(aircraftTypeSeatLetters.at(aircraftType));
}

std::string recordLocator(bool allowNumerics)
{
    if (allowNumerics)
    {
        return string::alphanumeric(6, string::StringCasing::Upper);
    }

    return string::alpha(6, string::StringCasing::Upper);
}

std::string flightNumber(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros)
    {
        return string::numeric(length, true);
    }

    return string::numeric(length, false);
}

std::string flightNumberByRange(bool addLeadingZeros, Range length)
{
    if (addLeadingZeros)
    {
        return string::numeric(number::integer(length.min, length.max), true);
    }

    return string::numeric(number::integer(length.min, length.max), false);
}
}
