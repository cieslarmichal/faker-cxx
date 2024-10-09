#pragma once

#include <array>
#include <string_view>

namespace faker::weather
{
const auto enUSWeatherDescriptions = std::to_array<std::string_view>({
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
    "dimma",     // fog
    "regn",      // rain
    "snö",       // snow
    "sol",       // sun
    "vind",      // wind
    "is",        // ice
    "storm",     // storm
    "vinter",    // winter
    "kallt",     // cold
    "snöflinga", // snow flake
    "snöstorm",  // blizzard
    "sommar",    // summer
    "vår",       // spring
    "skurar",    // showers
    "höst",      // fall/autumn
});

const auto csCZWeatherDescriptions = std::to_array<std::string_view>({
    "dusno",
    "chladno",
    "horko",
    "jasno",
    "mlhavo",
    "oblačno",
    "slunečno",
    "sucho",
    "teplo",
    "vedro",
    "vlhko",
    "zamračeno",
    "zima",
    "příjemně",
    "polojasno",
});

const auto frFRWeatherDescriptions = std::to_array<std::string_view>({
    "enneigée",
    "ensoleillée",
    "humide",
    "nuageux",
    "orageux",
    "sèche",
    "venteuse",
    "pleut",
    "pleut à verse",
    "du soleil",
    "du vent",
    "du brouillard",
    "neige",
    "gèle",
    "grêle",
    "mauvais",
});

const auto plPLWeatherDescriptions = std::to_array<std::string_view>({
    "pogoda",
    "słońce",
    "deszcz",
    "śnieg",
    "wiatr",
    "chmura",
    "mgła",
    "lód",
    "burza",
    "grzmot",
    "piorun",
    "śnieżyca",
});

const auto deDEWeatherDescriptions = std::to_array<std::string_view>({
    "sonnig",
    "wolkig",
    "windig",
    "regnerisch",
    "verregnet",
    "neblig",
    "diesig",
    "trüb",
    "stürmisch",
    "schnee",
    "hagel",
    "nebel",
});

const auto fiFIWeatherDescriptions = std::to_array<std::string_view>({
    "sumu",
    "sade",
    "lumi",
    "aurinkoinen",
    "tuuli",
    "jää",
    "myrsky",
    "pilvi",
    "rankkasade",
    "kostea",
    "sadekuuro",
    "kuura",
    "rae",
    "räntä",
});

}
