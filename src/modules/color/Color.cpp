#include "faker-cxx/Color.h"

#include "../../common/FormatHelper.h"
#include "ColorData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string_view Color::name()
{
    return Helper::arrayElement(colors);
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

    std::floating_point auto alpha = Number::decimal(1.0);

    return FormatHelper::format("rgba({}, {}, {}, {:.2f})", red, green, blue, alpha);
}

std::string Color::hex(HexCasing casing, HexPrefix prefix, bool includeAlpha)
{
    return String::hexadecimal(includeAlpha ? 8 : 6, casing, prefix);
}

std::string Color::hsl(bool include_alpha)
{
    std::integral auto hue = Number::integer(360);
    std::integral auto saturation = Number::integer(100);
    std::integral auto lightness = Number::integer(100);

    if (!include_alpha)
    {
        return FormatHelper::format("hsl({}, {}, {})", hue, saturation, lightness);
    }

    std::floating_point auto alpha = Number::decimal(1.0);

    return FormatHelper::format("hsla({}, {}, {}, {:.2f})", hue, saturation, lightness, alpha);
}

std::string Color::lch(bool include_alpha)
{
    std::integral auto luminance = Number::integer(100);
    std::integral auto chroma = Number::integer(100);
    std::integral auto hue = Number::integer(360);

    if (!include_alpha)
    {
        return FormatHelper::format("lch({}, {}, {})", luminance, chroma, hue);
    }

    std::floating_point auto alpha = Number::decimal(1.0);

    return FormatHelper::format("lcha({}, {}, {}, {:.2f})", luminance, chroma, hue, alpha);
}

std::string Color::cmyk()
{
    std::floating_point auto cyan = Number::decimal(1.);
    std::floating_point auto magenta = Number::decimal(1.);
    std::floating_point auto yellow = Number::decimal(1.);
    std::floating_point auto key = Number::decimal(1.);

    return FormatHelper::format("cmyk({:.2f}, {:.2f}, {:.2f}, {:.2f})", cyan, magenta, yellow, key);
}

std::string Color::lab()
{
    std::floating_point auto lightness = Number::decimal(100.0);
    std::floating_point auto red_green = Number::decimal(-128.0, 128.0);
    std::floating_point auto blue_yellow = Number::decimal(-128.0, 128.0);

    return FormatHelper::format("lab({:.2f}, {:.2f}, {:.2f})", lightness, red_green, blue_yellow);
}

std::string Color::hsb()
{
    std::integral auto hue = Number::integer(360);
    std::integral auto saturation = Number::integer(100);
    std::integral auto brightness = Number::integer(100);

    return FormatHelper::format("hsb({}, {}, {})", hue, saturation, brightness);
}

std::string Color::hsv()
{
    std::integral auto hue = Number::integer(360);
    std::integral auto saturation = Number::integer(100);
    std::integral auto value = Number::integer(100);

    return FormatHelper::format("hsv({}, {}, {})", hue, saturation, value);
}

std::string Color::yuv()
{
    std::integral auto luminance = Number::integer(255);
    std::integral auto chrominance_blue = Number::integer(255);
    std::integral auto chrominance_red = Number::integer(255);

    return FormatHelper::format("yuv({}, {}, {})", luminance, chrominance_blue, chrominance_red);
}

}
