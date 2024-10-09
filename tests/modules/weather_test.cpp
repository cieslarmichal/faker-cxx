#include <algorithm>
#include <span>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/types/locale.h"
#include "faker-cxx/weather.h"
#include "weather_data.h"

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
    case Locale::cs_CZ:
        return csCZWeatherDescriptions;
    case Locale::fr_BE:
    case Locale::fr_CA:
    case Locale::fr_CH:
    case Locale::fr_LU:
    case Locale::fr_MC:
    case Locale::fr_FR:
        return frFRWeatherDescriptions;
    case Locale::pl_PL:
        return plPLWeatherDescriptions;
    case Locale::de_AT:
    case Locale::de_BE:
    case Locale::de_LU:
    case Locale::de_CH:
    case Locale::de_LI:
    case Locale::de_DE:
        return deDEWeatherDescriptions;
    case Locale::fi_FI:
        return fiFIWeatherDescriptions;
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
