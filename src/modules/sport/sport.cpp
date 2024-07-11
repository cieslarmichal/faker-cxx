#include "faker-cxx/sport.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "sport_data.h"

namespace faker::sport
{
std::string_view sportName()
{
    return helper::arrayElement(sportNames);
}

std::string_view soccerTeam()
{
    return helper::arrayElement(soccerTeams);
}

std::string_view maleAthlete()
{
    return helper::arrayElement(maleAthletes);
}

std::string_view femaleAthlete()
{
    return helper::arrayElement(femaleAthletes);
}

std::string_view sportEvent()
{
    return helper::arrayElement(sportEvents);
}
}
