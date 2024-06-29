#pragma once

#include <string_view>
#include "faker-cxx/Export.h"

namespace faker::book
{
/**
 * @brief Returns a random book title.
 *
 * @returns Book title.
 *
 * @code
 * faker::book::title() // "Romeo and Juliet"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view title();

/**
 * @brief Returns a random book genre.
 *
 * @returns Book genre.
 *
 * @code
 * faker::book::genre() // "Fantasy"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view genre();

/**
 * @brief Returns a random book author.
 *
 * @returns Book author.
 *
 * @code
 * faker::book::author() // "William Shakespeare"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view author();

/**
 * @brief Returns a random book publisher.
 *
 * @returns Book publisher.
 *
 * @code
 * faker::book::publisher() // "Addison-Wesley"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view publisher();

/**
 * @brief Returns format of book
 *
 * @returns BookFormat format of book
 *
 * @code
 * faker::book::format() // "Paperback"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view format();

/**
 * @brief returns a random book series
 *
 * @returns std::string_view book series
 *
 * @code
 * faker::book::series() // "Harry Potter"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view series();
}
