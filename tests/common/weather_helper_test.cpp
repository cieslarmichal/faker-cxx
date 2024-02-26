#include "../test_helpers.h"
#include <common/weather_helper.h>

using namespace faker;

TEST(WeatherHelperTest, shouldConvertCelsiusToFahrenheit)
{
    double celsius = 10.0;
    double fahrenheit = WeatherHelper::celsiusToFahrenheit(celsius);

    ASSERT_EQ(fahrenheit, 50.0);
}

TEST(WeatherHelperTest, shouldConvertKPaToPsi)
{
    double kPa = 100.0;
    double psi = WeatherHelper::kPaToPsi(kPa);

    ASSERT_EQ(psi, 14.503773773375);
}

TEST(WeatherHelperTest, shouldConvertMilesToKilometers)
{
    double miles = 10.0;
    double kilometers = WeatherHelper::milesToKilometers(miles);

    ASSERT_EQ(kilometers, 16.09344);
}
