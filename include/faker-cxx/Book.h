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
