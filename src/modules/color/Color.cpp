#include "faker-cxx/Color.h"

#include <sstream>

#include "../../common/FormatHelper.h"
#include "data/Colors.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

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
        return FormatHelper::format("rgb({}, {}, {})", red, green, blue);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;

    const auto formattedAlpha = ss.str();

    return FormatHelper::format("rgba({}, {}, {}, {})", red, green, blue, formattedAlpha);
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
        return FormatHelper::format("hsl({}, {}, {})", hue, saturation, lightness);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return FormatHelper::format("hsla({}, {}, {}, {})", hue, saturation, lightness, formattedAlpha);
}

std::string Color::lch(bool includeAlpha)
{
    const std::integral auto luminance = Number::integer(100);
    const std::integral auto chroma = Number::integer(100);
    const std::integral auto hue = Number::integer(360);

    if (!includeAlpha)
    {
        return FormatHelper::format("lch({}, {}, {})", luminance, chroma, hue);
    }

    const std::floating_point auto alpha = Number::decimal<double>(1);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return FormatHelper::format("lcha({}, {}, {}, {})", luminance, chroma, hue, formattedAlpha);
}

std::string Color::cmyk()
{
    const std::floating_point auto cyan = Number::decimal<double>(1.);
    const std::floating_point auto magenta = Number::decimal<double>(1.);
    const std::floating_point auto yellow = Number::decimal<double>(1.);
    const std::floating_point auto key = Number::decimal<double>(1.);

    return FormatHelper::format("cmyk({:.2f}, {:.2f}, {:.2f}, {:.2f})", cyan, magenta, yellow, key);
}

std::string Color::lab()
{
    const std::floating_point auto lightness = Number::decimal<double>(100.0);
    const std::floating_point auto redGreenValue = Number::decimal<double>(-128.0, 128.0);
    const std::floating_point auto blueYellowValue = Number::decimal<double>(-128.0, 128.0);

    return FormatHelper::format("lab({:.2f}, {:.2f}, {:.2f})", lightness, redGreenValue, blueYellowValue);
}

std::string Color::hsb()
{
    const std::integral auto hue = Number::integer(360);
    const std::integral auto saturation = Number::integer(100);
    const std::integral auto brightness = Number::integer(100);

    return FormatHelper::format("hsb({}, {}, {})", hue, saturation, brightness);
}

std::string Color::hsv()
{
    const std::integral auto hue = Number::integer(360);
    const std::integral auto saturation = Number::integer(100);
    const std::integral auto value = Number::integer(100);

    return FormatHelper::format("hsv({}, {}, {})", hue, saturation, value);
}

std::string Color::yuv()
{
    const std::integral auto luminance = Number::integer(255);
    const std::integral auto chrominanceBlueColor = Number::integer(255);
    const std::integral auto chrominanceRedColor = Number::integer(255);

    return FormatHelper::format("yuv({}, {}, {})", luminance, chrominanceBlueColor, chrominanceRedColor);
}

}
