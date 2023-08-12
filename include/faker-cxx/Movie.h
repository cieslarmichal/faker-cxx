#pragma once

#include <string>

namespace faker
{
class Movie
{
public:
    /**
     * @brief Returns a random movie genre.
     *
     * @returns Movie genre.
     *
     * @code
     * Movie::genre() // "Drama"
     * @endcode
     */
    static std::string genre();

    /**
     * @brief Returns a random movie title.
     *
     * @returns Movie title.
     *
     * @code
     * Movie::movieTitle() // "Pulp Fiction"
     * @endcode
     */
    static std::string movieTitle();

    /**
     * @brief Returns a random movie director name.
     *
     * @returns Movie director name.
     *
     * @code
     * Movie::director() // "Quentin Tarantino"
     * @endcode
     */
    static std::string director();

    /**
     * @brief Returns a random actor name.
     *
     * @returns Actor name.
     *
     * @code
     * Movie::actor() // "John Travolta"
     * @endcode
     */
    static std::string actor();

    /**
     * @brief Returns a random actress name.
     *
     * @returns Actress name.
     *
     * @code
     * Movie::actress() // "Scarlett Johansson"
     * @endcode
     */
    static std::string actress();
};
}
