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
 * location::country_name() // "Poland"
 * @endcode
 */
std::string_view country_name();

/**
 * @brief Returns a random country code.
 *
 * @returns Country code consisting two letters.
 *
 * @code
 * location::country_code() // "PL"
 * @endcode
 */
std::string_view country_code();

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
 * location::zip_code() // "47683-9880"
 * location::zip_code(Country::Poland) // "31-881"
 * @endcode
 */
std::string zip_code(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random street address for given country.
 *
 * @param country The country to generate street address from. Defaults to `Country::Usa`.
 *
 * @returns Street address including building number and street name.
 *
 * @code
 * location::street_address() // "34830 Erdman Hollow"
 * @endcode
 */
std::string street_address(AddressCountry country = AddressCountry::Usa);

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
 * location::building_number() // "505"
 * @endcode
 */
std::string building_number(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Returns a random secondary address number for given country.
 * This refers to a specific location at a given address such as an apartment or room number
 *
 * @param country The country to generate building number from. Defaults to `Country::Usa`.
 *
 * @returns Secondary address.
 *
 * @code
 * location::secondary_address() // "Apt. 861"
 * @endcode
 */
std::string secondary_address(AddressCountry country = AddressCountry::Usa);

/**
 * @brief Generates a random latitude.
 *
 * @param prec The number of decimal points of precision for the latitude. Defaults to
 * `precision::four_dp`.
 *
 * @returns Latitude within -90 to 90 range.
 *
 * @code
 * location::latitude() // "-30.9501"
 * @endcode
 */
std::string latitude(precision prec = precision::four_dp);

/**
 * @brief Generates a random longitude.
 *
 * @param prec The number of decimal points of precision for the longitude. Defaults to
 * `precision::four_dp`.
 *
 * @returns Longitude within -180 to 180 range.
 *
 * @code
 * location::longitude() // "-30.9501"
 * @endcode
 */
std::string longitude(precision prec = precision::four_dp);

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
 * location::time_zone() // "Europe/Warsaw"
 * @endcode
 */
std::string_view time_zone();
}

#endif