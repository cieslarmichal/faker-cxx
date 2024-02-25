#ifndef FAKER_STRUCTURE_H
#define FAKER_STRUCTURE_H

#include <faker/types/structure_token.h>
#include <string>
#include <unordered_map>

namespace faker::structure {
/**
 * @brief Get a json string based on input
 *
 * @return a json string based on user selected tokens
 *
 * @code
 * std::unordered_map<std::string, faker::StructureToken> testTokens;
 * testTokens.emplace("Airport name", faker::StructureToken::AirlineAirportName);
 * testTokens.emplace("Bird name", faker::StructureToken::AnimalBird);
 * testTokens.emplace("Actor name", faker::StructureToken::MovieActor);
 * testTokens.emplace("Book title", faker::StructureToken::BookTitle);
 * structure::json(testTokens) // {"FoodName":"Cajun Shrimp
 * Pasta","airlineType":"narrowbody","airportName":"Brisbane International Airport"}
 * @endcode
 */
std::string json(const std::unordered_map<std::string, faker::StructureToken>& items);
/**
 * @brief Get a csv string based on input
 *
 * @return a josn csv based on user selected tokens and rows
 *
 * @code
 * std::unordered_map<std::string, faker::StructureToken> testTokens;
 * testTokens.emplace("Airport name", faker::StructureToken::AirlineAirportName);
 * testTokens.emplace("Bird name", faker::StructureToken::AnimalBird);
 * testTokens.emplace("Actor name", faker::StructureToken::MovieActor);
 * testTokens.emplace("Book title", faker::StructureToken::BookTitle);
 * structure::csv(testTokens,2) // FoodName,airlineType,airportName
                              Lobster Roll,widebody,Soekarno-Hatta International Airport
                              Pierogi,widebody,Brasilia-Presidente Juscelino Kubitschek
 International Airport
 * @endcode
 */
std::string csv(
    const std::unordered_map<std::string, faker::StructureToken>& items, unsigned int rows);
}

#endif