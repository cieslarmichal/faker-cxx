#include "../common/format_helper.h"
#include "color_data.h"
#include <faker/color.h>
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>
#include <sstream>

namespace faker::color {
std::string_view name() { return Helper::arrayElement(data::colors); }

std::string rgb(bool includeAlpha)
{
    const auto red = number::integer(255);
    const auto green = number::integer(255);
    const auto blue = number::integer(255);

    if (!includeAlpha) {
        return FormatHelper::format("rgb({}, {}, {})", red, green, blue);
    }

    const auto alpha = number::decimal(1.0);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;

    const auto formattedAlpha = ss.str();

    return FormatHelper::format("rgba({}, {}, {}, {})", red, green, blue, formattedAlpha);
}

std::string hex(HexCasing casing, HexPrefix prefix, bool includeAlpha)
{
    if (includeAlpha) {
        return string::hexadecimal(8, casing, prefix);
    }

    return string::hexadecimal(6, casing, prefix);
}

std::string hsl(bool includeAlpha)
{
    const auto hue = number::integer(360);
    const auto saturation = number::integer(100);
    const auto lightness = number::integer(100);

    if (!includeAlpha) {
        return FormatHelper::format("hsl({}, {}, {})", hue, saturation, lightness);
    }

    const auto alpha = number::decimal(1.0);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return FormatHelper::format("hsla({}, {}, {}, {})", hue, saturation, lightness, formattedAlpha);
}

std::string lch(bool includeAlpha)
{
    const auto luminance = number::integer(100);
    const auto chroma = number::integer(100);
    const auto hue = number::integer(360);

    if (!includeAlpha) {
        return FormatHelper::format("lch({}, {}, {})", luminance, chroma, hue);
    }

    const auto alpha = number::decimal(1.0);

    std::stringstream ss;
    ss << std::fixed;
    ss.precision(2);
    ss << alpha;
    const auto formattedAlpha = ss.str();

    return FormatHelper::format("lcha({}, {}, {}, {})", luminance, chroma, hue, formattedAlpha);
}

std::string cmyk()
{
    const auto cyan = number::decimal(1.);
    const auto magenta = number::decimal(1.);
    const auto yellow = number::decimal(1.);
    const auto key = number::decimal(1.);

    return FormatHelper::format("cmyk({:.2f}, {:.2f}, {:.2f}, {:.2f})", cyan, magenta, yellow, key);
}

std::string lab()
{
    const auto lightness = number::decimal(100.0);
    const auto redGreenValue = number::decimal(-128.0, 128.0);
    const auto blueYellowValue = number::decimal(-128.0, 128.0);

    return FormatHelper::format(
        "lab({:.2f}, {:.2f}, {:.2f})", lightness, redGreenValue, blueYellowValue);
}

std::string hsb()
{
    const auto hue = number::integer(360);
    const auto saturation = number::integer(100);
    const auto brightness = number::integer(100);

    return FormatHelper::format("hsb({}, {}, {})", hue, saturation, brightness);
}

std::string hsv()
{
    const auto hue = number::integer(360);
    const auto saturation = number::integer(100);
    const auto value = number::integer(100);

    return FormatHelper::format("hsv({}, {}, {})", hue, saturation, value);
}

std::string yuv()
{
    const auto luminance = number::integer(255);
    const auto chrominanceBlueColor = number::integer(255);
    const auto chrominanceRedColor = number::integer(255);

    return FormatHelper::format(
        "yuv({}, {}, {})", luminance, chrominanceBlueColor, chrominanceRedColor);
}

}
