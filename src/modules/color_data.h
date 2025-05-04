#pragma once

#include <array>
#include <string_view>

namespace faker::color
{
const auto englishColors = std::to_array<std::string_view>({
    "azure",     "black",        "blue",       "cyan",    "fuchsia", "gold",       "green",    "grey",     "indigo",
    "ivory",     "lavender",     "lime",       "magenta", "maroon",  "mint green", "olive",    "orange",   "orchid",
    "pink",      "plum",         "purple",     "red",     "salmon",  "silver",     "sky blue", "tan",      "teal",
    "turquoise", "violet",       "white",      "yellow",  "amber",   "apricot",    "beige",    "bronze",   "charcoal",
    "cherry",    "chocolate",    "copper",     "coral",   "cream",   "crimson",    "denim",    "eggplant", "emerald",
    "flamingo",  "forest green", "graphite",   "jade",    "lemon",   "lilac",      "mahogany", "mustard",  "navy",
    "ochre",     "peach",        "periwinkle", "rose",    "ruby",    "rust",       "sapphire", "scarlet",  "sepia",
    "slate",     "snow",         "steel",      "taupe",   "topaz",   "umber",      "wheat",    "wine",

});

const auto polishColors = std::to_array<std::string_view>({
    "błękitny",     "czarny",        "niebieski", "cyjan",     "fuksja",    "złoty",      "zielony",   "szary",
    "indygo",       "kość słoniowa", "lawendowy", "limonkowy", "magenta",   "kasztanowy", "miętowy",   "oliwkowy",
    "pomarańczowy", "orchidea",      "różowy",    "śliwkowy",  "purpurowy", "czerwony",   "łososiowy", "srebrny",
    "błękit nieba", "jasnobrązowy",  "morski",    "turkusowy", "fioletowy", "biały",      "żółty",
});

}
