#pragma once

#include <string_view>

#include "faker-cxx/export.h"

namespace faker::sport
{
/**
 * @brief Returns a random sport.
 *
 * @returns Sport.
 *
 * @code
 * faker::sport::sport() // "football"
 * @endcode
 */

FAKER_CXX_EXPORT std::string_view sportName();

/**
 * @brief Returns a random soccer team.
 *
 * @returns Coccer team.
 *
 * @code
 * faker::sport::soccerTeam() // "Manchester United"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view soccerTeam();

/**
 * @brief Returns a random male athlete.
 *
 * @returns Male athlete.
 *
 * @code
 * faker::sport::maleAthlete() // "Cristiano Ronaldo"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view maleAthlete();

/**
 * @brief Returns a random female athlete.
 *
 * @returns Female athlete.
 *
 * @code
 * faker::sport::femaleAthlete() // "Serena Williams"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view femaleAthlete();

/**
 * @brief Returns a random Sport Event.
 *
 * @returns Sport Event.
 *
 * @code
 * faker::sport::sportEvent() // "Super Bowl"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sportEvent();
}
