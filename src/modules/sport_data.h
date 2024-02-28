#ifndef FAKER_MODULES_SPORT_DATA_H
#define FAKER_MODULES_SPORT_DATA_H

#include <array>
#include <string_view>

namespace faker::sport::data {
extern const std::array<std::string_view, 10> female_athletes;
extern const std::array<std::string_view, 10> male_athletes;
extern const std::array<std::string_view, 10> soccer_teams;
extern const std::array<std::string_view, 10> sport_events;
extern const std::array<std::string_view, 10> sport_names;
}

#endif