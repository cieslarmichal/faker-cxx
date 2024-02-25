#include "../test_helpers.h"
#include <faker/airline.h>
#include <faker/number.h>
#include <faker/string.h>
#include <modules/airline_data.h>

using namespace ::testing;
using namespace faker;

// TODO: add flight number tests
class AirlineTest : public Test {
public:
};

TEST_F(AirlineTest, shouldGenerateAircraftType)
{
    auto generatedAircraftType = airline::aircraftType();

    ASSERT_TRUE(faker::testing::contains(aircraftTypes, generatedAircraftType));
}

TEST_F(AirlineTest, shouldGenerateAirline)
{
    faker::AirlineStruct generatedAirline = airline::airline();

    ASSERT_TRUE(faker::testing::contains(airlines, generatedAirline));
}

TEST_F(AirlineTest, shouldGenerateAirplane)
{
    faker::Airplane generatedAirplane = airline::airplane();

    ASSERT_TRUE(faker::testing::contains(airplanes, generatedAirplane));
}

TEST_F(AirlineTest, shouldGenerateAirport)
{
    faker::Airport generatedAirport = airline::airport();

    ASSERT_TRUE(faker::testing::contains(airports, generatedAirport));
}

// TEST_F(AirlineTest, shouldGenerateRecordLocator)
// {
//     std::string generatedRecordLocatorWithAlpha = airline::recordLocator(false);

//     ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
//     ASSERT_RANGE_ALL_OF_TRUE(
//         generatedRecordLocatorWithAlpha, [](const char& c) { return std::isalpha(c); });

//     std::string generatedRecordLocatorWithNumerics = airline::recordLocator(true);

//     ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
//     ASSERT_RANGE_ALL_OF_TRUE(
//         generatedRecordLocatorWithNumerics, [](const char& c) { return std::isalnum(c); });
// }

// TEST_F(AirlineTest, shouldGenerateSeatNumberRegional)
// {
//     std::string generatedSeatNumber = airline::seat(faker::AircraftType::Regional);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraftTypeMaxRows.at(faker::AircraftType::Regional);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraftTypeSeatLetters.at(faker::AircraftType::Regional),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

// TEST_F(AirlineTest, shouldGenerateSeatNumberNarrowbody)
// {
//     std::string generatedSeatNumber = airline::seat(faker::AircraftType::Narrowbody);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraftTypeMaxRows.at(faker::AircraftType::Narrowbody);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraftTypeSeatLetters.at(faker::AircraftType::Narrowbody),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

// TEST_F(AirlineTest, shouldGenerateSeatNumberWidebody)
// {
//     std::string generatedSeatNumber = airline::seat(faker::AircraftType::Widebody);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraftTypeMaxRows.at(faker::AircraftType::Widebody);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraftTypeSeatLetters.at(faker::AircraftType::Widebody),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

TEST_F(AirlineTest, shouldGenerateFlightNumberNoLeadingZeros)
{
    std::string flightNumber = airline::flightNumber();
    int flightNumberInt = std::stoi(flightNumber);

    ASSERT_TRUE(flightNumber.length() == 4);

    ASSERT_TRUE((flightNumberInt > 999) && (flightNumberInt <= 9999));
}

TEST_F(AirlineTest, shouldGenerateFlightNumberLeadingZeros)
{
    bool leadingZero = false;
    while (!leadingZero) {
        std::string flightNumber = airline::flightNumber(true, 4);
        if (flightNumber.substr(0, 1) == "0") {
            leadingZero = true;
        }
    }

    ASSERT_TRUE(leadingZero);
}

TEST_F(AirlineTest, shouldGenerateFlightNumberByRange)
{
    std::string flightNumber = airline::flightNumberByRange(false, { 1, 6 });
    ASSERT_TRUE(flightNumber.length() <= 6);
}
