#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::education
{
/**
 * @brief Returns a random school name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return School name.
 *
 * @code
 * faker::education::school() // "Harvard University"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view school(Locale locale = Locale::en_US);

/**
 * @brief Returns a random degree type (e.g., BSc, MBA).
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Degree type.
 *
 * @code
 * faker::education::degree() // "BSc"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view degree(Locale locale = Locale::en_US);

/**
 * @brief Returns a random field of study (e.g., Computer Science, Business).
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Field of study.
 *
 * @code
 * faker::education::field() // "Computer Science"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view field(Locale locale = Locale::en_US);

/**
 * @brief Returns a random academic term (e.g., Semester, GPA).
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Academic term.
 *
 * @code
 * faker::education::term() // "Semester"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view term(Locale locale = Locale::en_US);

/**
 * @brief Returns a random list of courses.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return List of courses.
 *
 * @code
 * faker::education::courses() // "Math 101, Computer Science 201"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view courses(Locale locale = Locale::en_US);

} // namespace faker::education
