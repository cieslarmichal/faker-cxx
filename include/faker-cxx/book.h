#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::book
{
/**
 * @brief Returns a random book title.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Book title.
 *
 * @code
 * faker::book::title() // "Romeo and Juliet"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view title(Locale locale = Locale::en_US);

/**
 * @brief Returns a random book genre.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Book genre.
 *
 * @code
 * faker::book::genre() // "Fantasy"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view genre(Locale locale = Locale::en_US);

/**
 * @brief Returns a random book author.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Book author.
 *
 * @code
 * faker::book::author() // "William Shakespeare"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view author(Locale locale = Locale::en_US);

/**
 * @brief Returns a random book publisher.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Book publisher.
 *
 * @code
 * faker::book::publisher() // "Addison-Wesley"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view publisher(Locale locale = Locale::en_US);

/**
 * @brief Returns format of book
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns BookFormat format of book
 *
 * @code
 * faker::book::format() // "Paperback"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view format(Locale locale = Locale::en_US);

/**
 * @brief returns a random book series
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns std::string_view book series
 *
 * @code
 * faker::book::series() // "Harry Potter"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view series(Locale locale = Locale::en_US);
}
