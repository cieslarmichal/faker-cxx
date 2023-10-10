#pragma once

#include <string>

namespace faker
{
class Sport
{
public:
    /**
     * @brief Returns a random sport.
     *
     * @returns sport.
     *
     * @code
     * Sport::sport() // "football"
     * @endcode
     */
    static std::string sport();

    /**
     * @brief Returns a random soccer team.
     *
     * @returns soccer team.
     *
     * @code
     * Sport::soccerTeam() // "Manchester United"
     * @endcode
     */
    static std::string soccerTeam();

    /**
     * @brief Returns a random male athlete.
     *
     * @returns male athlete.
     *
     * @code
     * Sport::maleAthlete() // "Cristiano Ronaldo"
     * @endcode
     */
    static std::string maleAthlete();

    /**
     * @brief Returns a random female athlete.
     *
     * @returns female athlete.
     *
     * @code
     * Sport::femaleAthlete() // "Serena Williams"
     * @endcode
     */
    static std::string femaleAthlete();

    /**
     * @brief Returns a random Sport Event.
     *
     * @returns Sport Event.
     *
     * @code
     * Sport::sportEvent() // "Super Bowl"
     * @endcode
     */
    static std::string sportEvent();
};
}