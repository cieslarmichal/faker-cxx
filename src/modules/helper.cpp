#include <algorithm>
#include <random>
#include <regex>
#include <string>

#include "common/algo_helper.h"
#include "common/luhn_check.h"
#include "common/string_helper.h"
#include "faker-cxx/generator.h"
#include "faker-cxx/number.h"

namespace faker::helper
{
std::string shuffleString(std::string data)
{
    std::mt19937_64& pseudoRandomGenerator = faker::getGenerator();

    std::shuffle(data.begin(), data.end(), pseudoRandomGenerator);

    return data;
}

std::string replaceSymbolWithNumber(const std::string& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str)
    {
        if (ch == symbol)
        {
            result += std::to_string(number::integer(0, 9));
        }
        else if (ch == '!')
        {
            result += std::to_string(number::integer(2, 9));
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

std::string replaceSymbolWithLetter(const std::string& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str)
    {
        if (ch == symbol)
        {
            result += static_cast<char>(number::integer(65, 90));
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

std::string replaceCreditCardSymbols(const std::string& inputString, char symbol)
{
    std::string modifiedString = regexpStyleStringParse(inputString);

    modifiedString = replaceSymbolWithNumber(modifiedString, symbol);

    int checkNum = common::luhnCheckValue(modifiedString);

    size_t pos = modifiedString.find('L');

    if (pos != std::string::npos)
    {
        modifiedString.replace(pos, 1, std::to_string(checkNum));
    }

    return modifiedString;
}

std::string regexpStyleStringParse(const std::string& input)
{
    std::string data = input;
    // Deal with range repeat `{min,max}`
    const std::regex RANGE_REP_REG(R"((.)\{(\d+),(\d+)\})");
    const std::regex REP_REG(R"((.)\{(\d+)\})");
    const std::regex RANGE_REG(R"(\[(\d+)-(\d+)\])");

    std::smatch token;

    while (std::regex_search(data, token, RANGE_REP_REG))
    {
        int min = std::stoi(token[2]);
        int max = std::stoi(token[3]);
        if (min > max)
        {
            std::swap(min, max);
        }

        int repetitions = number::integer(min, max);
        data = data.substr(0, static_cast<unsigned long>(token.position())) + common::repeat(token[1], repetitions) +
               data.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    // Deal with repeat `{num}`
    while (std::regex_search(data, token, REP_REG))
    {
        int repetitions = std::stoi(token[2]);
        data = data.substr(0, static_cast<unsigned long>(token.position())) + common::repeat(token[1], repetitions) +
               data.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    while (std::regex_search(data, token, RANGE_REG))
    {
        int min = std::stoi(token[1]);

        int max = std::stoi(token[2]);

        if (min > max)
        {
            std::swap(min, max);
        }

        data = data.substr(0, static_cast<unsigned long>(token.position())) +
               std::to_string(number::integer(min, max)) +
               data.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    return data;
}
}
