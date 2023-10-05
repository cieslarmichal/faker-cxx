#include "faker-cxx/Color.h"

#include <sstream>

#include "data/Colors.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "fmt/format.h"

namespace faker
{
std::string Color::name()
{
    return Helper::arrayElement<std::string>(colors);
}

std::string Color::rgb(bool includeAlpha)
{
    const std::integral auto red = Number::integer(255);
    const std::integral auto green = Number::integer(255);
    const std::integral auto blue = Number::integer(255);

    if (!includeAlpha)
    {
        return fmt::format("rgb({}, {}, {})", red, green, blue);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return fmt::format("rgba({}, {}, {}, {})", red, green, blue, formattedAlpha);
}

std::string Color::hex(HexCasing casing, HexPrefix prefix, bool includeAlpha)
{
    if (includeAlpha)
    {
        return String::hexadecimal(8, casing, prefix);
    }

    return String::hexadecimal(6, casing, prefix);
}
}
