#include "faker-cxx/Weather.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "weather/WeatherData.h"

using namespace ::testing;
using namespace faker::weather;

class WeatherTest : public Test
{
public:
};

TEST_F(WeatherTest, shouldGenerateWeatherDescription)
{
    const std::string_view generatedWeatherDescription = weatherDescription();

    ASSERT_TRUE(std::ranges::any_of(weatherDescriptions,
                                    [generatedWeatherDescription](const std::string_view& weatherDescription)
                                    { return weatherDescription == generatedWeatherDescription; }));
}
