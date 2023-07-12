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
    static std::string name();

    /**
     * @brief Returns an RGB color.
     *
     * @param includeAlpha Adds an alpha value to the color (RGBA). Defaults to `false`.
     *
     * @returns RGB color formatted with rgb(X,X,X) or rgba(X,X,X,X).
     *
     * @code
     * Color::rgb() // 'rgb(67, 28, 240)'
     * Color::rgb(true) // 'rgba(220, 28, 79, 0.50)'
     * @endcode
     */
    static std::string rgb(bool includeAlpha = false);

    /**
     * @brief Returns a hex color.
     *
     * @param casing Casing of the generated string. Defaults to `'Lower'`.
     * @param prefix Prefix for the generated string. Defaults to `'0x'
     * @param includeAlpha Adds an alpha value to the color. Defaults to `false`.
     *
     * @returns Hex color formatted that starts with '0x' or '#'.
     *
     * @code
     * String::hex() // "#e3f380"
     * String::hex(HexCasing::Upper, HexPrefix::ZeroX, true) // "0xE3F3801A"
     * @endcode
     */
    static std::string hex(HexCasing casing = HexCasing::Lower, HexPrefix prefix = HexPrefix::Hash,
                           bool includeAlpha = false);
};
}
