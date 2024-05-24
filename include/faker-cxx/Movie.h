#pragma once

#include <string_view>

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
    static std::string_view genre();

    /**
     * @brief Returns a random movie title.
     *
     * @returns Movie title.
     *
     * @code
     * Movie::movieTitle() // "Pulp Fiction"
     * @endcode
     */
    static std::string_view movieTitle();

    /**
     * @brief Returns a random tv show.
     *
     * @returns Tv show.
     *
     * @code
     * Movie::tvShow() // "The Sopranos"
     * @endcode
     */
    static std::string_view tvShow();

    /**
     * @brief Returns a random movie director name.
     *
     * @returns Movie director name.
     *
     * @code
     * Movie::director() // "Quentin Tarantino"
     * @endcode
     */
    static std::string_view director();

    /**
     * @brief Returns a random actor name.
     *
     * @returns Actor name.
     *
     * @code
     * Movie::actor() // "John Travolta"
     * @endcode
     */
    static std::string_view actor();

    /**
     * @brief Returns a random actress name.
     *
     * @returns Actress name.
     *
     * @code
     * Movie::actress() // "Scarlett Johansson"
     * @endcode
     */
    static std::string_view actress();
};
}
