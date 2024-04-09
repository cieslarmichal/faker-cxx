#pragma once

#include <string>

#include "types/Precision.h"

namespace faker
{
enum class AddressCountry
{
    Usa,
    Poland,
    France,
    Russia,
    Ukraine,
    Italy,
    Germany,
    Czech,
    Australia,
    India,
    Denmark,
    Spain,
    Brazil,
    Finland,
    Estonia,
    Romania,
    Latvia,
    Nepal
};

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
     * @brief Returns a random country code.
     *
     * @returns Country code consisting two letters.
     *
     * @code
     * Location::countryCode() // "PL"
     * @endcode
     */
    static std::string countryCode();

    /**
     * @brief Returns a random state for a given country.
     *
     * @param country The country to generate state from. Defaults to `Country::Usa`.
     *
     * @returns State.
     *
     * @code
     * Location::state() // "Arizona"
     * @endcode
     */
    static std::string state(AddressCountry country = AddressCountry::Usa);

    /**
     * @brief Returns a random county for a given country.
     *
     * @param country The country to generate county from. Defaults to `Country::Usa`.
     *
     * @returns County.
     *
     * @code
     * Location::county() // "Adams County"
     * @endcode
     */
    static std::string county(AddressCountry country = AddressCountry::Usa);

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
    static std::string city(AddressCountry country = AddressCountry::Usa);

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
    static std::string zipCode(AddressCountry country = AddressCountry::Usa);

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
    static std::string streetAddress(AddressCountry country = AddressCountry::Usa);

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
    static std::string street(AddressCountry country = AddressCountry::Usa);

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
    static std::string buildingNumber(AddressCountry country = AddressCountry::Usa);

    /**
     * @brief Returns a random secondary address number for given country.
     * This refers to a specific location at a given address such as an apartment or room number
     *
     * @param country The country to generate building number from. Defaults to `Country::Usa`.
     *
     * @returns Secondary address.
     *
     * @code
     * Location::secondaryAddress() // "Apt. 861"
     * @endcode
     */
    static std::string secondaryAddress(AddressCountry country = AddressCountry::Usa);

    /**
     * @brief Generates a random latitude.
     *
     * @param precision The number of decimal points of precision for the latitude. Defaults to `Precision::FourDp`.
     *
     * @returns Latitude within -90 to 90 range.
     *
     * @code
     * Location::latitude() // "-30.9501"
     * @endcode
     */
    static std::string latitude(Precision precision = Precision::FourDp);

    /**
     * @brief Generates a random longitude.
     *
     * @param precision The number of decimal points of precision for the longitude. Defaults to `Precision::FourDp`.
     *
     * @returns Longitude within -180 to 180 range.
     *
     * @code
     * Location::longitude() // "-30.9501"
     * @endcode
     */
    static std::string longitude(Precision precision = Precision::FourDp);

    /**
     * @brief Generates a random direction from cardinal and ordinal directions.
     *
     * @returns Direction.
     *
     * @code
     * Location::direction() // "North"
     * @endcode
     */
    static std::string direction();

    /**
     * @brief Generates a random time zone.
     *
     * @returns Time zone.
     *
     * @code
     * Location::timeZone() // "Europe/Warsaw"
     * @endcode
     */
    static std::string timeZone();
};
}
