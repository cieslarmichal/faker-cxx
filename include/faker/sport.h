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
 * sport::soccer_team() // "Manchester United"
 * @endcode
 */
std::string_view soccer_team();

/**
 * @brief Returns a random male athlete.
 *
 * @returns male athlete.
 *
 * @code
 * sport::male_athlete() // "Cristiano Ronaldo"
 * @endcode
 */
std::string_view male_athlete();

/**
 * @brief Returns a random female athlete.
 *
 * @returns female athlete.
 *
 * @code
 * sport::female_athlete() // "Serena Williams"
 * @endcode
 */
std::string_view female_athlete();

/**
 * @brief Returns a random sport Event.
 *
 * @returns sport Event.
 *
 * @code
 * sport::sport_event() // "Super Bowl"
 * @endcode
 */
std::string_view sport_event();
}

#endif