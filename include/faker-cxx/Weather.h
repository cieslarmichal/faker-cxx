#pragma once

#include <string_view>

namespace faker::weather
{
/**
 * @brief Generated a random weather description
 *
 * @return A random weather description
 *
 * @code
 * weather::weatherDescription(); // "Sunny"
 * @endcode
 */
std::string_view weatherDescription();
}
