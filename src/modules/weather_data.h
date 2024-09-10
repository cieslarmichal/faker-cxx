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

const auto svSEWeatherDescriptions = std::to_array<std::string_view>({
    "dimma",    // fog
    "regn", // rain
    "snö", // snow
    "sol", // sun
    "vind", // wind
    "is", // ice
    "storm", // storm
    "vinter", // winter
    "kallt", // cold
    "snöflinga", // snow flake
    "snöstorm", // blizzard
    "sommar", // summer
    "vår", // spring
    "skurar", // showers
    "höst", // fall/autumn
});

}
