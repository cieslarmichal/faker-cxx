#pragma once

#include <string_view>

namespace faker::book
{
/**
 * @brief Returns a random book title.
 *
 * @returns Book title.
 *
 * @code
 * book::title() // "Romeo and Juliet"
 * @endcode
 */
std::string_view title();

/**
 * @brief Returns a random book genre.
 *
 * @returns Book genre.
 *
 * @code
 * book::genre() // "Fantasy"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random book author.
 *
 * @returns Book author.
 *
 * @code
 * book::author() // "William Shakespeare"
 * @endcode
 */
std::string_view author();

/**
 * @brief Returns a random book publisher.
 *
 * @returns Book publisher.
 *
 * @code
 * book::publisher() // "Addison-Wesley"
 * @endcode
 */
std::string_view publisher();

/**
 * @brief Returns format of book
 *
 * @returns BookFormat format of book
 *
 * @code
 * book::format() // "Paperback"
 * @endcode
 */
std::string_view format();

/**
 * @brief returns a random book series
 *
 * @returns std::string_view book series
 *
 * @code
 * book::series() // "Harry Potter"
 * @endcode
 */
std::string_view series();
}
