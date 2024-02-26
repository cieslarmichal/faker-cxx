#include "../json_helper.h"
#include "../test_helpers.h"
#include <common/string_helper.h>
#include <faker/structure.h>
#include <modules/airline_data.h>
#include <modules/animal_data.h>
#include <modules/book_data.h>
#include <modules/movie_data.h>
#include <unordered_map>
#include <unordered_set>

using namespace faker;

TEST(StructureTest, shouldGenerateJson)
{
    std::unordered_map<std::string, structure::StructureToken> testTokens;
    testTokens.emplace("Airport name", structure::StructureToken::AirlineAirportName);
    testTokens.emplace("Bird name", structure::StructureToken::AnimalBird);
    testTokens.emplace("Book title", structure::StructureToken::BookTitle);
    testTokens.emplace("Actor name", structure::StructureToken::MovieActor);
    const auto generatedJson = structure::json(testTokens);

    const auto parsedJson = JsonHelper::simpleJsonParser(generatedJson);

    const auto key1 = parsedJson.find("Airport name")->first;
    const auto key2 = parsedJson.find("Bird name")->first;
    const auto key3 = parsedJson.find("Book title")->first;
    const auto key4 = parsedJson.find("Actor name")->first;

    const auto value1 = parsedJson.find("Airport name")->second;
    const auto value2 = parsedJson.find("Bird name")->second;
    const auto value3 = parsedJson.find("Book title")->second;
    const auto value4 = parsedJson.find("Actor name")->second;

    // there is no point for this but it's better to be there
    ASSERT_EQ(key1, "Airport name");
    ASSERT_EQ(key2, "Bird name");
    ASSERT_EQ(key3, "Book title");
    ASSERT_EQ(key4, "Actor name");

    ASSERT_TRUE(faker::testing::any_of(
        airline::data::airports, [value1](auto& airport) { return airport.name == value1; }));
    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::birds, value2);
    ASSERT_TRUE(faker::testing::any_of(
        book::data::titles, [value3](const auto& title) { return title == value3; }));
    ASSERT_TRUE(faker::testing::any_of(
        movie::data::actors, [value4](const auto& actor) { return actor == value4; }));
}

TEST(StructureTest, shouldGenerateCSV)
{
    std::unordered_map<std::string, structure::StructureToken> testTokens;
    const unsigned int noRows = 2;
    testTokens.emplace("Airport name", structure::StructureToken::AirlineAirportName);
    testTokens.emplace("Bird name", structure::StructureToken::AnimalBird);
    testTokens.emplace("Book title", structure::StructureToken::BookTitle);
    testTokens.emplace("Actor name", structure::StructureToken::MovieActor);

    const auto generatedCSV = structure::csv(testTokens, noRows);

    std::istringstream dataStream(generatedCSV);
    std::string line;

    std::getline(dataStream, line);

    auto x = StringHelper::split(line, ",");
    std::unordered_set<std::string> keys { x.begin(), x.end() };

    ASSERT_TRUE(keys.find("Actor name") != keys.end());
    ASSERT_TRUE(keys.find("Airport name") != keys.end());
    ASSERT_TRUE(keys.find("Bird name") != keys.end());
    ASSERT_TRUE(keys.find("Book title") != keys.end());

    while (std::getline(dataStream, line)) {
        ASSERT_TRUE(faker::testing::any_of(movie::data::actors,
            [&line](const auto& actor) { return line.find(actor) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(airline::data::airports,
            [&line](auto& airport) { return line.find(airport.name) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(animal::data::birds,
            [&line](const auto& bird) { return line.find(bird) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(book::data::titles,
            [&line](const auto& title) { return line.find(title) != std::string::npos; }));
    }
}
