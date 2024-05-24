#include "faker-cxx/Airline.h"

#include "AirlineData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string_view Airline::aircraftType()
{
    return Helper::arrayElement(aircraftTypes);
}

Airline::Airplane Airline::airplane()
{
    return Helper::arrayElement(airplanes);
}

Airline::AirlineInfo Airline::airline()
{
    return Helper::arrayElement(airlines);
}

Airline::Airport Airline::airport()
{
    return Helper::arrayElement(airports);
}

std::string Airline::seat(Airline::AircraftType aircraftType)
{
    return std::to_string(Number::integer(1, aircraftTypeMaxRows.at(aircraftType))) +
           Helper::arrayElement<char>(aircraftTypeSeatLetters.at(aircraftType));
}

std::string Airline::recordLocator(bool allowNumerics)
{
    if (allowNumerics)
    {
        return String::alphanumeric(6, StringCasing::Upper);
    }

    return String::alpha(6, StringCasing::Upper);
}

std::string Airline::flightNumber(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros)
    {
        return String::numeric(length, true);
    }

    return String::numeric(length, false);
}

std::string Airline::flightNumberByRange(bool addLeadingZeros, Airline::Range length)
{
    if (addLeadingZeros)
    {
        return String::numeric(Number::integer(length.min, length.max), true);
    }

    return String::numeric(Number::integer(length.min, length.max), false);
}
}
