#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::weather
{
/**
 * @brief Generated a random weather description.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return A random weather description.
 *
 * @code
 * faker::weather::weatherDescription(Locale::en_GB); // "Sunny"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view weatherDescription(Locale locale = Locale::en_US);
}
