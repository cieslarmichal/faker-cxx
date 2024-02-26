#include "../common/helper.h"
#include "sport_data.h"
#include <faker/sport.h>

namespace faker::sport {
std::string_view sport() { return Helper::arrayElement(data::sportNames); }

std::string_view soccer_team() { return Helper::arrayElement(data::soccerTeams); }

std::string_view male_athlete() { return Helper::arrayElement(data::maleAthletes); }

std::string_view female_athlete() { return Helper::arrayElement(data::femaleAthletes); }

std::string_view sport_event() { return Helper::arrayElement(data::sportEvents); }
}
