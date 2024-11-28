#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::medicine
{
/**
 * @brief Returns a random medical condition.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Medical condition.
 *
 * @code
 * faker::medicine::condition() // "AIDS"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view condition(Locale locale = Locale::en_US);

/**
 * @brief Returns a random medical test
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Medical test.
 *
 * @code
 * faker::medicine::medicalTest() // "pulmonary auscultation"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view medicalTest(Locale locale = Locale::en_US);

/**
 * @brief Returns a random Medical specialty
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Medical specialty.
 *
 * @code
 * faker::medicine::specialty() // "Cardiology"
 * @endcode
 */

FAKER_CXX_EXPORT std::string_view specialty(Locale locale = Locale::en_US);
}
