#include "faker-cxx/Weather.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "WeatherData.h"

namespace faker
{
std::string_view Weather::weatherDescription()
{
    return Helper::arrayElement(weatherDescriptions);
}
}
