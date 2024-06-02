#include "faker-cxx/Sport.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "SportData.h"

namespace faker
{
std::string_view Sport::sport()
{
    return Helper::arrayElement(sport::sportNames);
}

std::string_view Sport::soccerTeam()
{
    return Helper::arrayElement(sport::soccerTeams);
}

std::string_view Sport::maleAthlete()
{
    return Helper::arrayElement(sport::maleAthletes);
}

std::string_view Sport::femaleAthlete()
{
    return Helper::arrayElement(sport::femaleAthletes);
}

std::string_view Sport::sportEvent()
{
    return Helper::arrayElement(sport::sportEvents);
}
}
