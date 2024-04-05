#pragma once

#include <map>
#include <string>
#include <vector>

#include "faker-cxx/Airline.h"

namespace faker
{
const std::map<Airline::AircraftType, int> aircraftTypeMaxRows = {
    {Airline::AircraftType::Regional, 20},
    {Airline::AircraftType::Narrowbody, 40},
    {Airline::AircraftType::Widebody, 60},
};

const std::map<Airline::AircraftType, std::vector<char>> aircraftTypeSeatLetters = {
    {Airline::AircraftType::Regional, {'A', 'B', 'C', 'D'}},
    {Airline::AircraftType::Narrowbody, {'A', 'B', 'C', 'D', 'E', 'F'}},
    {Airline::AircraftType::Widebody, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K'}},
};
}
