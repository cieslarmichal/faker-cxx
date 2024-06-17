#pragma once

#include <array>
#include <unordered_map>

#include "faker-cxx/Airline.h"

namespace faker::airline
{
extern const std::array<std::string_view, 3> aircraftTypes;
extern const std::array<AirlineInfo, 125> airlines;
extern const std::array<Airplane, 155> airplanes;
extern const std::array<Airport, 119> airports;
extern const std::unordered_map<AircraftType, int> aircraftTypeMaxRows;
extern const std::unordered_map<AircraftType, std::string_view> aircraftTypeSeatLetters;
}
