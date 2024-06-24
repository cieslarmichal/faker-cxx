#include "faker-cxx/Weather.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "WeatherData.h"

namespace faker::weather
{
std::string_view weatherDescription()
{
    return Helper::arrayElement(weatherDescriptions);
}
}
