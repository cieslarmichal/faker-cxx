#ifndef FAKER_MEDICINE_H
#define FAKER_MEDICINE_H

#include <string_view>

namespace faker::medicine {
/**
 * @brief Returns a random medical condition.
 *
 * @returns Medical condition.
 *
 * @code
 * medicine::condition() // "AIDS"
 * @endcode
 */
std::string_view condition();

/**
 * @brief Returns a random medical test
 *
 * @returns Medical test.
 *
 * @code
 * medicine::medical_test() // "pulmonary auscultation"
 * @endcode
 */
std::string_view medical_test();

/**
 * @brief Returns a random Medical specialty
 *
 * @returns Medical specialty.
 *
 * @code
 * medicine::specialty() // "Cardiology"
 * @endcode
 */

std::string_view specialty();
}

#endif