#include "faker-cxx/Airline.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "data/AircraftTypes.h"
#include "data/Airlines.h"
#include "data/Airplanes.h"
#include "data/Airports.h"
#include "data/Seat.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

using namespace ::testing;
using namespace faker;

// TODO: add flight number tests
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

TEST_F(AirlineTest, shouldGenerateAirline)
{
    faker::AirlineStruct generatedAirline = Airline::airline();

    ASSERT_TRUE(std::ranges::any_of(
        airlines, [generatedAirline](const faker::AirlineStruct& airline)
        { return airline.name == generatedAirline.name && airline.iataCode == generatedAirline.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateAirplane)
{
    faker::Airplane generatedAirplane = Airline::airplane();

    ASSERT_TRUE(std::ranges::any_of(airplanes,
                                    [generatedAirplane](const faker::Airplane& airplane) {
                                        return airplane.name == generatedAirplane.name &&
                                               airplane.iataTypeCode == generatedAirplane.iataTypeCode;
                                    }));
}

TEST_F(AirlineTest, shouldGenerateAirport)
{
    faker::Airport generatedAirport = Airline::airport();

    ASSERT_TRUE(std::ranges::any_of(
        airports, [generatedAirport](const faker::Airport& airport)
        { return airport.name == generatedAirport.name && airport.iataCode == generatedAirport.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateRecordLocator)
{
    std::string generatedRecordLocatorWithAlpha = Airline::recordLocator(false);

    ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithAlpha, [](const char& c) { return std::isalpha(c); }));

    std::string generatedRecordLocatorWithNumerics = Airline::recordLocator(true);

    ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithNumerics, [](const char& c) { return std::isalnum(c); }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberRegional)
{
    std::string generatedSeatNumber = Airline::seat(faker::AircraftType::Regional);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(faker::AircraftType::Regional);

    bool inRange = false;
    for (int i = max; i >= min; --i)
    {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos)
        {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(faker::AircraftType::Regional),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberNarrowbody)
{
    std::string generatedSeatNumber = Airline::seat(faker::AircraftType::Narrowbody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(faker::AircraftType::Narrowbody);

    bool inRange = false;
    for (int i = max; i >= min; --i)
    {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos)
        {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(faker::AircraftType::Narrowbody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberWidebody)
{
    std::string generatedSeatNumber = Airline::seat(faker::AircraftType::Widebody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(faker::AircraftType::Widebody);

    bool inRange = false;
    for (int i = max; i >= min; --i)
    {
        std::string numberStr = std::to_string(i);
        if (generatedSeatNumber.find(numberStr) != std::string::npos)
        {
            inRange = true;
            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(faker::AircraftType::Widebody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberNoLeadingZeros)
{
    std::string flightNumber = Airline::flightNumber();
    int flightNumberInt = std::stoi(flightNumber);

    ASSERT_TRUE(flightNumber.length() == 4);

    ASSERT_TRUE((flightNumberInt > 999) && (flightNumberInt <= 9999));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberLeadingZeros)
{
    bool leadingZero = false;
    while (!leadingZero)
    {
        std::string flightNumber = Airline::flightNumber(true, 4);
        if (flightNumber.substr(0, 1) == "0")
        {
            leadingZero = true;
        }
    }

    ASSERT_TRUE(leadingZero);
}

TEST_F(AirlineTest, shouldGenerateFlightNumberByRange)
{
    std::string flightNumber = Airline::flightNumberByRange(false, {1, 6});
    ASSERT_TRUE(flightNumber.length() <= 6);
}
