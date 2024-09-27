#include "faker-cxx/weather.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "weather_data.h"
#include <span>

namespace faker::weather
{
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
std::string_view weatherDescription(Locale locale)
{
    const auto& weatherDefinition = getWeatherDefinition(locale);

    return helper::randomElement(weatherDefinition);
}
}
