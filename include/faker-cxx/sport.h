#pragma once

#include <string_view>
#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::sport
{
/**
 * @brief Returns a random sport.
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @returns Sport.
 *
 * @code
 * faker::sport::sport() // "football"
 * @endcode
 */

FAKER_CXX_EXPORT std::string_view sportName(Locale locale = Locale::en_US);

/**
 * @brief Returns a random soccer team.
 *
 * @returns Coccer team.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @code
 * faker::sport::soccerTeam() // "Manchester United"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view soccerTeam(Locale locale = Locale::en_US);

/**
 * @brief Returns a random male athlete.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Male athlete.
 *
 * @code
 * faker::sport::maleAthlete() // "Cristiano Ronaldo"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view maleAthlete(Locale locale = Locale::en_US);

/**
 * @brief Returns a random female athlete.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Female athlete.
 *
 * @code
 * faker::sport::femaleAthlete() // "Serena Williams"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view femaleAthlete(Locale locale = Locale::en_US);

/**
 * @brief Returns a random Sport Event.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Sport Event.
 *
 * @code
 * faker::sport::sportEvent() // "Super Bowl"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sportEvent(Locale locale = Locale::en_US);
}
