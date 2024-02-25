#ifndef FAKER_SPORT_H
#define FAKER_SPORT_H

#include <string_view>

namespace faker::sport {
/**
 * @brief Returns a random sport.
 *
 * @returns sport.
 *
 * @code
 * sport::sport() // "football"
 * @endcode
 */
std::string_view sport();

/**
 * @brief Returns a random soccer team.
 *
 * @returns soccer team.
 *
 * @code
 * sport::soccerTeam() // "Manchester United"
 * @endcode
 */
std::string_view soccerTeam();

/**
 * @brief Returns a random male athlete.
 *
 * @returns male athlete.
 *
 * @code
 * sport::maleAthlete() // "Cristiano Ronaldo"
 * @endcode
 */
std::string_view maleAthlete();

/**
 * @brief Returns a random female athlete.
 *
 * @returns female athlete.
 *
 * @code
 * sport::femaleAthlete() // "Serena Williams"
 * @endcode
 */
std::string_view femaleAthlete();

/**
 * @brief Returns a random sport Event.
 *
 * @returns sport Event.
 *
 * @code
 * sport::sportEvent() // "Super Bowl"
 * @endcode
 */
std::string_view sportEvent();
}

#endif