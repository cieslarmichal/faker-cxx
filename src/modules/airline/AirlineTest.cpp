#include "faker-cxx/Airline.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>

#include "data/AircraftTypes.h"
#include "data/Airplanes.h"
#include "data/Airlines.h"
#include "data/Airports.h"
#include "data/Seat.h"

using namespace ::testing;
using namespace faker;

class AirlineTest : public Test
{
public:
};

TEST_F(AirlineTest, shouldGenerateAircraftType)
{
    std::string generatedAircraftType = Airline::aircraftType();

    ASSERT_TRUE(std::ranges::any_of(aircraftTypes, [generatedAircraftType](const std::string& aircraftType)
                                    { return aircraftType == generatedAircraftType; }));
}

TEST_F(AirlineTest, shouldGenerateAirline) {
    Airline::AirlineStruct generatedAirline = Airline::airline();

    ASSERT_TRUE(std::ranges::any_of(airlines, [generatedAirline](const Airline::AirlineStruct& airline)
                                    { return airline.name == generatedAirline.name && airline.iataCode == generatedAirline.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateAirplane) {
    Airline::Airplane generatedAirplane = Airline::airplane();

    ASSERT_TRUE(std::ranges::any_of(airplanes, [generatedAirplane](const Airline::Airplane& airplane)
                                    { return airplane.name == generatedAirplane.name && airplane.iataTypeCode == generatedAirplane.iataTypeCode; }));
}

TEST_F(AirlineTest, shouldGenerateAirport) {
    Airline::Airport generatedAirport = Airline::airport();

    ASSERT_TRUE(std::ranges::any_of(airports, [generatedAirport](const Airline::Airport& airport)
                                    { return airport.name == generatedAirport.name && airport.iataCode == generatedAirport.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateRecordLocator) {
    std::string generatedRecordLocatorWithAlpha = Airline::recordLocator(false);

    ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithAlpha, [](const char& c)
                                    { return std::isalpha(c); }));

    std::string generatedRecordLocatorWithNumerics = Airline::recordLocator(true);

    ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithNumerics, [](const char& c)
                                    { return std::isalnum(c); }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberRegional) {
    std::string generatedSeatNumber = Airline::seat(Airline::AircraftType::Regional);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Regional);

    bool inRange = false;
    for (int i = max; i >= min; --i) {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos) {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(
        aircraftTypeSeatLetters.at(Airline::AircraftType::Regional),
        [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; }
        ));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberNarrowbody) {
    std::string generatedSeatNumber = Airline::seat(Airline::AircraftType::Narrowbody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Narrowbody);

    bool inRange = false;
    for (int i = max; i >= min; --i) {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos) {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(
        aircraftTypeSeatLetters.at(Airline::AircraftType::Narrowbody),
        [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; }
        ));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberWidebody) {
    std::string generatedSeatNumber = Airline::seat(Airline::AircraftType::Widebody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Widebody);

    bool inRange = false;
    for (int i = max; i >= min; --i) {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos) {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(
        aircraftTypeSeatLetters.at(Airline::AircraftType::Widebody),
        [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; }
        ));
}