#include "faker-cxx/Sport.h"

#include <string>

#include "data/FemaleAthletes.h"
#include "data/MaleAthletes.h"
#include "data/SoccerTeams.h"
#include "data/SportEvents.h"
#include "data/SportNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Sport::sport()
{
    return Helper::arrayElement<std::string>(sportNames);
}

std::string Sport::soccerTeam()
{
    return Helper::arrayElement<std::string>(soccerTeams);
}

std::string Sport::maleAthlete()
{
    return Helper::arrayElement<std::string>(maleAthletes);
}

std::string Sport::femaleAthlete()
{
    return Helper::arrayElement<std::string>(femaleAthletes);
}

std::string Sport::sportEvent()
{
    return Helper::arrayElement<std::string>(sportEvents);
}
}
