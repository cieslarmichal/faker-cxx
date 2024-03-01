#include "../common/formatter.h"
#include "../common/random.h"
#include "color_data.h"
#include <faker/color.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::color {
std::string_view name() { return random::element(data::colors); }

std::string rgb(bool include_alpha)
{
    auto red = number::integer(255);
    auto green = number::integer(255);
    auto blue = number::integer(255);

    if (!include_alpha) {
        return utils::format("rgb({}, {}, {})", red, green, blue);
    }

    auto alpha = number::decimal(1.0);

    return utils::format("rgba({}, {}, {}, {:.2f})", red, green, blue, alpha);
}

std::string hex(hex_case_t casing, hex_prefix_t prefix, bool include_alpha)
{
    return string::hexadecimal(include_alpha ? 8 : 6, casing, prefix);
}

std::string hsl(bool include_alpha)
{
    auto hue = number::integer(360);
    auto saturation = number::integer(100);
    auto lightness = number::integer(100);

    if (!include_alpha) {
        return utils::format("hsl({}, {}, {})", hue, saturation, lightness);
    }

    auto alpha = number::decimal(1.0);

    return utils::format("hsla({}, {}, {}, {:.2f})", hue, saturation, lightness, alpha);
}

std::string lch(bool include_alpha)
{
    auto luminance = number::integer(100);
    auto chroma = number::integer(100);
    auto hue = number::integer(360);

    if (!include_alpha) {
        return utils::format("lch({}, {}, {})", luminance, chroma, hue);
    }

    auto alpha = number::decimal(1.0);

    return utils::format("lcha({}, {}, {}, {:.2f})", luminance, chroma, hue, alpha);
}

std::string cmyk()
{
    auto cyan = number::decimal(1.);
    auto magenta = number::decimal(1.);
    auto yellow = number::decimal(1.);
    auto key = number::decimal(1.);

    return utils::format("cmyk({:.2f}, {:.2f}, {:.2f}, {:.2f})", cyan, magenta, yellow, key);
}

std::string lab()
{
    auto lightness = number::decimal(100.0);
    auto red_green = number::decimal(-128.0, 128.0);
    auto blue_yellow = number::decimal(-128.0, 128.0);

    return utils::format("lab({:.2f}, {:.2f}, {:.2f})", lightness, red_green, blue_yellow);
}

std::string hsb()
{
    auto hue = number::integer(360);
    auto saturation = number::integer(100);
    auto brightness = number::integer(100);

    return utils::format("hsb({}, {}, {})", hue, saturation, brightness);
}

std::string hsv()
{
    auto hue = number::integer(360);
    auto saturation = number::integer(100);
    auto value = number::integer(100);

    return utils::format("hsv({}, {}, {})", hue, saturation, value);
}

std::string yuv()
{
    auto luminance = number::integer(255);
    auto chrominance_blue = number::integer(255);
    auto chrominance_red = number::integer(255);

    return utils::format("yuv({}, {}, {})", luminance, chrominance_blue, chrominance_red);
}

}
