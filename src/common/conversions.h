#ifndef FAKER_COMMON_CONVERSIONS_H
#define FAKER_COMMON_CONVERSIONS_H

namespace faker::utils {
/**
 * @brief Converts celsius to fahrenheit
 *
 * @param celsius
 *
 * @return double
 *
 * @code
 * faker::utils::celsius_to_fahrenheit(10); // 50
 * @endcode
 */
double celsius_to_fahrenheit(double celsius);

/**
 * @brief Converts kPa to PSI
 *
 * @param kPa
 *
 * @return double
 *
 * @code
 * faker::utils::kpa_to_psi(1000); // 145.037
 * @endcode
 */
double kpa_to_psi(double kPa);

/**
 * @brief Converts miles to kilometers
 *
 * @param miles
 *
 * @return double
 *
 * @code
 * faker::utils::mile_to_km(10); // 16.0934
 * @endcode
 */
double mile_to_km(double miles);
}

#endif