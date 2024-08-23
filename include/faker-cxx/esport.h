#pragma once

#include <string_view>

#include "faker-cxx/export.h"

namespace faker::esport
{

/**
 * @brief Returns a random player name.
 *
 * @return Player name.
 *
 * @code
 * faker::esport::player() // "Faker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view player();

/**
 * @brief Returns a random esport team.
 *
 * @return Esport team.
 *
 * @code
 * faker::esport::team() // "Karmine Corp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view team();

/**
 * @brief Returns a random esport league.
 *
 * @return Esport League.
 *
 * @code
 * faker::esport::league() // "LEC"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view league();

/**
 * @brief Returns a random esport event.
 *
 * @return Esport Event.
 *
 * @code
 * faker::esport::event() // "Faker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view event();

/**
 * @brief Returns a random competitive video game.
 *
 * @return Competitive video game.
 *
 * @code
 * faker::esport::game() // "Rocket League"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view game();
}