#ifndef FAKER_MODULES_SPORT_DATA_H
#define FAKER_MODULES_SPORT_DATA_H

#include <array>
#include <string_view>

namespace faker::sport::data {
extern const std::array<std::string_view, 10> femaleAthletes;
extern const std::array<std::string_view, 10> maleAthletes;
extern const std::array<std::string_view, 10> soccerTeams;
extern const std::array<std::string_view, 10> sportEvents;
extern const std::array<std::string_view, 10> sportNames;
}

#endif