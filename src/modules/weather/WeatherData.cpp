#include "WeatherData.h"

#include <array>
#include <string_view>

namespace faker
{

const std::array<std::string_view, 16> weatherDescriptions = {
    "clear sky",     "few clouds",  "scattered clouds",
    "broken clouds", "shower rain", "rainy",
    "thunderstorm",  "snowy",       "misty",
    "smoky",         "haze",        "sunny",
    "cloudy",        "windy",       "dark",
    "foggy",
};

}
