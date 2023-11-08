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
std::string Color::hsl(bool includeAlpha)
{
    const std::integral auto hue = Number::integer(360);
    const std::integral auto saturation = Number::integer(100);
    const std::integral auto lightness = Number::integer(100);

    if (!includeAlpha)
    {
        return fmt::format("hsl({}, {}, {})", hue, saturation, lightness);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return fmt::format("hsla({}, {}, {}, {})", hue, saturation, lightness, formattedAlpha);
}
std::string Color::lch(bool includeAlpha)
{
    const std::integral auto luminance = Number::integer(100);
    const std::integral auto chroma = Number::integer(100);
    const std::integral auto hue = Number::integer(360);

    if (!includeAlpha)
    {
        return fmt::format("lch({}, {}, {})", luminance, chroma, hue);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return fmt::format("lcha({}, {}, {}, {})", luminance, chroma, hue, formattedAlpha);
}

std::string Color::cmyk()
{
    const std::floating_point auto cyan = Number::decimal<double>(1.);
    const std::floating_point auto magenta = Number::decimal<double>(1.);
    const std::floating_point auto yellow = Number::decimal<double>(1.);
    const std::floating_point auto key = Number::decimal<double>(1.);

    return fmt::format("cmyk({:.2f}, {:.2f}, {:.2f}, {:.2f})", cyan, magenta, yellow, key);
}

}
