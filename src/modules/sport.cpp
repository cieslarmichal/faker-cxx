#include "../common/helper.h"
#include "sport_data.h"
#include <faker/sport.h>

namespace faker::sport {
std::string_view sport() { return Helper::arrayElement(data::sportNames); }

std::string_view soccerTeam() { return Helper::arrayElement(data::soccerTeams); }

std::string_view maleAthlete() { return Helper::arrayElement(data::maleAthletes); }

std::string_view femaleAthlete() { return Helper::arrayElement(data::femaleAthletes); }

std::string_view sportEvent() { return Helper::arrayElement(data::sportEvents); }
}
