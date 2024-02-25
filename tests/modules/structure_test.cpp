#include "../test_helpers.h"
#include <common/json_helper.h>
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
    std::unordered_map<std::string, StructureToken> testTokens;
    testTokens.emplace("Airport name", StructureToken::AirlineAirportName);
    testTokens.emplace("Bird name", StructureToken::AnimalBird);
    testTokens.emplace("Book title", StructureToken::BookTitle);
    testTokens.emplace("Actor name", StructureToken::MovieActor);
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
        airports, [value1](const faker::Airport& airport) { return airport.name == value1; }));
    FAKER_EXPECT_CONTAINS(birds, value2);
    ASSERT_TRUE(faker::testing::any_of(
        books::titles, [value3](const auto& title) { return title == value3; }));
    ASSERT_TRUE(faker::testing::any_of(
        movie::actors, [value4](const auto& actor) { return actor == value4; }));
}

TEST(StructureTest, shouldGenerateCSV)
{
    std::unordered_map<std::string, StructureToken> testTokens;
    const unsigned int noRows = 2;
    testTokens.emplace("Airport name", StructureToken::AirlineAirportName);
    testTokens.emplace("Bird name", StructureToken::AnimalBird);
    testTokens.emplace("Book title", StructureToken::BookTitle);
    testTokens.emplace("Actor name", StructureToken::MovieActor);

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
        ASSERT_TRUE(faker::testing::any_of(movie::actors,
            [&line](const auto& actor) { return line.find(actor) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(airports, [&line](const faker::Airport& airport) {
            return line.find(airport.name) != std::string::npos;
        }));
        ASSERT_TRUE(faker::testing::any_of(
            birds, [&line](const auto& bird) { return line.find(bird) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(books::titles,
            [&line](const auto& title) { return line.find(title) != std::string::npos; }));
    }
}
