#pragma once

#include <string>

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
};
}
