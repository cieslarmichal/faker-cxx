#include "../test_helpers.h"
#include <faker/airline.h>
#include <faker/number.h>
#include <faker/string.h>
#include <modules/airline_data.h>

using namespace faker;

TEST(AirlineTest, shouldGenerateAircraftType)
{
    auto generatedAircraftType = airline::aircraft_type_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::aircraft_types, generatedAircraftType);
}

TEST(AirlineTest, shouldGenerateAirline)
{
    auto generatedAirline = airline::airline();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airlines, generatedAirline);
}

TEST(AirlineTest, shouldGenerateAirplane)
{
    auto generatedAirplane = airline::airplane();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airplanes, generatedAirplane);
}

TEST(AirlineTest, shouldGenerateAirport)
{
    auto generatedAirport = airline::airport();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airports, generatedAirport);
}

// TEST(AirlineTest, shouldGenerateRecordLocator)
// {
//     std::string generatedRecordLocatorWithAlpha = airline::record_locator(false);

//     ASSERT_EQ(generatedRecordLocatorWithAlpha.length(), 6);
//     ASSERT_RANGE_ALL_OF_TRUE(
//         generatedRecordLocatorWithAlpha, [](const char& c) { return std::isalpha(c); });

//     std::string generatedRecordLocatorWithNumerics = airline::record_locator(true);

//     ASSERT_EQ(generatedRecordLocatorWithNumerics.length(), 6);
//     ASSERT_RANGE_ALL_OF_TRUE(
//         generatedRecordLocatorWithNumerics, [](const char& c) { return std::isalnum(c); });
// }

// TEST(AirlineTest, shouldGenerateSeatNumberRegional)
// {
//     std::string generatedSeatNumber = airline::seat(faker::aircraft_type::Regional);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraft_type_max_rows.at(faker::aircraft_type::Regional);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraft_type_seat_letters.at(faker::aircraft_type::Regional),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

// TEST(AirlineTest, shouldGenerateSeatNumberNarrowbody)
// {
//     std::string generatedSeatNumber = airline::seat(faker::aircraft_type::narrow_body);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraft_type_max_rows.at(faker::aircraft_type::narrow_body);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraft_type_seat_letters.at(faker::aircraft_type::narrow_body),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

// TEST(AirlineTest, shouldGenerateSeatNumberWidebody)
// {
//     std::string generatedSeatNumber = airline::seat(faker::aircraft_type::wide_body);

//     ASSERT_TRUE(generatedSeatNumber.length() == 2 || generatedSeatNumber.length() == 3);

//     int min = 1;
//     int max = aircraft_type_max_rows.at(faker::aircraft_type::wide_body);

//     bool inRange = false;
//     for (int i = max; i >= min; --i) {
//         std::string numberStr = std::to_string(i);
//         if (generatedSeatNumber.find(numberStr) != std::string::npos) {
//             inRange = true;
//             break;
//         }
//     }

//     ASSERT_TRUE(inRange);
//     ASSERT_RANGE_ANY_OF_TRUE(aircraft_type_seat_letters.at(faker::aircraft_type::wide_body),
//         [generatedSeatNumber](char letter) { return generatedSeatNumber.back() == letter; });
// }

TEST(AirlineTest, shouldGenerateFlightNumberNoLeadingZeros)
{
    auto flightNumber = airline::flight_number();
    auto flightNumberInt = std::stoi(flightNumber);

    ASSERT_TRUE(flightNumber.length() == 4);
    ASSERT_TRUE((flightNumberInt > 999) && (flightNumberInt <= 9999));
}

TEST(AirlineTest, shouldGenerateFlightNumberLeadingZeros)
{
    bool leadingZero = false;
    while (!leadingZero) {
        std::string flightNumber = airline::flight_number(true, 4);
        if (flightNumber.substr(0, 1) == "0") {
            leadingZero = true;
        }
    }

    ASSERT_TRUE(leadingZero);
}

TEST(AirlineTest, shouldGenerateFlightNumberByRange)
{
    auto flightNumber = airline::flight_number_by_range(false, 1, 6);

    ASSERT_TRUE(flightNumber.length() <= 6);
}
