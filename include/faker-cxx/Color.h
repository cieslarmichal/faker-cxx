#pragma once

#include <string>

#include "types/Hex.h"

namespace faker
{
class Color
{
public:
    /**
     * @brief Returns a random color.
     *
     * @returns Human readable color name.
     *
     * @code
     * Color::name() // "Blue"
     * @endcode
     */
    static std::string_view name();

    /**
     * @brief Returns an RGB color.
     *
     * @param includeAlpha Adds an alpha value to the color (RGBA). Defaults to `false`.
     *
     * @returns RGB color formatted with rgb(X,X,X) or rgba(X,X,X,X).
     *
     * @code
     * Color::rgb() // "rgb(67, 28, 240)"
     * Color::rgb(true) // "rgba(220, 28, 79, 0.50)"
     * @endcode
     */
    static std::string rgb(bool includeAlpha = false);

    /**
     * @brief Returns a hex color.
     *
     * @param casing Casing of the generated string. Defaults to `HexCasing::Lower`.
     * @param prefix Prefix for the generated string. Defaults to `HexPrefix::ZeroX`.
     * @param includeAlpha Adds an alpha value to the color. Defaults to `false`.
     *
     * @returns Hex color formatted that starts with `0x` or `#`.
     *
     * @code
     * Color::hex() // "#e3f380"
     * Color::hex(HexCasing::Upper, HexPrefix::ZeroX, true) // "0xE3F3801A"
     * @endcode
     */
    static std::string hex(HexCasing casing = HexCasing::Lower, HexPrefix prefix = HexPrefix::Hash,
                           bool includeAlpha = false);

    /**
     * @brief Returns an HSL color.
     *
     * @param includeAlpha Adds an alpha value to the color (HSLA). Defaults to `false`.
     * @returns HSL color formatted with hsl(X,X,X) or hsla(X,X,X,X).
     * @code
     * Color::hsl() // "hsl(0, 20, 100)"
     * Color::hsl(true) // "hsla(0, 0, 100, 0.50)"
     * @endcode
     */
    static std::string hsl(bool includeAlpha = false);

    /**
     * @brief Returns an LCH color.
     *
     * @param includeAlpha Adds an alpha value to the color (LCHA). Defaults to `false`.
     * @returns LCH color formatted with lch(X,X,X) or lcha(X,X,X,X).
     * @code
     * Color::lch() // "lch(0, 20, 100)"
     * Color::lch(true) // "lcha(0, 0, 100, 0.50)"
     * @endcode
     */
    static std::string lch(bool includeAlpha = false);

    /**
     * @brief Return a CMYK color
     *
     * @returns CMYK color formatted with cmyk(X,X,X,X)
     * @code
     * Color::cmyk() // "cmyk(0.72, 0.88, 0.00, 0.06)"
     * @endcode
     */
    static std::string cmyk();

    /**
     * @brief Return a LAB color
     *
     * @returns LAB color formatted with lab(X,X,X)
     * @code
     * Color::lab() // "lab(98.74, 2.18, -2.35)"
     * @endcode
     */
    static std::string lab();

    /**
     * @brief Return a HSB color
     *
     * @returns HSB color formatted with hsb(X,X,X)
     * @code
     * Color::hsb() // "hsb(37, 82, 50)"
     * @endcode
     */
    static std::string hsb();

    /**
     * @brief Return a HSV color
     *
     * @returns HSV color formatted with hsv(X,X,X)
     * @code
     * Color::hsv() // "hsv(21, 67, 39)"
     * @endcode
     */
    static std::string hsv();

    /**
     * @brief Return a YUV color
     *
     * @returns YUV color formatted with yuv(X,X,X)
     * @code
     * Color::yuv() // "yuv(42, 234, 109)"
     * @endcode
     */
    static std::string yuv();
};
}
