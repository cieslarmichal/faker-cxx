#pragma once

#include <string_view>
#include "faker-cxx/export.h"

namespace faker::weather
{
/**
 * @brief Generated a random weather description
 *
 * @return A random weather description
 *
 * @code
 * faker::weather::weatherDescription(); // "Sunny"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view weatherDescription();
}
