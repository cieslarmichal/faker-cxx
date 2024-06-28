#pragma once

#include <string_view>
#include "faker-cxx/Export.h"

namespace faker::medicine
{
/**
 * @brief Returns a random medical condition.
 *
 * @returns Medical condition.
 *
 * @code
 * faker::medicine::condition() // "AIDS"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view condition();

/**
 * @brief Returns a random medical test
 *
 * @returns Medical test.
 *
 * @code
 * faker::medicine::medicalTest() // "pulmonary auscultation"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view medicalTest();

/**
 * @brief Returns a random Medical specialty
 *
 * @returns Medical specialty.
 *
 * @code
 * faker::medicine::specialty() // "Cardiology"
 * @endcode
 */

FAKER_CXX_EXPORT std::string_view specialty();
}
