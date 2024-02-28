#ifndef FAKER_AIRLINE_H
#define FAKER_AIRLINE_H

#include <string>

namespace faker::airline {
/**
 * @brief Enumeration representing different types of aircraft.
 */
enum class aircraft_type {
    regional,
    narrow_body,
    wide_body,
};

/**
 * @brief Contains basic information about an airplane.
 */
struct airplane_info {
    std::string_view name;
    std::string_view iata_type_code;
};

inline bool operator==(const airplane_info& lhs, const airplane_info& rhs)
{
    return lhs.name == rhs.name && lhs.iata_type_code == rhs.iata_type_code;
}

inline bool operator!=(const airplane_info& lhs, const airplane_info& rhs) { return !(lhs == rhs); }

/**
 * @brief Contains basic information about an airport.
 */
struct airport_info {
    std::string_view name;
    std::string_view iata_code;
};

inline bool operator==(const airport_info& lhs, const airport_info& rhs)
{
    return lhs.name == rhs.name && lhs.iata_code == rhs.iata_code;
}

inline bool operator!=(const airport_info& lhs, const airport_info& rhs) { return !(lhs == rhs); }

/**
 * @brief Contains basic information about an airline.
 */
struct airline_info {
    std::string_view name;
    std::string_view iata_code;
};

inline bool operator==(const airline_info& lhs, const airline_info& rhs)
{
    return lhs.name == rhs.name && lhs.iata_code == rhs.iata_code;
}

inline bool operator!=(const airline_info& lhs, const airline_info& rhs) { return !(lhs == rhs); }

/**
 * @brief Get a random aircraft type
 *
 * @return a random aircraft type
 *
 * @code
 * airline::aircraft_type_name // "narrowbody"
 * @endcode
 */
std::string_view aircraft_type_name();

/**
 * @brief Get a random airplane
 *
 * @return a random airplane and its iataTypeCode
 *
 * @code
 * airline::airplane() // {"Boeing 737-800", "738"}
 * @endcode
 */
airplane_info airplane();

/**
 * @brief Get a random airline
 *
 * @return a random airline and its iataCode
 *
 * @code
 * airline::airline() // {"Air Canada", "AC"}
 * @endcode
 */
airline_info airline();

/**
 * @brief Get a random airport
 *
 * @return a random airport and its iataCode
 *
 * @code
 * airline::airport() // {"Toronto Pearson International Airport", "YYZ"}
 * @endcode
 */
airport_info airport();

/**
 * @brief Get a random seat by aircraft type
 *
 * @param type the aircraft type
 *
 * @return a random seat
 *
 * @code
 * airline::seat(aircraft_type::narrow_body) // "1A"
 * @endcode
 */
std::string seat(aircraft_type type);

/**
 * @brief Get a random record location
 *
 * @return a random record location
 *
 * @code
 * airline::record_locator() // "ABCDEF"
 * airline::record_locator(true) // "ABC123"
 * @endcode
 */
std::string record_locator(bool allow_numbers = false);

/**
 * @brief Get a random flight number from given length
 *
 * @param add_leading_zeros whether to add leading zeros
 *
 * @param length the length of the flight number
 *
 * @return a random flight number
 *
 * @code
 * airline::flight_number() // "1234"
 * airline::flight_number(true) // "0123"
 * airline::flight_number(false, 3) // "234"
 * @endcode
 */
std::string flight_number(bool add_leading_zeros = false, unsigned length = 4);

/**
 * @brief Get a random flight number from given length
 *
 * @param add_leading_zeros whether to add leading zeros
 *
 * @param min_length the minimal length of the flight number
 * @param max_length the maximal length of the flight number
 *
 * @return a random flight number
 *
 * @code
 * airline::flight_number() // "1234"
 * airline::flight_number(true) // "0123"
 * airline::flight_number(false, 1, 4) // "234" // "12" // "1234"
 * @endcode
 */
std::string flight_number_by_range(
    bool add_leading_zeros = false, unsigned min_length = 1, unsigned max_length = 4);
}

#endif