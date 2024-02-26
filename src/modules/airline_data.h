#ifndef FAKER_MODULES_AIRLINE_DATA_H
#define FAKER_MODULES_AIRLINE_DATA_H

#include <array>
#include <faker/airline.h>
#include <string_view>
#include <unordered_map>

namespace faker::airline::data {
extern const std::array<std::string_view, 3> aircraftTypes;
extern const std::array<AirlineStruct, 125> airlines;
extern const std::array<Airplane, 155> airplanes;
extern const std::array<Airport, 119> airports;
extern const std::unordered_map<AircraftType, int> aircraftTypeMaxRows;
extern const std::unordered_map<AircraftType, std::string_view> aircraftTypeSeatLetters;
}

#endif