#ifndef FAKER_MOVIE_H
#define FAKER_MOVIE_H

#include <string_view>

namespace faker::movie {
/**
 * @brief Returns a random movie genre.
 *
 * @returns movie genre.
 *
 * @code
 * movie::genre() // "Drama"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random movie title.
 *
 * @returns movie title.
 *
 * @code
 * movie::movie_title() // "Pulp Fiction"
 * @endcode
 */
std::string_view movie_title();

/**
 * @brief Returns a random tv show.
 *
 * @returns Tv show.
 *
 * @code
 * movie::tv_show() // "The Sopranos"
 * @endcode
 */
std::string_view tv_show();

/**
 * @brief Returns a random movie director name.
 *
 * @returns movie director name.
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

#endif