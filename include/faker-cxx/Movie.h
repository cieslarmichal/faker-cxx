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
 * faker::movie::genre() // "Drama"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random movie title.
 *
 * @returns Movie title.
 *
 * @code
 * faker::movie::movieTitle() // "Pulp Fiction"
 * @endcode
 */
std::string_view movieTitle();

/**
 * @brief Returns a random tv show.
 *
 * @returns Tv show.
 *
 * @code
 * faker::movie::tvShow() // "The Sopranos"
 * @endcode
 */
std::string_view tvShow();

/**
 * @brief Returns a random movie director name.
 *
 * @returns Movie director name.
 *
 * @code
 * faker::movie::director() // "Quentin Tarantino"
 * @endcode
 */
std::string_view director();

/**
 * @brief Returns a random actor name.
 *
 * @returns Actor name.
 *
 * @code
 * faker::movie::actor() // "John Travolta"
 * @endcode
 */
std::string_view actor();

/**
 * @brief Returns a random actress name.
 *
 * @returns Actress name.
 *
 * @code
 * faker::movie::actress() // "Scarlett Johansson"
 * @endcode
 */
std::string_view actress();
}
