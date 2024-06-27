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
     * faker::sport::sport() // "football"
     * @endcode
     */
    
    std::string_view sportName();

    /**
     * @brief Returns a random soccer team.
     *
     * @returns soccer team.
     *
     * @code
     * faker::sport::soccerTeam() // "Manchester United"
     * @endcode
     */
    std::string_view soccerTeam();

    /**
     * @brief Returns a random male athlete.
     *
     * @returns male athlete.
     *
     * @code
     * faker::sport::maleAthlete() // "Cristiano Ronaldo"
     * @endcode
     */
    std::string_view maleAthlete();

    /**
     * @brief Returns a random female athlete.
     *
     * @returns female athlete.
     *
     * @code
     * faker::sport::femaleAthlete() // "Serena Williams"
     * @endcode
     */
    std::string_view femaleAthlete();

    /**
     * @brief Returns a random Sport Event.
     *
     * @returns Sport Event.
     *
     * @code
     * faker::sport::sportEvent() // "Super Bowl"
     * @endcode
     */
    std::string_view sportEvent();
}
