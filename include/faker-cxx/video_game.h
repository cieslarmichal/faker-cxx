#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::videogame
{
/**
 * @brief Returns a random video game name.
 * 
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Video game name.
 *
 * @code
 * faker::videogame::gameTitle() // "Rayman Arena"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gameTitle(Locale locale = Locale::en_US);

/**
 * @brief Returns a random video game genre.
 * 
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Video game genre.
 *
 * @code
 * faker::videogame::genre() // "Platformer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view genre(Locale locale = Locale::en_US);

/**
 * @brief Returns a random video game platform.
 * 
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Platform.
 *
 * @code
 * faker::videogame::platform() // "Playstation 5"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view platform(Locale locale = Locale::en_US);

/**
 * @brief Returns a random video game studio name.
 * 
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Studio name.
 *
 * @code
 * faker::videogame::studioName() // "Activision Blizzard"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view studioName(Locale locale = Locale::en_US);
}
