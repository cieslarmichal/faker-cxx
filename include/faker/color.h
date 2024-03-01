#ifndef FAKER_COLOR_H
#define FAKER_COLOR_H

#include <faker/types/hex.h>
#include <string>

namespace faker::color {
/**
 * @brief Returns a random color.
 *
 * @returns Human readable color name.
 *
 * @code
 * color::name() // "Blue"
 * @endcode
 */
std::string_view name();

/**
 * @brief Returns an RGB color.
 *
 * @param include_alpha Adds an alpha value to the color (RGBA). Defaults to `false`.
 *
 * @returns RGB color formatted with rgb(X,X,X) or rgba(X,X,X,X).
 *
 * @code
 * color::rgb() // "rgb(67, 28, 240)"
 * color::rgb(true) // "rgba(220, 28, 79, 0.50)"
 * @endcode
 */
std::string rgb(bool include_alpha = false);

/**
 * @brief Returns a hex color.
 *
 * @param casing Casing of the generated string. Defaults to `hex_case::lower`.
 * @param prefix Prefix for the generated string. Defaults to `hex_prefix_t::zero_x`.
 * @param include_alpha Adds an alpha value to the color. Defaults to `false`.
 *
 * @returns Hex color formatted that starts with `0x` or `#`.
 *
 * @code
 * color::hex() // "#e3f380"
 * color::hex(hex_case_t::upper, hex_prefix_t::zero_x, true) // "0xE3F3801A"
 * @endcode
 */
std::string hex(hex_case_t casing = hex_case_t::lower, hex_prefix_t prefix = hex_prefix_t::hash,
    bool include_alpha = false);

/**
 * @brief Returns an HSL color.
 *
 * @param include_alpha Adds an alpha value to the color (HSLA). Defaults to `false`.
 * @returns HSL color formatted with hsl(X,X,X) or hsla(X,X,X,X).
 * @code
 * color::hsl() // "hsl(0, 20, 100)"
 * color::hsl(true) // "hsla(0, 0, 100, 0.50)"
 * @endcode
 */
std::string hsl(bool include_alpha = false);

/**
 * @brief Returns an LCH color.
 *
 * @param include_alpha Adds an alpha value to the color (LCHA). Defaults to `false`.
 * @returns LCH color formatted with lch(X,X,X) or lcha(X,X,X,X).
 * @code
 * color::lch() // "lch(0, 20, 100)"
 * color::lch(true) // "lcha(0, 0, 100, 0.50)"
 * @endcode
 */
std::string lch(bool include_alpha = false);

/**
 * @brief Return a CMYK color
 *
 * @returns CMYK color formatted with cmyk(X,X,X,X)
 * @code
 * color::cmyk() // "cmyk(0.72, 0.88, 0.00, 0.06)"
 * @endcode
 */
std::string cmyk();

/**
 * @brief Return a LAB color
 *
 * @returns LAB color formatted with lab(X,X,X)
 * @code
 * color::lab() // "lab(98.74, 2.18, -2.35)"
 * @endcode
 */
std::string lab();

/**
 * @brief Return a HSB color
 *
 * @returns HSB color formatted with hsb(X,X,X)
 * @code
 * color::hsb() // "hsb(37, 82, 50)"
 * @endcode
 */
std::string hsb();

/**
 * @brief Return a HSV color
 *
 * @returns HSV color formatted with hsv(X,X,X)
 * @code
 * color::hsv() // "hsv(21, 67, 39)"
 * @endcode
 */
std::string hsv();

/**
 * @brief Return a YUV color
 *
 * @returns YUV color formatted with yuv(X,X,X)
 * @code
 * color::yuv() // "yuv(42, 234, 109)"
 * @endcode
 */
std::string yuv();
}

#endif