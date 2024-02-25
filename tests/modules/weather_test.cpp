#include "../test_helpers.h"
#include <algorithm>
#include <faker/weather.h>
#include <modules/weather_data.h>
#include <string>

using namespace ::testing;
using namespace faker;

class WeatherTest : public Test {
public:
};

TEST_F(WeatherTest, shouldGenerateTemperature)
{
    weather::Temperature generatedTemperature = weather::temperature();

    ASSERT_TRUE(generatedTemperature.metric >= 10 && generatedTemperature.metric <= 30);
    ASSERT_TRUE(generatedTemperature.imperial >= 50 && generatedTemperature.imperial <= 90);
}

TEST_F(WeatherTest, shouldGeneratePressure)
{
    weather::Pressure generatedPressure = weather::pressure();

    ASSERT_TRUE(generatedPressure.metric >= 100.0 && generatedPressure.metric <= 102.0);
    ASSERT_TRUE(generatedPressure.imperial >= 14.5 && generatedPressure.imperial <= 14.8);
}

TEST_F(WeatherTest, shouldGenerateVisibility)
{
    weather::Visibility generatedVisibility = weather::visibility();

    ASSERT_TRUE(generatedVisibility.metric >= 1 && generatedVisibility.metric <= 10.0);
    ASSERT_TRUE(generatedVisibility.imperial >= 1.6 && generatedVisibility.imperial <= 16.1);
}

TEST_F(WeatherTest, shouldGenerateWindSpeed)
{
    weather::WindSpeed generatedWindSpeed = weather::windSpeed();

    ASSERT_TRUE(generatedWindSpeed.metric >= 0.1 && generatedWindSpeed.metric <= 24.2);
    ASSERT_TRUE(generatedWindSpeed.imperial >= 0.1 && generatedWindSpeed.imperial <= 15.0);
}

TEST_F(WeatherTest, shouldGenerateUvIndex)
{
    int generatedUvIndex = weather::uvIndex();

    ASSERT_TRUE(generatedUvIndex >= 0 && generatedUvIndex <= 11);
}

TEST_F(WeatherTest, shouldGenerateHumidity)
{
    int generatedHumidity = weather::humidity();

    ASSERT_TRUE(generatedHumidity >= 0 && generatedHumidity <= 100);
}

TEST_F(WeatherTest, shouldGenerateWeatherDescription)
{
    std::string generatedWeatherDescription = weather::weatherDescription();

    ASSERT_TRUE(faker::testing::any_of(
        weatherDescriptions, [generatedWeatherDescription](const std::string& weatherDescription) {
            return weatherDescription == generatedWeatherDescription;
        }));
}

TEST_F(WeatherTest, shouldGenerateWeatherCloudCover)
{
    int generatedCloudCover = weather::cloudCover();

    ASSERT_TRUE(generatedCloudCover >= 0 && generatedCloudCover <= 100);
}
