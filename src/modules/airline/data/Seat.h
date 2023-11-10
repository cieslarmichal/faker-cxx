#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "faker-cxx/Airline.h"

namespace faker
{

const std::unordered_map<Airline::AircraftType, int> aircraftTypeMaxRows = {
    {Airline::AircraftType::Regional, 20},
    {Airline::AircraftType::Narrowbody, 40},
    {Airline::AircraftType::Widebody, 60},
};

const std::unordered_map<Airline::AircraftType, std::vector<char>> aircraftTypeSeatLetters = {
    {Airline::AircraftType::Regional, {'A', 'B', 'C', 'D'}},
    {Airline::AircraftType::Narrowbody, {'A', 'B', 'C', 'D', 'E', 'F'}},
    {Airline::AircraftType::Widebody, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K'}},
};
}

// upon picking an aircraft type we can just generate one randomly by aircraft type, vector[aircraft_type]
