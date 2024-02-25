#ifndef FAKER_COMMON_WEATHER_HELPER_H
#define FAKER_COMMON_WEATHER_HELPER_H

namespace faker {
class WeatherHelper {
public:
    /**
     * @brief Converts celsius to fahrenheit
     *
     * @param celsius
     *
     * @return double
     *
     * @code
     * WeatherHelper::celsiusToFahrenheit(10); // 50
     * @endcode
     */
    static double celsiusToFahrenheit(double celsius);

    /**
     * @brief Converts kPa to PSI
     *
     * @param kPa
     *
     * @return double
     *
     * @code
     * WeatherHelper::kPaToPsi(1000); // 145.037
     * @endcode
     */
    static double kPaToPsi(double kPa);

    /**
     * @brief Converts miles to kilometers
     *
     * @param miles
     *
     * @return double
     *
     * @code
     * WeatherHelper::milesToKilometers(10); // 16.0934
     * @endcode
     */
    static double milesToKilometers(double miles);
};
}

#endif