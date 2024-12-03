#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::music
{
/**
 * @brief Returns a random artist.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Artist.
 *
 * @code
 * faker::music::artist() // "Nirvana"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view artist(Locale locale = Locale::en_US);

/**
 * @brief Returns a random music genre.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Music genre.
 *
 * @code
 * faker::music::genre() // "Rock"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view genre(Locale locale = Locale::en_US);

/**
 * @brief Returns a random song name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Song name.
 *
 * @code
 * faker::music::songName() // "Light My Fire"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view songName(Locale locale = Locale::en_US);
}
