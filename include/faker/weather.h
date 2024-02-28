#ifndef FAKER_WEATHER_H
#define FAKER_WEATHER_H

#include <string>

namespace faker::weather {
struct temperature_value {
    double metric;
    double imperial;
};

/**
 * @brief Generates a random temperature
 *
 * @return temperature_value object with metric and imperial temperatures
 *
 * @code
 * weather::temperature(); // temperature_value.metric = 10, temperature_value.imperial = 50
 * @endcode
 */
temperature_value temperature();

struct pressure_value {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random pressure
 *
 * @return pressure_value object with metric and imperial pressures
 *
 * @code
 * weather::pressure(); // pressure_value.metric = 1000, pressure_value.imperial = 14.5
 * @endcode
 */
pressure_value pressure();

struct visibility_value {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random visibility
 *
 * @return visibility_value object with metric and imperial visibility
 *
 * @code
 * weather::visibility(); // visibility_value.metric = 10.0, visibility_value.imperial = 6.2
 * @endcode
 */
visibility_value visibility();

struct wind_speed_value {
    double metric;
    double imperial;
};

/**
 * @brief Generated a random wind speed
 *
 * @return wind_speed_value object with metric and imperial wind speed
 *
 * @code
 * weather::wind_speed(); // wind_speed_value.metric = 10.0, wind_speed_value.imperial = 6.2
 * @endcode
 */
wind_speed_value wind_speed();

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