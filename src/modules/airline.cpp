#include "../common/helper.h"
#include "airline_data.h"
#include <faker/airline.h>
#include <faker/number.h>
#include <faker/string.h>
#include <string>

namespace faker::airline {
std::string_view aircraft_type() { return Helper::arrayElement(data::aircraftTypes); }

Airplane airplane() { return Helper::arrayElement(data::airplanes); }

AirlineStruct airline() { return Helper::arrayElement(data::airlines); }

Airport airport() { return Helper::arrayElement(data::airports); }

std::string seat(AircraftType aircraftType)
{
    return std::to_string(number::integer(1, data::aircraftTypeMaxRows.at(aircraftType)))
        + Helper::arrayElement(data::aircraftTypeSeatLetters.at(aircraftType));
}

std::string record_locator(bool allowNumerics)
{
    if (allowNumerics) {
        return string::alphanumeric(6, string::StringCasing::Upper);
    }

    return string::alpha(6, string::StringCasing::Upper);
}

std::string flight_number(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros) {
        return string::numeric(length, true);
    }

    return string::numeric(length, false);
}

std::string flight_number_by_range(bool addLeadingZeros, Range length)
{
    if (addLeadingZeros) {
        return string::numeric(number::integer(length.min, length.max), true);
    }

    return string::numeric(number::integer(length.min, length.max), false);
}
}
