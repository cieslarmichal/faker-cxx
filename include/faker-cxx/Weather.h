#pragma once

#include <string_view>

namespace faker
{
class Weather
{
public:
    /**
     * @brief Generated a random weather description
     *
     * @return String_View A random weather description
     *
     * @code
     * Weather::description(); // "Sunny"
     * @endcode
     */
    static std::string_view weatherDescription();
};
}
