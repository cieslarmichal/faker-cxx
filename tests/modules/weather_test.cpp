#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/types/locale.h"
#include "faker-cxx/weather.h"
#include "weather_data.h"

using namespace ::testing;
using namespace faker::weather;

namespace
{
const auto& getWeatherDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::sv_SE:
        return svSEWeatherDescriptions;
    case Locale::en_029:
    case Locale::en_AU:
    case Locale::en_BW:
    case Locale::en_BZ:
    case Locale::en_CA:
    case Locale::en_cb:
    case Locale::en_GB:
    case Locale::en_GH:
    case Locale::en_HK:
    case Locale::en_IE:
    case Locale::en_IN:
    case Locale::en_JM:
    case Locale::en_MT:
    case Locale::en_MY:
    case Locale::en_NZ:
    case Locale::en_PH:
    case Locale::en_SG:
    case Locale::en_TT:
    case Locale::en_US:
    case Locale::en_ZA:
    case Locale::en_ZW:
    default:
        return enUSWeatherDescriptions;
    }
}
}

class WeatherTest : public TestWithParam<Locale>
{
public:
};

TEST_F(WeatherTest, shouldGenerateWeatherDescription)
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
