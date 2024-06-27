#pragma once

#include <string_view>

namespace faker::airline
{
        /**
     * @brief Get a random aircraft type
     *
     * @return a random aircraft type
     *
     * @code
     * faker::airline::aircraftType // "narrowbody"
     * @endcode
     */
    std::string_view aircraftType();

    struct Airplane
    {
        std::string_view name;
        std::string_view iataTypeCode;
    };

    /**
     * @brief Get a random airplane
     *
     * @return a random airplane and its iataTypeCode
     *
     * @code
     * faker::airline::airplane() // {"Boeing 737-800", "738"}
     * @endcode
     */
     Airplane airplane();

    struct AirlineInfo
    {
        std::string_view name;
        std::string_view iataCode;
    };

    /**
     * @brief Get a random airline
     *
     * @return a random airline and its iataCode
     *
     * @code
     * faker::airline::airline() // {"Air Canada", "AC"}
     * @endcode
     */
     AirlineInfo airline();

    struct Airport
    {
        std::string_view name;
        std::string_view iataCode;
    };

    /**
     * @brief Get a random airport
     *
     * @return a random airport and its iataCode
     *
     * @code
     * faker::airline::airport() // {"Toronto Pearson International Airport", "YYZ"}
     * @endcode
     */
     Airport airport();

    enum class AircraftType
    {
        Regional,
        Narrowbody,
        Widebody,
    };

    /**
     * @brief Get a random seat by aircraft type
     *
     * @param aircraftType the aircraft type
     *
     * @return a random seat
     *
     * @code
     * faker::airline::seat(AircraftType::Narrowbody) // "1A"
     * @endcode
     */
     std::string seat(AircraftType aircraftType);

    /**
     * @brief Get a random record location
     *
     * @return a random record location
     *
     * @code
     * faker::airline::recordLocator() // "ABCDEF"
     * faker::airline::recordLocator(true) // "ABC123"
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
     * faker::airline::flightNumber() // "1234"
     * faker::airline::flightNumber(true) // "0123"
     * faker::airline::flightNumber(false, 3) // "234"
     * @endcode
     */
     std::string flightNumber(bool addLeadingZeros = false, unsigned int length = 4);

    struct Range
    {
        unsigned int min;
        unsigned int max;
    };

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
     * faker::airline::flightNumber() // "1234"
     * faker::airline::flightNumber(true) // "0123"
     * faker::airline::flightNumber(false, {1, 4}) // "234" // "12" // "1234"
     * @endcode
     */
     std::string flightNumberByRange(bool addLeadingZeros = false, Range length = {1, 4});
    }
