#pragma once

#include <string_view>

namespace faker
{
class Book
{
public:
    /**
     * @brief Returns a random book title.
     *
     * @returns Book title.
     *
     * @code
     * Book::title() // "Romeo and Juliet"
     * @endcode
     */
    static std::string_view title();

    /**
     * @brief Returns a random book genre.
     *
     * @returns Book genre.
     *
     * @code
     * Book::genre() // "Fantasy"
     * @endcode
     */
    static std::string_view genre();

    /**
     * @brief Returns a random book author.
     *
     * @returns Book author.
     *
     * @code
     * Book::author() // "Shakespeare, William"
     * @endcode
     */
    static std::string_view author();

    /**
     * @brief Returns a random book publisher.
     *
     * @returns Book publisher.
     *
     * @code
     * Book::publisher() // "Addison-Wesley"
     * @endcode
     */
    static std::string_view publisher();

    /**
     * @brief Returns a random book ISBN.
     *
     * @returns Book ISBN.
     *
     * @code
     * Book::isbn() // "978-83-01-00000-1"
     * @endcode
     */
    static std::string isbn();

    /**
     * @brief Returns the full name of a translator
     *
     * @returns std::string_view full name
     *
     * @code
     * Book::translator() // "Eric Floyd"
     * @endcode
     */
    static std::string_view translator();

    /**
     * @brief Returns format of book
     *
     * @returns BookFormat format of book
     *
     * @code
     * Book::format() // BookFormat::paperback
     * @endcode
     */
    static std::string_view format();

    /**
     * @brief returns a random book series
     *
     * @returns std::string_view book series
     *
     * @code
     * Book::series() // "Harry Potter"
     * @endcode
     */
    static std::string_view series();
};
}
