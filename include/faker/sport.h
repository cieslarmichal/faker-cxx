#pragma once

#include <string>

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
std::string sport();

/**
 * @brief Returns a random soccer team.
 *
 * @returns soccer team.
 *
 * @code
 * sport::soccerTeam() // "Manchester United"
 * @endcode
 */
std::string soccerTeam();

/**
 * @brief Returns a random male athlete.
 *
 * @returns male athlete.
 *
 * @code
 * sport::maleAthlete() // "Cristiano Ronaldo"
 * @endcode
 */
std::string maleAthlete();

/**
 * @brief Returns a random female athlete.
 *
 * @returns female athlete.
 *
 * @code
 * sport::femaleAthlete() // "Serena Williams"
 * @endcode
 */
std::string femaleAthlete();

/**
 * @brief Returns a random sport Event.
 *
 * @returns sport Event.
 *
 * @code
 * sport::sportEvent() // "Super Bowl"
 * @endcode
 */
std::string sportEvent();
}