#ifndef FAKER_AIRLINE_H
#define FAKER_AIRLINE_H

#include <string>

namespace faker::airline {
enum class AircraftType {
    Regional,
    Narrowbody,
    Widebody,
};

struct Airplane {
    std::string_view name;
    std::string_view iataTypeCode;
};

inline bool operator==(const Airplane& lhs, const Airplane& rhs)
{
    return lhs.name == rhs.name && lhs.iataTypeCode == rhs.iataTypeCode;
}

inline bool operator!=(const Airplane& lhs, const Airplane& rhs) { return !(lhs == rhs); }

struct Airport {
    std::string_view name;
    std::string_view iataCode;
};

inline bool operator==(const Airport& lhs, const Airport& rhs)
{
    return lhs.name == rhs.name && lhs.iataCode == rhs.iataCode;
}

inline bool operator!=(const Airport& lhs, const Airport& rhs) { return !(lhs == rhs); }

struct Range {
    unsigned int min;
    unsigned int max;
};

inline bool operator==(const Range& lhs, const Range& rhs)
{
    return lhs.min == rhs.min && lhs.max == rhs.max;
}

inline bool operator!=(const Range& lhs, const Range& rhs) { return !(lhs == rhs); }

struct AirlineStruct {
    std::string_view name;
    std::string_view iataCode;
};

inline bool operator==(const AirlineStruct& lhs, const AirlineStruct& rhs)
{
    return lhs.name == rhs.name && lhs.iataCode == rhs.iataCode;
}

inline bool operator!=(const AirlineStruct& lhs, const AirlineStruct& rhs) { return !(lhs == rhs); }

/**
 * @brief Get a random aircraft type
 *
 * @return a random aircraft type
 *
 * @code
 * airline::aircraftType // "narrowbody"
 * @endcode
 */
std::string_view aircraftType();

/**
 * @brief Get a random airplane
 *
 * @return a random airplane and its iataTypeCode
 *
 * @code
 * airline::airplane() // {"Boeing 737-800", "738"}
 * @endcode
 */
Airplane airplane();

/**
 * @brief Get a random airline
 *
 * @return a random airline and its iataCode
 *
 * @code
 * airline::airline() // {"Air Canada", "AC"}
 * @endcode
 */
AirlineStruct airline();

/**
 * @brief Get a random airport
 *
 * @return a random airport and its iataCode
 *
 * @code
 * airline::airport() // {"Toronto Pearson International Airport", "YYZ"}
 * @endcode
 */
Airport airport();

/**
 * @brief Get a random seat by aircraft type
 *
 * @param aircraftType the aircraft type
 *
 * @return a random seat
 *
 * @code
 * airline::seat(AircraftType::Narrowbody) // "1A"
 * @endcode
 */
std::string seat(AircraftType aircraftType);

/**
 * @brief Get a random record location
 *
 * @return a random record location
 *
 * @code
 * airline::recordLocator() // "ABCDEF"
 * airline::recordLocator(true) // "ABC123"
 * @endcode
 */
std::string recordLocator(bool allowNumerics = false);

/**
 * @brief Get a random flight number from given length
 *
 * @param addLeadingZeros whether to add leading zeros
 *
 * @param length the length of the flight number
 *
 * @return a random flight number
 *
 * @code
 * airline::flightNumber() // "1234"
 * airline::flightNumber(true) // "0123"
 * airline::flightNumber(false, 3) // "234"
 * @endcode
 */
std::string flightNumber(bool addLeadingZeros = false, unsigned int length = 4);

/**
 * @brief Get a random flight number from given length
 *
 * @param addLeadingZeros whether to add leading zeros
 *
 * @param length the length of the flight number
 *
 * @return a random flight number
 *
 * @code
 * airline::flightNumber() // "1234"
 * airline::flightNumber(true) // "0123"
 * airline::flightNumber(false, {1, 4}) // "234" // "12" // "1234"
 * @endcode
 */
std::string flightNumberByRange(bool addLeadingZeros = false, Range length = { 1, 4 });
}

#endif