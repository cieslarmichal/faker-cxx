#include "../common/random.h"
#include "sport_data.h"
#include <faker/sport.h>

namespace faker::sport {
std::string_view sport() { return random::element(data::sport_names); }

std::string_view soccer_team() { return random::element(data::soccer_teams); }

std::string_view male_athlete() { return random::element(data::male_athletes); }

std::string_view female_athlete() { return random::element(data::female_athletes); }

std::string_view sport_event() { return random::element(data::sport_events); }
}
