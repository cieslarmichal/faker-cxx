#ifndef FAKER_WEATHER_H
#define FAKER_WEATHER_H

#include <string>

namespace faker::weather {
struct Temperature {
    double metric;
    double imperial;
};

/**
 * @brief Generates a random temperature
 *
 * @return Temperature object with metric and imperial temperatures
 *
 * @code
 * weather::temperature(); // Temperature.metric = 10, Temperature.imperial = 50
 * @endcode
 */
Temperature temperature();

struct Pressure {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random pressure
 *
 * @return Pressure object with metric and imperial pressures
 *
 * @code
 * weather::pressure(); // Pressure.metric = 1000, Pressure.imperial = 14.5
 * @endcode
 */
Pressure pressure();

struct Visibility {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random visibility
 *
 * @return Visibility object with metric and imperial visibility
 *
 * @code
 * weather::visibility(); // Visibility.metric = 10.0, Visibility.imperial = 6.2
 * @endcode
 */
Visibility visibility();

struct WindSpeed {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random wind speed
 *
 * @return WindSpeed object with metric and imperial wind speed
 *
 * @code
 * weather::wind_speed(); // WindSpeed.metric = 10.0, WindSpeed.imperial = 6.2
 * @endcode
 */
WindSpeed wind_speed();

/**
 * @brief Generated a random uvIndex
 *
 * @return Int A random uvIndex
 *
 * @code
 * weather::uv_index(); // 10
 * @endcode
 */
int uv_index();

/**
 * @brief Generated a random humidity percentage
 *
 * @return Int A random humidity percentage
 *
 * @code
 * weather::humidity(); // 10
 * @endcode
 */
int humidity();

/**
 * @brief Generated a random weather description
 *
 * @return String A random weather description
 *
 * @code
 * weather::description(); // "Sunny"
 * @endcode
 */
std::string_view description();

/**
 * @brief Generated a random cloud cover percentage
 *
 * @return Int A random cloud cover percentage
 *
 * @code
 * weather::cloud_cover(); // 10
 * @endcode
 */
int cloud_cover();
}

#endif