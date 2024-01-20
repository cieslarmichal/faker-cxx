#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "faker-cxx/Airline.h"

namespace faker
{

const std::unordered_map<faker::AircraftType, int> aircraftTypeMaxRows = {
    {faker::AircraftType::Regional, 20},
    {faker::AircraftType::Narrowbody, 40},
    {faker::AircraftType::Widebody, 60},
};

const std::unordered_map<faker::AircraftType, std::vector<char>> aircraftTypeSeatLetters = {
    {faker::AircraftType::Regional, {'A', 'B', 'C', 'D'}},
    {faker::AircraftType::Narrowbody, {'A', 'B', 'C', 'D', 'E', 'F'}},
    {faker::AircraftType::Widebody, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K'}},
};
}

// upon picking an aircraft type we can just generate one randomly by aircraft type, vector[aircraft_type]
