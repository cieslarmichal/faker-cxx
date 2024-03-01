#include "../json_helper.h"
#include "../test_helpers.h"
#include <common/strings.h>
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
    std::vector<structure::structure_token_spec> specs;
    specs.push_back(structure::structure_token_spec {
        "Airport name", structure::structure_token_t::airline_airport_name });
    specs.push_back(
        structure::structure_token_spec { "Bird name", structure::structure_token_t::animal_bird });
    specs.push_back(
        structure::structure_token_spec { "Book title", structure::structure_token_t::book_title });
    specs.push_back(structure::structure_token_spec {
        "Actor name", structure::structure_token_t::movie_actor });

    const auto generatedJson = structure::json(specs);

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
    std::vector<structure::structure_token_spec> specs;
    specs.push_back(structure::structure_token_spec {
        "Airport name", structure::structure_token_t::airline_airport_name });
    specs.push_back(
        structure::structure_token_spec { "Bird name", structure::structure_token_t::animal_bird });
    specs.push_back(
        structure::structure_token_spec { "Book title", structure::structure_token_t::book_title });
    specs.push_back(structure::structure_token_spec {
        "Actor name", structure::structure_token_t::movie_actor });

    const unsigned int row_count = 2;
    const auto generated_csv = structure::csv(specs, row_count);

    std::istringstream stream(generated_csv);
    std::string line;

    std::getline(stream, line);

    auto line_parts = utils::split(line, ",");
    std::unordered_set<std::string_view> keys { line_parts.begin(), line_parts.end() };

    ASSERT_TRUE(keys.find("Actor name") != keys.end());
    ASSERT_TRUE(keys.find("Airport name") != keys.end());
    ASSERT_TRUE(keys.find("Bird name") != keys.end());
    ASSERT_TRUE(keys.find("Book title") != keys.end());

    unsigned lines_read = 0;
    while (std::getline(stream, line)) {
        ASSERT_TRUE(faker::testing::any_of(movie::data::actors,
            [&line](const auto& actor) { return line.find(actor) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(airline::data::airports,
            [&line](auto& airport) { return line.find(airport.name) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(animal::data::birds,
            [&line](const auto& bird) { return line.find(bird) != std::string::npos; }));
        ASSERT_TRUE(faker::testing::any_of(book::data::titles,
            [&line](const auto& title) { return line.find(title) != std::string::npos; }));
        ++lines_read;
    }

    ASSERT_EQ(lines_read, row_count);
}
