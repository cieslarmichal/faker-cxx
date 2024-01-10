#pragma once

#include <map>
#include <string>

#include "types/StructureToken.h"

namespace faker
{
class Structure
{
public:
    /**
     * @brief Get a json string based on input
     *
     * @return a json string based on user selected tokens
     *
     * @code
     * std::map<std::string, faker::StructureToken> testTokens;
     * testTokens.emplace("Airport name", faker::StructureToken::AirlineAirportName);
     * testTokens.emplace("Bird name", faker::StructureToken::AnimalBird);
     * testTokens.emplace("Actor name", faker::StructureToken::MovieActor);
     * testTokens.emplace("Book title", faker::StructureToken::BookTitle);
     * Structure::json(testTokens) // {"FoodName":"Cajun Shrimp
     * Pasta","airlineType":"narrowbody","airportName":"Brisbane International Airport"}
     * @endcode
     */
    static std::string json(const std::map<std::string, faker::StructureToken>& items);
    /**
     * @brief Get a csv string based on input
     *
     * @return a josn csv based on user selected tokens and rows
     *
     * @code
     * std::map<std::string, faker::StructureToken> testTokens;
     * testTokens.emplace("Airport name", faker::StructureToken::AirlineAirportName);
     * testTokens.emplace("Bird name", faker::StructureToken::AnimalBird);
     * testTokens.emplace("Actor name", faker::StructureToken::MovieActor);
     * testTokens.emplace("Book title", faker::StructureToken::BookTitle);
     * Structure::csv(testTokens,2) // FoodName,airlineType,airportName
                                  Lobster Roll,widebody,Soekarno-Hatta International Airport
                                  Pierogi,widebody,Brasilia-Presidente Juscelino Kubitschek International Airport
     * @endcode
     */
    static std::string csv(const std::map<std::string, faker::StructureToken>& items, unsigned int rows);
};

}
