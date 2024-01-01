#include "faker-cxx/Structure.h"

#include <algorithm>
#include <map>

#include "gtest/gtest.h"

#include "../../common/JsonHelper.h"
#include "../airline/data/Airports.h"
#include "../animal/data/Birds.h"
#include "../book/data/Titles.h"
#include "../movie/data/Actors.h"
#include "../../common/StringHelper.h"

using namespace faker;
using namespace ::testing;

class StructureTest : public Test
{
public:
};

TEST_F(StructureTest, shouldGenerateJson)
{
    std::map<std::string, Token> testTokens;
    testTokens.emplace("Airport name", Token::AirlineAirportName);
    testTokens.emplace("Bird name", Token::AnimalBird);
    testTokens.emplace("Book title", Token::BookTitle);
    testTokens.emplace("Actor name", Token::MovieActor);
    const auto generatedJson = Structure::json(testTokens);

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

    ASSERT_TRUE(
        std::ranges::any_of(airports, [value1](const Airline::Airport& airport) { return airport.name == value1; }));
    ASSERT_TRUE(std::ranges::any_of(birds, [value2](const std::string& bird) { return bird == value2; }));
    ASSERT_TRUE(std::ranges::any_of(titles, [value3](const std::string& title) { return title == value3; }));
    ASSERT_TRUE(std::ranges::any_of(actors, [value4](const std::string& actor) { return actor == value4; }));
}

TEST_F(StructureTest, shouldGenerateCSV)
{
    std::map<std::string, Token> testTokens;
    const unsigned int noRows = 2;
    testTokens.emplace("Airport name", Token::AirlineAirportName);
    testTokens.emplace("Bird name", Token::AnimalBird);
    testTokens.emplace("Book title", Token::BookTitle);
    testTokens.emplace("Actor name", Token::MovieActor);

    const auto generatedCSV = Structure::csv(testTokens, noRows);

    std::istringstream dataStream(generatedCSV);
    std::string line;

    std::getline(dataStream, line);
    std::vector<std::string> keys = StringHelper::split(line, ",");

    ASSERT_EQ(keys.at(0), "Actor name");
    ASSERT_EQ(keys.at(1), "Airport name");
    ASSERT_EQ(keys.at(2), "Bird name");
    ASSERT_EQ(keys.at(3), "Book title");

    while (std::getline(dataStream, line))
    {
        ASSERT_TRUE(std::ranges::any_of(actors, [&line](const std::string& actor)
                                        { return line.find(actor) != std::string::npos; }));
        ASSERT_TRUE(std::ranges::any_of(airports, [&line](const Airline::Airport& airport)
                                        { return line.find(airport.name) != std::string::npos; }));
        ASSERT_TRUE(std::ranges::any_of(birds, [&line](const std::string& bird)
                                        { return line.find(bird) != std::string::npos; }));
        ASSERT_TRUE(std::ranges::any_of(titles, [&line](const std::string& title)
                                        { return line.find(title) != std::string::npos; }));
    }
}
