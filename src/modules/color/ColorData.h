#pragma once

#include <array>
#include <string_view>

namespace faker::color
{
const auto colors = std::to_array<std::string_view>({
    "red",      "green",  "blue",    "yellow", "purple", "mint green", "teal",      "white",
    "black",    "orange", "pink",    "grey",   "maroon", "violet",     "turquoise", "tan",
    "sky blue", "salmon", "plum",    "orchid", "olive",  "magenta",    "lime",      "ivory",
    "indigo",   "gold",   "fuchsia", "cyan",   "azure",  "lavender",   "silver",
});

}
