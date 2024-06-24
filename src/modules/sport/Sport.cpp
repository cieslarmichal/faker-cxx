#include "faker-cxx/Sport.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "SportData.h"

namespace faker::Sport
{
std::string_view sport()
{
    return Helper::arrayElement(sportNames);
}

std::string_view soccerTeam()
{
    return Helper::arrayElement(soccerTeams);
}

std::string_view maleAthlete()
{
    return Helper::arrayElement(maleAthletes);
}

std::string_view femaleAthlete()
{
    return Helper::arrayElement(femaleAthletes);
}

std::string_view sportEvent()
{
    return Helper::arrayElement(sportEvents);
}
}
