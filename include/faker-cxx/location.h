#pragma once

#include <limits>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/types/precision.h"

namespace faker::location
{
/**
 * @brief Returns a random country name.
 *
 * @returns Country name.
 *
 * @code
 * faker::location::country() // "Poland"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view country();

/**
 * @brief Returns the continent for a given country or a random continent if no country is specified.
 *
 * @param country The country name. Defaults to an empty string, which means a random continent is selected.
 *
 * @returns Continent name or "Unknown" if the country is not mapped.
 *
 * @code
 * faker::location::continent("Poland") // Europe
 * faker::location::continent() 
// Africa
// Asia
// Europe
// North America
// South America
 * 
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view continent(std::string_view country = "");


/**
 * @brief Returns a random country code.
 *
 * @returns Country code consisting two letters.
 *
 * @code
 * faker::location::countryCode() // "PL"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view countryCode();

/**
 * @brief Returns a random state for a given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns State.
 *
 * @code
 * faker::location::state() // "Arizona"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view state(Locale locale = Locale::en_US);

/**
 * @brief Returns a random city for given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns City.
 *
 * @code
 * faker::location::city() // "Boston"
 * @endcode
 */
FAKER_CXX_EXPORT std::string city(Locale locale = Locale::en_US);

/**
 * @brief Returns a random zip code for given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Zip code.
 *
 * @code
 * faker::location::zipCode() // "47683-9880"
 * faker::location::zipCode(Country::Poland) // "31-881"
 * @endcode
 */
FAKER_CXX_EXPORT std::string zipCode(Locale locale = Locale::en_US);

/**
 * @brief Returns a random street address for given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Street address including building number and street name.
 *
 * @code
 * faker::location::streetAddress() // "34830 Erdman Hollow"
 * @endcode
 */
FAKER_CXX_EXPORT std::string streetAddress(Locale locale = Locale::en_US);

/**
 * @brief Returns a random street for given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Street name.
 *
 * @code
 * faker::location::street() // "Schroeder Isle"
 * @endcode
 */
FAKER_CXX_EXPORT std::string street(Locale locale = Locale::en_US);

/**
 * @brief Returns a random building number for given locale.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Building number.
 *
 * @code
 * faker::location::buildingNumber() // "505"
 * @endcode
 */
FAKER_CXX_EXPORT std::string buildingNumber(Locale locale = Locale::en_US);

/**
 * @brief Returns a random secondary address number for given locale.
 * This refers to a specific location at a given address such as an apartment or room number
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Secondary address.
 *
 * @code
 * faker::location::secondaryAddress() // "Apt. 861"
 * @endcode
 */
FAKER_CXX_EXPORT std::string secondaryAddress(Locale locale = Locale::en_US);

/**
 * @brief Generates a random latitude.
 *
 * @param precision The number of decimal points of precision for the latitude. Defaults to `Precision::FourDp`.
 *
 * @returns Latitude within -90 to 90 range.
 *
 * @code
 * faker::location::latitude() // "-30.9501"
 * @endcode
 */
FAKER_CXX_EXPORT std::string latitude(Precision precision = Precision::FourDp);

/**
 * @brief Generates a random longitude.
 *
 * @param precision The number of decimal points of precision for the longitude. Defaults to `Precision::FourDp`.
 *
 * @returns Longitude within -180 to 180 range.
 *
 * @code
 * faker::location::longitude() // "-30.9501"
 * @endcode
 */
FAKER_CXX_EXPORT std::string longitude(Precision precision = Precision::FourDp);

/**
 * @brief Generates a random GPS coordinate within the specified radius from the given coordinate.
 *
 * @param precision The number of decimal points of precision for the latitude and longitude. Defaults to
 * `Precision::FourDp`.
 * @param origin The origin GPS coordinate. Defaults to a random GPS coordinate.
 * @param radius The radius in kilometers or miles. Defaults to 10.
 * @param isMetric The unit of radius. Defaults to false which means miles.
 *
 * @returns GPS coordinate within the specified radius from the given coordinate.
 *
 * @code
 * faker::location::nearbyGPSCoordinate() // "48.8566", "2.3522"
 * faker::location::nearbyGPSCoordinate(Precision::FourDp, {33, -170}) // "33.0165", "-170.0636"
 * faker::location::nearbyGPSCoordinate(Precision::FourDp, {33, -170}, 1000, true) // "37.9163", "-179.2408"
 * @endcode
 */
FAKER_CXX_EXPORT std::tuple<std::string, std::string> nearbyGPSCoordinate(
    Precision precision = Precision::FourDp,
    const std::tuple<double, double>& origin = {std::numeric_limits<double>::max(), std::numeric_limits<double>::max()},
    double radius = 10, bool isMetric = false);

/**
 * @brief Generates a random direction from cardinal and ordinal directions.
 *
 * @returns Direction.
 *
 * @code
 * faker::location::direction() // "North"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view direction();

/**
 * @brief Generates a random time zone.
 *
 * @returns Time zone.
 *
 * @code
 * faker::location::timeZone() // "Europe/Warsaw"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view timeZone();
}
