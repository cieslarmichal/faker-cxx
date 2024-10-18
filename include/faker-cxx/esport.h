#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::esport
{
/**
 * @brief Returns a random player name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Player name.
 *
 * @code
 * faker::esport::player() // "Faker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view player(Locale locale = Locale::en_US);

/**
 * @brief Returns a random esport team.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Esport team.
 *
 * @code
 * faker::esport::team() // "Karmine Corp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view team(Locale locale = Locale::en_US);

/**
 * @brief Returns a random esport league.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Esport League.
 *
 * @code
 * faker::esport::league() // "LEC"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view league(Locale locale = Locale::en_US);

/**
 * @brief Returns a random esport event.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Esport Event.
 *
 * @code
 * faker::esport::event() // "Faker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view event(Locale locale = Locale::en_US);

/**
 * @brief Returns a random competitive video game.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @return Competitive video game.
 *
 * @code
 * faker::esport::game() // "Rocket League"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view game(Locale locale = Locale::en_US);
}
