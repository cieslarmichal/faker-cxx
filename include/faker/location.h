#ifndef FAKER_LOCATION_H
#define FAKER_LOCATION_H

#include <faker/types/precision.h>
#include <string>

namespace faker::location {
// TODO: remove when address_country enum values will be same as Country values
enum class address_country {
    usa,
    poland,
    france,
    russia,
    ukraine,
    italy,
    germany,
    czechia,
    australia,
    india,
    denmark,
    spain,
    brazil,
    finland,
    estonia
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
 * @param country The country to generate state from. Defaults to `country_t::usa`.
 *
 * @returns State.
 *
 * @code
 * location::state() // "Arizona"
 * @endcode
 */
std::string_view state(address_country country = address_country::usa);

/**
 * @brief Returns a random county for a given country.
 *
 * @param country The country to generate county from. Defaults to `country_t::usa`.
 *
 * @returns County.
 *
 * @code
 * location::county() // "Adams County"
 * @endcode
 */
std::string_view county(address_country country = address_country::usa);

/**
 * @brief Returns a random city for given country.
 *
 * @param country The country to generate city from. Defaults to `country_t::usa`.
 *
 * @returns City.
 *
 * @code
 * location::city() // "Boston"
 * @endcode
 */
std::string city(address_country country = address_country::usa);

/**
 * @brief Returns a random zip code for given country.
 *
 * @param country The country to generate zip code from. Defaults to `country_t::usa`.
 *
 * @returns Zip code.
 *
 * @code
 * location::zip_code() // "47683-9880"
 * location::zip_code(country_t::poland) // "31-881"
 * @endcode
 */
std::string zip_code(address_country country = address_country::usa);

/**
 * @brief Returns a random street address for given country.
 *
 * @param country The country to generate street address from. Defaults to `country_t::usa`.
 *
 * @returns Street address including building number and street name.
 *
 * @code
 * location::street_address() // "34830 Erdman Hollow"
 * @endcode
 */
std::string street_address(address_country country = address_country::usa);

/**
 * @brief Returns a random street for given country.
 *
 * @param country The country to generate street from. Defaults to `country_t::usa`.
 *
 * @returns Street name.
 *
 * @code
 * location::street() // "Schroeder Isle"
 * @endcode
 */
std::string street(address_country country = address_country::usa);

/**
 * @brief Returns a random building number for given country.
 *
 * @param country The country to generate building number from. Defaults to `country_t::usa`.
 *
 * @returns Building number.
 *
 * @code
 * location::building_number() // "505"
 * @endcode
 */
std::string building_number(address_country country = address_country::usa);

/**
 * @brief Returns a random secondary address number for given country.
 * This refers to a specific location at a given address such as an apartment or room number
 *
 * @param country The country to generate building number from. Defaults to `country_t::Usa`.
 *
 * @returns Secondary address.
 *
 * @code
 * location::secondary_address() // "Apt. 861"
 * @endcode
 */
std::string secondary_address(address_country country = address_country::usa);

/**
 * @brief Generates a random latitude.
 *
 * @param prec The number of decimal points of precision for the latitude. Defaults to
 * `precision_t::four_dp`.
 *
 * @returns Latitude within -90 to 90 range.
 *
 * @code
 * location::latitude() // "-30.9501"
 * @endcode
 */
std::string latitude(precision_t prec = precision_t::four_dp);

/**
 * @brief Generates a random longitude.
 *
 * @param prec The number of decimal points of precision for the longitude. Defaults to
 * `precision_t::four_dp`.
 *
 * @returns Longitude within -180 to 180 range.
 *
 * @code
 * location::longitude() // "-30.9501"
 * @endcode
 */
std::string longitude(precision_t prec = precision_t::four_dp);

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