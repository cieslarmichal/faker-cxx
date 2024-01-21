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

	/**
	 * @brief Returns a random release year
	 *
	 * @returns int year
	 *
	 * @code
	 * Book::releaseYear() // "2016-06-27"
	 * @endcode
	 */
	static std::string releaseYear();

	/**
	 * @brief Returns the full name of a translator
	 *
	 * @returns std::string full name
	 *
	 * @code
	 * Book::translator() // "Eric Floyd"
	 * @endcode
	 */
	static std::string translator();
	
	enum class BookFormat {
		Paperback,
		Hardcover,
		Kindle,
		// Add more formats if needed
	};
	
	/**
	 * @brief Returns format of book
	 *
	 * @returns BookFormat format of book
	 *
	 * @code
	 * Book::format() // BookFormat::paperback
	 * @endcode
	 */
	static BookFormat format();

	/*
	 * @brief returns a random page number (50-999)
	 *
	 * @returns int page number
	 *
	 * @code
	 * Book::page() // 314
	 * @endcode
	 */
	static int page();

	/*
	 * @brief returns a random book series
	 *
	 * @returns std::string book series
	 *
	 * @code
	 * Book::series() // "Harry Potter"
	 * @endcode
	 */
	static std::string series();
};
}

