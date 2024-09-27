#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/types/locale.h"
#include "faker-cxx/weather.h"
#include "weather_data.h"
#include <span>

using namespace ::testing;
using namespace faker;
using namespace faker::weather;

namespace
{
const std::span<const std::string_view> getWeatherDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::sv_SE:
        return svSEWeatherDescriptions;
    default:
        return enUSWeatherDescriptions;
    }
}
}

class WeatherTest : public TestWithParam<Locale>
{
public:
};

TEST_P(WeatherTest, shouldGenerateWeatherDescription)
{

    const auto locale = GetParam();

    const auto& weatherDefinition = getWeatherDefinition(locale);

    const std::string_view generatedWeatherDescription = weatherDescription(locale);

    ASSERT_TRUE(std::ranges::any_of(weatherDefinition,
                                    [generatedWeatherDescription](const std::string_view& weatherDescription)
                                    { return weatherDescription == generatedWeatherDescription; }));
}

INSTANTIATE_TEST_SUITE_P(TestWeatherByLocale, WeatherTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
