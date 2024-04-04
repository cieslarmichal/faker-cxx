#pragma once

#include <string>

#include "./types/AirlineTypes.h"

namespace faker
{
class Airline
{
public:
    /**
     * @brief Get a random aircraft type
     *
     * @return a random aircraft type
     *
     * @code
     * Airline::aircraftType // "narrowbody"
     * @endcode
     */
    static std::string aircraftType();

    /**
     * @brief Get a random airplane
     *
     * @return a random airplane and its iataTypeCode
     *
     * @code
     * Airline::airplane() // {"Boeing 737-800", "738"}
     * @endcode
     */
    static Airplane airplane();

    /**
     * @brief Get a random airline
     *
     * @return a random airline and its iataCode
     *
     * @code
     * Airline::airline() // {"Air Canada", "AC"}
     * @endcode
     */
    static AirlineStruct airline();

    /**
     * @brief Get a random airport
     *
     * @return a random airport and its iataCode
     *
     * @code
     * Airline::airport() // {"Toronto Pearson International Airport", "YYZ"}
     * @endcode
     */
    static Airport airport();

    /**
     * @brief Get a random seat by aircraft type
     *
     * @param aircraftType the aircraft type
     *
     * @return a random seat
     *
     * @code
     * Airline::seat(AircraftType::Narrowbody) // "1A"
     * @endcode
     */
    static std::string seat(AircraftType aircraftType);

    /**
     * @brief Get a random record location
     *
     * @return a random record location
     *
     * @code
     * Airline::recordLocator() // "ABCDEF"
     * Airline::recordLocator(true) // "ABC123"
     * @endcode
     */
    static std::string recordLocator(bool allowNumerics = false);

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
     * Airline::flightNumber() // "1234"
     * Airline::flightNumber(true) // "0123"
     * Airline::flightNumber(false, 3) // "234"
     * @endcode
     */
    static std::string flightNumber(bool addLeadingZeros = false, unsigned int length = 4);

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
     * Airline::flightNumber() // "1234"
     * Airline::flightNumber(true) // "0123"
     * Airline::flightNumber(false, {1, 4}) // "234" // "12" // "1234"
     * @endcode
     */
    static std::string flightNumberByRange(bool addLeadingZeros = false, Range length = {1, 4});
};
}
