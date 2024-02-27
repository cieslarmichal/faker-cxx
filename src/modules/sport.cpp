#include "../common/random.h"
#include "sport_data.h"
#include <faker/sport.h>

namespace faker::sport {
std::string_view sport() { return random::element(data::sportNames); }

std::string_view soccer_team() { return random::element(data::soccerTeams); }

std::string_view male_athlete() { return random::element(data::maleAthletes); }

std::string_view female_athlete() { return random::element(data::femaleAthletes); }

std::string_view sport_event() { return random::element(data::sportEvents); }
}
