#ifndef FAKER_AIRLINE_H
#define FAKER_AIRLINE_H

#include <faker/types/airline_types.h>
#include <string>

namespace faker::airline {
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