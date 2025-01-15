#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "airline_data.h"
#include "faker-cxx/airline.h"

using namespace ::testing;
using namespace faker::airline;

class AirlineTest : public Test
{
public:
};

TEST_F(AirlineTest, shouldGenerateAircraftType)
{
    const auto generatedAircraftType = aircraftType();

    ASSERT_TRUE(std::ranges::any_of(aircraftTypes, [generatedAircraftType](const std::string_view& aircraftType)
                                    { return aircraftType == generatedAircraftType; }));
}

TEST_F(AirlineTest, shouldGenerateAirline)
{
    const auto generatedAirline = airline();

    ASSERT_TRUE(std::ranges::any_of(
        airlines, [generatedAirline](const AirlineInfo& airline)
        { return airline.name == generatedAirline.name && airline.iataCode == generatedAirline.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateAirplane)
{
    const auto generatedAirplane = airplane();

    ASSERT_TRUE(std::ranges::any_of(airplanes,
                                    [generatedAirplane](const Airplane& airplane)
                                    {
                                        return airplane.name == generatedAirplane.name &&
                                               airplane.iataTypeCode == generatedAirplane.iataTypeCode;
                                    }));
}

TEST_F(AirlineTest, shouldGenerateAirport)
{
    const auto generatedAirport = airport();

    ASSERT_TRUE(std::ranges::any_of(
        airports, [generatedAirport](const Airport& airport)
        { return airport.name == generatedAirport.name && airport.iataCode == generatedAirport.iataCode; }));
}

TEST_F(AirlineTest, shouldGenerateRecordLocator)
{
    const auto generatedRecordLocatorWithAlpha = recordLocator(false);

    ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithAlpha, [](const char& c) { return std::isalpha(c); }));

    const auto generatedRecordLocatorWithNumerics = recordLocator(true);

    ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedRecordLocatorWithNumerics, [](const char& c) { return std::isalnum(c); }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberRegional)
{
    const auto generatedSeatNumber = seat(AircraftType::Regional);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(AircraftType::Regional);

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
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(AircraftType::Regional),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberNarrowbody)
{
    const auto generatedSeatNumber = seat(AircraftType::Narrowbody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(AircraftType::Narrowbody);

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
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(AircraftType::Narrowbody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateSeatNumberWidebody)
{
    const auto generatedSeatNumber = seat(AircraftType::Widebody);

    ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

    int min = 1;
    int max = aircraftTypeMaxRows.at(AircraftType::Widebody);

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
    ASSERT_TRUE(std::ranges::any_of(aircraftTypeSeatLetters.at(AircraftType::Widebody),
                                    [generatedSeatNumber](char letter)
                                    { return generatedSeatNumber.back() == letter; }));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberNoLeadingZeros)
{
    // called faker::airline to avoid ambiguous error
    const auto flightNumber = faker::airline::flightNumber();
    const auto flightNumberInt = std::stoi(flightNumber);

    ASSERT_TRUE(flightNumber.length() == 4);

    ASSERT_TRUE((flightNumberInt > 999) && (flightNumberInt <= 9999));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberLeadingZeros)
{
    bool leadingZero = false;
    while (!leadingZero)
    {
        const auto flightNumber = faker::airline::flightNumber(true, 4);

        if (flightNumber.substr(0, 1) == "0")
        {
            leadingZero = true;
        }
    }

    ASSERT_TRUE(leadingZero);
}

TEST_F(AirlineTest, shouldGenerateFlightNumberByRangeNoLeadingZeros)
{
    const auto flightNumber = flightNumberByRange(false, {1, 6});

    ASSERT_TRUE(flightNumber.length() <= 6);
}

TEST_F(AirlineTest, shouldGenerateFlightNumberByRangeLeadingZeros)
{
    const auto flightNumber = flightNumberByRange(true, {1, 8});

    ASSERT_TRUE(flightNumber.length() <= 8);
}
