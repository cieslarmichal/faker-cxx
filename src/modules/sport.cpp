#include "faker-cxx/sport.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "sport_data.h"

namespace faker::sport
{
std::string_view sportName()
{
    return helper::randomElement(sportNames);
}

std::string_view soccerTeam()
{
    return helper::randomElement(soccerTeams);
}

std::string_view maleAthlete()
{
    return helper::randomElement(maleAthletes);
}

std::string_view femaleAthlete()
{
    return helper::randomElement(femaleAthletes);
}

std::string_view sportEvent()
{
    return helper::randomElement(sportEvents);
}
}
