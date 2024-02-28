#ifndef FAKER_MODULES_AIRLINE_DATA_H
#define FAKER_MODULES_AIRLINE_DATA_H

#include <array>
#include <faker/airline.h>
#include <unordered_map>

namespace faker::airline::data {
extern const std::array<std::string_view, 3> aircraft_types;
extern const std::array<airline_info, 125> airlines;
extern const std::array<airplane_info, 155> airplanes;
extern const std::array<airport_info, 119> airports;
extern const std::unordered_map<aircraft_type, int> aircraft_type_max_rows;
extern const std::unordered_map<aircraft_type, std::string_view> aircraft_type_seat_letters;
}

#endif