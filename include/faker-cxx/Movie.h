#pragma once

#include <string_view>

namespace faker::movie
{
/**
 * @brief Returns a random movie genre.
 *
 * @returns Movie genre.
 *
 * @code
 * movie::genre() // "Drama"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random movie title.
 *
 * @returns Movie title.
 *
 * @code
 * movie::movieTitle() // "Pulp Fiction"
 * @endcode
 */
std::string_view movieTitle();

/**
 * @brief Returns a random tv show.
 *
 * @returns Tv show.
 *
 * @code
 * movie::tvShow() // "The Sopranos"
 * @endcode
 */
std::string_view tvShow();

/**
 * @brief Returns a random movie director name.
 *
 * @returns Movie director name.
 *
 * @code
 * movie::director() // "Quentin Tarantino"
 * @endcode
 */
std::string_view director();

/**
 * @brief Returns a random actor name.
 *
 * @returns Actor name.
 *
 * @code
 * movie::actor() // "John Travolta"
 * @endcode
 */
std::string_view actor();

/**
 * @brief Returns a random actress name.
 *
 * @returns Actress name.
 *
 * @code
 * movie::actress() // "Scarlett Johansson"
 * @endcode
 */
std::string_view actress();
}
