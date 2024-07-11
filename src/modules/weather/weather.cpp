#include "faker-cxx/weather.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "weather_data.h"

namespace faker::weather
{
std::string_view weatherDescription()
{
    return helper::arrayElement(weatherDescriptions);
}
}
