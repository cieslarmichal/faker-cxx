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
     * @returns Human readable color name
     *
     * @code
     * Color::name() // "Blue"
     * @endcode
     */
    static std::string name();
};
}
