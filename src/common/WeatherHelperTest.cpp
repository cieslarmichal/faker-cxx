#include "WeatherHelper.h"
#include "gtest/gtest.h"

using namespace faker;
using namespace ::testing;

class WeatherHelperTest : public Test {
public:
};

TEST_F(WeatherHelperTest, shouldConvertCelsiusToFahrenheit) {
    double celsius = 10.0;
    double fahrenheit = WeatherHelper::celsiusToFahrenheit(celsius);

    ASSERT_EQ(fahrenheit, 50.0);
}

TEST_F(WeatherHelperTest, shouldConvertKPaToPsi) {
    double kPa = 100.0;
    double psi = WeatherHelper::kPaToPsi(kPa);

    ASSERT_EQ(psi, 14.503773773375);
}

TEST_F(WeatherHelperTest, shouldConvertMilesToKilometers) {
    double miles = 10.0;
    double kilometers = WeatherHelper::milesToKilometers(miles);

    ASSERT_EQ(kilometers, 16.09344);
}
