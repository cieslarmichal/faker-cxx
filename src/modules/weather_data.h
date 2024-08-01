#pragma once

#include <array>
#include <string_view>

namespace faker::weather
{
const auto weatherDescriptions = std::to_array<std::string_view>({
    "broken clouds",
    "clear sky",
    "cloudy",
    "dark",
    "few clouds",
    "foggy",
    "haze",
    "misty",
    "rainy",
    "scattered clouds",
    "shower rain",
    "smoky",
    "snowy",
    "sunny",
    "thunderstorm",
    "windy",
});

}
