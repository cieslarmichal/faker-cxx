#include "../test_helpers.h"
#include <common/conversions.h>

using namespace faker;

TEST(WeatherHelperTest, shouldConvertCelsiusToFahrenheit)
{
    double celsius = 10.0;
    double fahrenheit = utils::celsius_to_fahrenheit(celsius);

    ASSERT_EQ(fahrenheit, 50.0);
}

TEST(WeatherHelperTest, shouldConvertKPaToPsi)
{
    double kPa = 100.0;
    double psi = utils::kpa_to_psi(kPa);

    ASSERT_EQ(psi, 14.503773773375);
}

TEST(WeatherHelperTest, shouldConvertMilesToKilometers)
{
    double miles = 10.0;
    double kilometers = utils::mile_to_km(miles);

    ASSERT_EQ(kilometers, 16.09344);
}