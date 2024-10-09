#include "faker-cxx/weather.h"

#include <span>
#include <string_view>

#include "faker-cxx/helper.h"
#include "weather_data.h"

namespace faker::weather
{
namespace
{
std::span<const std::string_view> getWeatherDefinition(Locale locale)
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

std::string_view weatherDescription(Locale locale)
{
    const auto& weatherDefinition = getWeatherDefinition(locale);

    return helper::randomElement(weatherDefinition);
}
}
