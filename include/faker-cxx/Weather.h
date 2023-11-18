#pragma once

#include <string>

namespace faker
{
class Weather
{
public:
    struct Temperature
    {
        double metric, imperial;
    };

    /**
     * @brief Generates a random temperature
     *
     * @return Temperature object with metric and imperial temperatures
     *
     * @code
     * Weather::temperature(); // Temperature.metric = 10, Temperature.imperial = 50
     * @endcode
     */
    static Temperature temperature();

    struct Pressure
    {
        double metric;
        double imperial;
    };

    /**
     * @brief Generated a random pressure
     *
     * @return Pressure object with metric and imperial pressures
     *
     * @code
     * Weather::pressure(); // Pressure.metric = 1000, Pressure.imperial = 14.5
     * @endcode
     */
    static Pressure pressure();

    struct Visibility
    {
        double metric;
        double imperial;
    };

    /**
     * @brief Generated a random visibility
     *
     * @return Visibility object with metric and imperial visibility
     *
     * @code
     * Weather::visibility(); // Visibility.metric = 10.0, Visibility.imperial = 6.2
     * @endcode
     */
    static Visibility visibility();

    struct WindSpeed
    {
        double metric;
        double imperial;
    };

    /**
     * @brief Generated a random wind speed
     *
     * @return WindSpeed object with metric and imperial wind speed
     *
     * @code
     * Weather::windSpeed(); // WindSpeed.metric = 10.0, WindSpeed.imperial = 6.2
     * @endcode
     */
    static WindSpeed windSpeed();

    /**
     * @brief Generated a random uvIndex
     *
     * @return Int A random uvIndex
     *
     * @code
     * Weather::uvIndex(); // 10
     * @endcode
     */
    static int uvIndex();

    /**
     * @brief Generated a random humidity percentage
     *
     * @return Int A random humidity percentage
     *
     * @code
     * Weather::humidity(); // 10
     * @endcode
     */
    static int humidity();

    /**
     * @brief Generated a random weather description
     *
     * @return String A random weather description
     *
     * @code
     * Weather::description(); // "Sunny"
     * @endcode
     */
    static std::string weatherDescription();

    /**
     * @brief Generated a random cloud cover percentage
     *
     * @return Int A random cloud cover percentage
     *
     * @code
     * Weather::cloudCover(); // 10
     * @endcode
     */
    static int cloudCover();
};
}
