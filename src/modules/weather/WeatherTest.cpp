#include "faker-cxx/Weather.h"

#include <algorithm>
#include <string>

#include "gtest/gtest.h"
#include "data/WeatherDescription.h"

using namespace ::testing;
using namespace faker;

class WeatherTest : public Test
{
public:
};

TEST_F(WeatherTest, shouldGenerateTemperature)
{
    Weather::Temperature generatedTemperature = Weather::temperature();

    ASSERT_TRUE(generatedTemperature.metric >= 10 && generatedTemperature.metric <= 30);
    ASSERT_TRUE(generatedTemperature.imperial >= 50 && generatedTemperature.imperial <= 90);
}

TEST_F(WeatherTest, shouldGeneratePressure)
{
    Weather::Pressure generatedPressure = Weather::pressure();

    ASSERT_TRUE(generatedPressure.metric >= 1000 && generatedPressure.metric <= 1100);
    ASSERT_TRUE(generatedPressure.imperial >= 14.0 && generatedPressure.imperial <= 16.0);
}

TEST_F(WeatherTest, shouldGenerateVisibility)
{
    Weather::Visibility generatedVisibility = Weather::visibility();

    ASSERT_TRUE(generatedVisibility.metric >= 0.1 && generatedVisibility.metric <= 10.0);
    ASSERT_TRUE(generatedVisibility.imperial >= 0.1 && generatedVisibility.imperial <= 6.2);
}

TEST_F(WeatherTest, shouldGenerateWindSpeed)
{
    Weather::WindSpeed generatedWindSpeed = Weather::windSpeed();

    ASSERT_TRUE(generatedWindSpeed.metric >= 0.1 && generatedWindSpeed.metric <= 24.2);
    ASSERT_TRUE(generatedWindSpeed.imperial >= 0.1 && generatedWindSpeed.imperial <= 15.0);
}

TEST_F(WeatherTest, shouldGenerateUvIndex)
{
    int generatedUvIndex = Weather::uvIndex();

    ASSERT_TRUE(generatedUvIndex >= 0 && generatedUvIndex <= 11);
}

TEST_F(WeatherTest, shouldGenerateHumidity)
{
    int generatedHumidity = Weather::humidity();

    ASSERT_TRUE(generatedHumidity >= 0 && generatedHumidity <= 100);
}

TEST_F(WeatherTest, shouldGenerateWeatherDescription)
{
    std::string generatedWeatherDescription = Weather::weatherDescription();

    ASSERT_TRUE(std::ranges::any_of(weatherDescriptions, [generatedWeatherDescription](const std::string& weatherDescription)
                                    { return weatherDescription == generatedWeatherDescription; }));
}

TEST_F(WeatherTest, shouldGenerateWeatherCloudCover) {
    int generatedCloudCover = Weather::cloudCover();

    ASSERT_TRUE(generatedCloudCover >= 0 && generatedCloudCover <= 100);
}
