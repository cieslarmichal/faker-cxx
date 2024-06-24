#pragma once

#include <string_view>

namespace faker::sport
{
    /**
     * @brief Returns a random sport.
     *
     * @returns sport.
     *
     * @code
     * Sport::sport() // "football"
     * @endcode
     */
    
    std::string_view sportName();

    /**
     * @brief Returns a random soccer team.
     *
     * @returns soccer team.
     *
     * @code
     * Sport::soccerTeam() // "Manchester United"
     * @endcode
     */
    std::string_view soccerTeam();

    /**
     * @brief Returns a random male athlete.
     *
     * @returns male athlete.
     *
     * @code
     * Sport::maleAthlete() // "Cristiano Ronaldo"
     * @endcode
     */
    std::string_view maleAthlete();

    /**
     * @brief Returns a random female athlete.
     *
     * @returns female athlete.
     *
     * @code
     * Sport::femaleAthlete() // "Serena Williams"
     * @endcode
     */
    std::string_view femaleAthlete();

    /**
     * @brief Returns a random Sport Event.
     *
     * @returns Sport Event.
     *
     * @code
     * Sport::sportEvent() // "Super Bowl"
     * @endcode
     */
    std::string_view sportEvent();
}
