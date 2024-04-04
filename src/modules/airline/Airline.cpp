#include "faker-cxx/Airline.h"

#include "data/AircraftTypes.h"
#include "data/Airlines.h"
#include "data/Airplanes.h"
#include "data/Airports.h"
#include "data/Seat.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string Airline::aircraftType()
{
    return Helper::arrayElement<std::string>(aircraftTypes);
}

faker::Airplane Airline::airplane()
{
    return Helper::arrayElement<faker::Airplane>(airplanes);
}

faker::AirlineStruct Airline::airline()
{
    return Helper::arrayElement<faker::AirlineStruct>(airlines);
}

faker::Airport Airline::airport()
{
    return Helper::arrayElement<faker::Airport>(airports);
}

std::string Airline::seat(faker::AircraftType aircraftType)
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

std::string Airline::flightNumberByRange(bool addLeadingZeros, faker::Range length)
{
    if (addLeadingZeros)
    {
        return String::numeric(Number::integer(length.min, length.max), true);
    }

    return String::numeric(Number::integer(length.min, length.max), false);
}
}
