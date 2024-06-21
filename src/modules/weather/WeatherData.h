#pragma once

#include <array>
#include <string_view>

namespace faker
{
const auto weatherDescriptions = std::to_array<std::string_view>({
    "clear sky",     "few clouds",  "scattered clouds",
    "broken clouds", "shower rain", "rainy",
    "thunderstorm",  "snowy",       "misty",
    "smoky",         "haze",        "sunny",
    "cloudy",        "windy",       "dark",
    "foggy",
});

}
