#ifndef FAKER_BOOK_H
#define FAKER_BOOK_H

#include <string>

namespace faker::book {
/**
 * @brief Returns a random book title.
 *
 * @returns book title.
 *
 * @code
 * book::title() // "Romeo and Juliet"
 * @endcode
 */
std::string_view title();

/**
 * @brief Returns a random book genre.
 *
 * @returns book genre.
 *
 * @code
 * book::genre() // "Fantasy"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random book author.
 *
 * @returns book author.
 *
 * @code
 * book::author() // "Shakespeare, William"
 * @endcode
 */
std::string_view author();

/**
 * @brief Returns a random book publisher.
 *
 * @returns book publisher.
 *
 * @code
 * book::publisher() // "Addison-Wesley"
 * @endcode
 */
std::string_view publisher();

/**
 * @brief Returns a random book ISBN.
 *
 * @returns book ISBN.
 *
 * @code
 * book::isbn() // "978-83-01-00000-1"
 * @endcode
 */
std::string isbn();

/**
 * @brief Returns a random release year
 *
 * @returns int year
 *
 * @code
 * book::releaseYear() // 2016
 * @endcode
 */
int releaseYear();

/**
 * @brief Returns the full name of a translator
 *
 * @returns std::string full name
 *
 * @code
 * book::translator() // "Eric Floyd"
 * @endcode
 */
std::string_view translator();

/**
 * @brief Returns format of book
 *
 * @returns BookFormat format of book
 *
 * @code
 * book::format() // BookFormat::paperback
 * @endcode
 */
std::string_view format();

/*
 * @brief returns a random page number (50-999)
 *
 * @returns int page number
 *
 * @code
 * book::page() // 314
 * @endcode
 */
int page();

/*
 * @brief returns a random book series
 *
 * @returns std::string book series
 *
 * @code
 * book::series() // "Harry Potter"
 * @endcode
 */
std::string_view series();
}

#endif