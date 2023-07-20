#pragma once

#include <string>

#include "types/Country.h"
#include "types/Precision.h"

namespace faker
{
class Location
{
public:
    /**
     * @brief Returns a random country name.
     *
     * @returns Country name.
     *
     * @code
     * Location::country() // "Poland"
     * @endcode
     */
    static std::string country();

    /**
     * @brief Returns a random USA state.
     *
     * @returns USA state.
     *
     * @code
     * Location::state() // "Arizona"
     * @endcode
     */
    static std::string state();

    /**
     * @brief Returns a random city for given country.
     *
     * @param country The country to generate city from. Defaults to `Country::Usa`.
     *
     * @returns City.
     *
     * @code
     * Location::city() // "Boston"
     * @endcode
     */
    static std::string city(Country country = Country::Usa);

    /**
     * @brief Returns a random zip code for given country.
     *
     * @param country The country to generate zip code from. Defaults to `Country::Usa`.
     *
     * @returns Zip code.
     *
     * @code
     * Location::zipCode() // "47683-9880"
     * Location::zipCode(Country::Poland) // "31-881"
     * @endcode
     */
    static std::string zipCode(Country country = Country::Usa);

    /**
     * @brief Returns a random street address for given country.
     *
     * @param country The country to generate street address from. Defaults to `Country::Usa`.
     *
     * @returns Street address including building number and street name.
     *
     * @code
     * Location::streetAddress() // "34830 Erdman Hollow"
     * @endcode
     */
    static std::string streetAddress(Country country = Country::Usa);

    /**
     * @brief Returns a random street for given country.
     *
     * @param country The country to generate street from. Defaults to `Country::Usa`.
     *
     * @returns Street name.
     *
     * @code
     * Location::street() // "Schroeder Isle"
     * @endcode
     */
    static std::string street(Country country = Country::Usa);

    /**
     * @brief Returns a random building number for given country.
     *
     * @param country The country to generate building number from. Defaults to `Country::Usa`.
     *
     * @returns Building number.
     *
     * @code
     * Location::buildingNumber() // "505"
     * @endcode
     */
    static std::string buildingNumber(Country country = Country::Usa);

    /**
     * @brief Generates a random latitude.
     *
     * @param precision The number of decimal points of precision for the latitude. Defaults to `4`.
     *
     * @returns Latitude within -90 to 90 range.
     *
     * @code
     * Location::latitude() // "-30.9501"
     * @endcode
     */
    static std::string latitude(Precision = Precision::FourDp);

    /**
     * @brief Generates a random longitude.
     *
     * @param precision The number of decimal points of precision for the longitude. Defaults to `4`.
     *
     * @returns Longitude within -180 to 180 range.
     *
     * @code
     * Location::longitude() // "-30.9501"
     * @endcode
     */
    static std::string longitude(Precision = Precision::FourDp);
};
}
