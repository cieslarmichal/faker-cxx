#include "../common/random.h"
#include "airline_data.h"
#include <faker/airline.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::airline {
std::string_view aircraft_type_name() { return random::element(data::aircraft_types); }

airplane_info airplane() { return random::element(data::airplanes); }

airline_info airline() { return random::element(data::airlines); }

airport_info airport() { return random::element(data::airports); }

std::string seat(aircraft_type type)
{
    return std::to_string(number::integer(1, data::aircraft_type_max_rows.at(type)))
        + random::element(data::aircraft_type_seat_letters.at(type));
}

std::string record_locator(bool allow_numbers)
{
    if (allow_numbers) {
        return string::alphanumeric(6, string::string_case::upper);
    }

    return string::alpha(6, string::string_case::upper);
}

std::string flight_number(bool add_leading_zeros, unsigned length)
{
    return string::numeric(length, add_leading_zeros);
}

std::string flight_number_by_range(bool add_leading_zeros, unsigned min_length, unsigned max_length)
{
    return string::numeric(number::integer(min_length, max_length), add_leading_zeros);
}
}
