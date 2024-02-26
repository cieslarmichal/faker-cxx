#include "../common/helper.h"
#include "../common/luhn_check.h"
#include "../common/string_helper.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <regex>
#include <string>
#include <vector>

namespace faker {
std::random_device Helper::randomDevice;

std::mt19937 Helper::pseudoRandomGenerator(Helper::randomDevice());

std::string Helper::shuffleString(std::string data)
{
    std::shuffle(data.begin(), data.end(), pseudoRandomGenerator);

    return data;
}

std::string Helper::replaceSymbolWithNumber(const std::string& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str) {
        if (ch == symbol) {
            result += std::to_string(number::integer(0, 9));
        } else if (ch == '!') {
            result += std::to_string(number::integer(2, 9));
        } else {
            result += ch;
        }
    }

    return result;
}

std::string Helper::replaceSymbolWithNumber(const std::string_view& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str) {
        if (ch == symbol) {
            result += std::to_string(number::integer(0, 9));
        } else if (ch == '!') {
            result += std::to_string(number::integer(2, 9));
        } else {
            result += ch;
        }
    }

    return result;
}

std::string Helper::replaceCreditCardSymbols(const std::string& inputString, char symbol)
{
    // Replace regex-like expressions in the given string with matching values.
    std::string modifiedString = regexpStyleStringParse(inputString);

    // Replace ### with random numbers (where ### is the symbol)
    modifiedString = replaceSymbolWithNumber(modifiedString, symbol);

    // Calculate the luhnCheckValue and replace 'L' with the checkNum
    int checkNum = LuhnCheck::luhnCheckValue(modifiedString);

    size_t pos = modifiedString.find('L');

    if (pos != std::string::npos) {
        modifiedString.replace(pos, 1, std::to_string(checkNum));
    }

    return modifiedString;
}

std::string Helper::regexpStyleStringParse(const std::string& input)
{
    std::string string = input;
    // Deal with range repeat `{min,max}`
    const std::regex RANGE_REP_REG(R"((.)\{(\d+),(\d+)\})");
    const std::regex REP_REG(R"((.)\{(\d+)\})");
    const std::regex RANGE_REG(R"(\[(\d+)-(\d+)\])");
    std::smatch token;

    while (std::regex_search(string, token, RANGE_REP_REG)) {
        int min = std::stoi(token[2]);
        int max = std::stoi(token[3]);
        // switch min and max
        if (min > max) {
            std::swap(min, max);
        }

        int repetitions = number::integer(min, max);
        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + StringHelper::repeat(token[1], repetitions)
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    // Deal with repeat `{num}`
    while (std::regex_search(string, token, REP_REG)) {
        int repetitions = std::stoi(token[2]);
        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + StringHelper::repeat(token[1], repetitions)
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    // Deal with range `[min-max]` (only works with numbers for now)
    // TODO: implement for letters e.g. [0-9a-zA-Z] etc.
    while (std::regex_search(string, token, RANGE_REG)) {
        int min = std::stoi(token[1]); // This time we are not capturing the char before `[]`
        int max = std::stoi(token[2]);
        // switch min and max
        if (min > max) {
            std::swap(min, max);
        }

        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + std::to_string(number::integer(min, max))
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    return string;
}
}
