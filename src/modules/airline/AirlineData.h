#pragma once

#include <array>
#include <unordered_map>

#include "faker-cxx/Airline.h"

namespace faker
{
extern const std::array<std::string_view, 3> aircraftTypes;
extern const std::array<Airline::AirlineInfo, 125> airlines;
extern const std::array<Airline::Airplane, 155> airplanes;
extern const std::array<Airline::Airport, 119> airports;
extern const std::unordered_map<Airline::AircraftType, int> aircraftTypeMaxRows;
extern const std::unordered_map<Airline::AircraftType, std::string_view> aircraftTypeSeatLetters;
}
