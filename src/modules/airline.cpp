#include "faker-cxx/airline.h"

#include <string>
#include <string_view>

#include "airline_data.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/string.h"

namespace faker::airline
{
std::string_view aircraftType()
{
    return helper::randomElement(aircraftTypes);
}

Airplane airplane()
{
    return helper::randomElement(airplanes);
}

AirlineInfo airline()
{
    return helper::randomElement(airlines);
}

Airport airport()
{
    return helper::randomElement(airports);
}

std::string seat(AircraftType aircraftType)
{
    return std::to_string(number::integer(1, aircraftTypeMaxRows.at(aircraftType))) +
           helper::randomElement<char>(aircraftTypeSeatLetters.at(aircraftType));
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
