#include "sport_data.h"
#include <faker/helper.h>
#include <faker/sport.h>

namespace faker::sport {
std::string sport() { return Helper::arrayElement<std::string>(sportNames); }

std::string soccerTeam() { return Helper::arrayElement<std::string>(soccerTeams); }

std::string maleAthlete() { return Helper::arrayElement<std::string>(maleAthletes); }

std::string femaleAthlete() { return Helper::arrayElement<std::string>(femaleAthletes); }

std::string sportEvent() { return Helper::arrayElement<std::string>(sportEvents); }
}
