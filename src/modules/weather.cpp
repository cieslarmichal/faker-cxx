#include "faker-cxx/weather.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "weather_data.h"

namespace faker::weather
{
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
std::string_view weatherDescription(Locale locale)
{
    const auto& weatherDefinition = getWeatherDefinition(locale);

    return helper::randomElement(weatherDefinition);
}
}
