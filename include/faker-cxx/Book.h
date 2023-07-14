#pragma once

#include <string>

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
    static std::string title();

    /**
     * @brief Returns a random book genre.
     *
     * @returns Book genre.
     *
     * @code
     * Book::genre() // "Fantasy"
     * @endcode
     */
    static std::string genre();

    /**
     * @brief Returns a random book author.
     *
     * @returns Book author.
     *
     * @code
     * Book::author() // "Shakespeare, William"
     * @endcode
     */
    static std::string author();

    /**
     * @brief Returns a random book publisher.
     *
     * @returns Book publisher.
     *
     * @code
     * Book::publisher() // "Addison-Wesley"
     * @endcode
     */
    static std::string publisher();

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
};
}
