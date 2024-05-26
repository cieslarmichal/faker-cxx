#include "faker-cxx/Sport.h"

#include <string_view>

#include "data/FemaleAthletes.h"
#include "data/MaleAthletes.h"
#include "data/SoccerTeams.h"
#include "data/SportEvents.h"
#include "data/SportNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Sport::sport()
{
    return Helper::arrayElement(sportNames);
}

std::string_view Sport::soccerTeam()
{
    return Helper::arrayElement(soccerTeams);
}

std::string_view Sport::maleAthlete()
{
    return Helper::arrayElement(maleAthletes);
}

std::string_view Sport::femaleAthlete()
{
    return Helper::arrayElement(femaleAthletes);
}

std::string_view Sport::sportEvent()
{
    return Helper::arrayElement(sportEvents);
}
}
