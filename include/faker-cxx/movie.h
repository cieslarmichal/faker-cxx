#pragma once

#include <string_view>
#include "faker-cxx/types/locale.h"

#include "faker-cxx/export.h"

namespace faker::movie
{
/**
 * @brief Returns a random movie genre
 * 
 * @brief Returns a random movie genre.
 *
 * @returns Movie genre.
 *
 * @code
 * faker::movie::genre() // "Drama"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view genre(Locale locale = Locale::en_US);

/**
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @brief Returns a random movie title.
 *
 * @returns Movie title.
 *
 * @code
 * faker::movie::movieTitle() // "Pulp Fiction"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view movieTitle(Locale locale = Locale::en_US);

/**
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @brief Returns a random tv show.
 *
 * @returns Tv show.
 *
 * @code
 * faker::movie::tvShow() // "The Sopranos"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view tvShow(Locale locale = Locale::en_US);

/**
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @brief Returns a random movie director name.
 *
 * @returns Movie director name.
 *
 * @code
 * faker::movie::director() // "Quentin Tarantino"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view director(Locale locale = Locale::en_US);

/**
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @brief Returns a random actor name.
 *
 * @returns Actor name.
 *
 * @code
 * faker::movie::actor() // "John Travolta"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view actor(Locale locale = Locale::en_US);

/**
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @brief Returns a random actress name.
 *
 * @returns Actress name.
 *
 * @code
 * faker::movie::actress() // "Scarlett Johansson"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view actress(Locale locale = Locale::en_US);
}
