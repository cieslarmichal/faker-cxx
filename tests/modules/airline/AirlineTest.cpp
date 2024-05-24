#include "faker-cxx/Airline.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "airline/AirlineData.h"

using namespace ::testing;
using namespace faker;

class AirlineTest : public Test
{
public:
};

TEST_F(AirlineTest, shouldGenerateAircraftType)
{
    const auto generatedAircraftType = Airline::aircraftType();

    ASSERT_TRUE(std::ranges::any_of(aircraftTypes, [generatedAircraftType](const std::string_view& aircraftType)
                                    { return aircraftType == generatedAircraftType; }));
}

TEST_F(AirlineTest, shouldGenerateAirline)
{
    const auto generatedAirline = Airline::airline();

    ASSERT_TRUE(std::ranges::any_of(
        airlines, [generatedAirline](const Airline::AirlineInfo& airline)
        { return airline.name == generatedAirline.name && airline.iataCode == generatedAirline.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateAirplane)
{
    const auto generatedAirplane = Airline::airplane();

    ASSERT_TRUE(std::ranges::any_of(airplanes,
                                    [generatedAirplane](const Airline::Airplane& airplane) {
                                        return airplane.name == generatedAirplane.name &&
                                               airplane.iataTypeCode == generatedAirplane.iataTypeCode;
                                    }));
}

TEST_F(AirlineTest, shouldGenerateAirport)
{
    const auto generatedAirport = Airline::airport();

    ASSERT_TRUE(std::ranges::any_of(
        airports, [generatedAirport](const Airline::Airport& airport)
        { return airport.name == generatedAirport.name && airport.iataCode == generatedAirport.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateRecordLocator)
{
    const auto generatedRecordLocatorWithAlpha = Airline::recordLocator(false);

    ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithAlpha, [](const char& c) { return std::isalpha(c); }));

    const auto generatedRecordLocatorWithNumerics = Airline::recordLocator(true);

    ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithNumerics, [](const char& c) { return std::isalnum(c); }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberRegional)
{
    const auto generatedSeatNumber = Airline::seat(Airline::AircraftType::Regional);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Regional);

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
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(Airline::AircraftType::Regional),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberNarrowbody)
{
    const auto generatedSeatNumber = Airline::seat(Airline::AircraftType::Narrowbody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Narrowbody);

    bool inRange = false;

    for (int i = max; i >= min; --i)
    {
        const auto numberStr = std::to_string(i);

        if (generatedSeatNumber.find(numberStr) != std::string::npos)
        {
            inRange = true;

            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(Airline::AircraftType::Narrowbody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberWidebody)
{
    const auto generatedSeatNumber = Airline::seat(Airline::AircraftType::Widebody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(Airline::AircraftType::Widebody);

    bool inRange = false;

    for (int i = max; i >= min; --i)
    {
        const auto numberStr = std::to_string(i);

        if (generatedSeatNumber.find(numberStr) != std::string::npos)
        {
            inRange = true;

            break;
        }
    }

    ASSERT_TRUE(inRange);
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(Airline::AircraftType::Widebody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberNoLeadingZeros)
{
    const auto flightNumber = Airline::flightNumber();
    const auto flightNumberInt = std::stoi(flightNumber);

    ASSERT_TRUE(flightNumber.length() == 4);

    ASSERT_TRUE((flightNumberInt > 999) && (flightNumberInt <= 9999));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberLeadingZeros)
{
    bool leadingZero = false;
    while (!leadingZero)
    {
        const auto flightNumber = Airline::flightNumber(true, 4);

        if (flightNumber.substr(0, 1) == "0")
        {
            leadingZero = true;
        }
    }

    ASSERT_TRUE(leadingZero);
}

TEST_F(AirlineTest, shouldGenerateFlightNumberByRange)
{
    const auto flightNumber = Airline::flightNumberByRange(false, {1, 6});
    
    ASSERT_TRUE(flightNumber.length() <= 6);
}
