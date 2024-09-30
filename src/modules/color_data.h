#pragma once

#include <array>
#include <string_view>

namespace faker::color
{
const auto englishColors = std::to_array<std::string_view>({
    "azure",    "black",  "blue",     "cyan",      "fuchsia", "gold",   "green",      "grey",
    "indigo",   "ivory",  "lavender", "lime",      "magenta", "maroon", "mint green", "olive",
    "orange",   "orchid", "pink",     "plum",      "purple",  "red",    "salmon",     "silver",
    "sky blue", "tan",    "teal",     "turquoise", "violet",  "white",  "yellow",
});

const auto polishColors = std::to_array<std::string_view>({
    "błękitny",     "czarny",        "niebieski", "cyjan",     "fuksja",    "złoty",      "zielony",   "szary",
    "indygo",       "kość słoniowa", "lawendowy", "limonkowy", "magenta",   "kasztanowy", "miętowy",   "oliwkowy",
    "pomarańczowy", "orchidea",      "różowy",    "śliwkowy",  "purpurowy", "czerwony",   "łososiowy", "srebrny",
    "błękit nieba", "jasnobrązowy",  "morski",    "turkusowy", "fioletowy", "biały",      "żółty",
});

}
