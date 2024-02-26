#ifndef FAKER_LOCATION_H
#define FAKER_LOCATION_H

#include <faker/types/precision.h>
#include <string>

namespace faker::location {
// TODO: remove when AddressCountry enum values will be same as Country values
enum class AddressCountry {
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
    Estonia
};

/**
 * @brief Returns a random country name.
 *
 * @returns Country name.
 *
 * @code
 * location::country() // "Poland"
 * @endcode
 */
std::string_view country();

/**
 * @brief Returns a random country code.
 *
 * @returns Country code consisting two letters.
 *
 * @code
 * location::countryCode() // "PL"
 * @endcode
 */
std::string_view countryCode();

/**
 * @brief Returns a random state for a given country.
 *
 * @param country The country to generate state from. Defaults to `Country::Usa`.
 *
 * @returns State.
 *
 * @code
 * location::state() // "Arizona"
 * @endcode
 */
std::string_view state(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random county for a given country.
 *
 * @param country The country to generate county from. Defaults to `Country::Usa`.
 *
 * @returns County.
 *
 * @code
 * location::county() // "Adams County"
 * @endcode
 */
std::string_view county(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random city for given country.
 *
 * @param country The country to generate city from. Defaults to `Country::Usa`.
 *
 * @returns City.
 *
 * @code
 * location::city() // "Boston"
 * @endcode
 */
std::string city(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random zip code for given country.
 *
 * @param country The country to generate zip code from. Defaults to `Country::Usa`.
 *
 * @returns Zip code.
 *
 * @code
 * location::zipCode() // "47683-9880"
 * location::zipCode(Country::Poland) // "31-881"
 * @endcode
 */
std::string zipCode(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random street address for given country.
 *
 * @param country The country to generate street address from. Defaults to `Country::Usa`.
 *
 * @returns Street address including building number and street name.
 *
 * @code
 * location::streetAddress() // "34830 Erdman Hollow"
 * @endcode
 */
std::string streetAddress(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random street for given country.
 *
 * @param country The country to generate street from. Defaults to `Country::Usa`.
 *
 * @returns Street name.
 *
 * @code
 * location::street() // "Schroeder Isle"
 * @endcode
 */
std::string street(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random building number for given country.
 *
 * @param country The country to generate building number from. Defaults to `Country::Usa`.
 *
 * @returns Building number.
 *
 * @code
 * location::buildingNumber() // "505"
 * @endcode
 */
std::string buildingNumber(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random secondary address number for given country.
 * This refers to a specific location at a given address such as an apartment or room number
 *
 * @param country The country to generate building number from. Defaults to `Country::Usa`.
 *
 * @returns Secondary address.
 *
 * @code
 * location::secondaryAddress() // "Apt. 861"
 * @endcode
 */
std::string secondaryAddress(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Generates a random latitude.
 *
 * @param precision The number of decimal points of precision for the latitude. Defaults to
 * `Precision::FourDp`.
 *
 * @returns Latitude within -90 to 90 range.
 *
 * @code
 * location::latitude() // "-30.9501"
 * @endcode
 */
std::string latitude(Precision precision = Precision::FourDp);

/**
 * @brief Generates a random longitude.
 *
 * @param precision The number of decimal points of precision for the longitude. Defaults to
 * `Precision::FourDp`.
 *
 * @returns Longitude within -180 to 180 range.
 *
 * @code
 * location::longitude() // "-30.9501"
 * @endcode
 */
std::string longitude(Precision precision = Precision::FourDp);

/**
 * @brief Generates a random direction from cardinal and ordinal directions.
 *
 * @returns Direction.
 *
 * @code
 * location::direction() // "North"
 * @endcode
 */
std::string_view direction();

/**
 * @brief Generates a random time zone.
 *
 * @returns Time zone.
 *
 * @code
 * location::timeZone() // "Europe/Warsaw"
 * @endcode
 */
std::string_view timeZone();
}

#endif