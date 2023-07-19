#pragma once

#include <chrono>
#include <random>
#include <regex>
#include <span>
#include <string_view>
#include <vector>

#include "Number.h"
#include "../src/common/StringHelper.h"

namespace faker
{
class Helper
{
public:
    /**
     * @brief Get a random element from an STL container.
     *
     * @tparam T an element type of the container.
     *
     * @param data The container.
     *
     * @return T a random element from the container.
     *
     * @code
     * Helper::arrayElement<char>(std::string{"abcd"}) // "b"
     * Helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
     * @endcode
     */
    template <class T>
    static T arrayElement(std::span<const T> data)
    {
        const auto index = Number::integer<size_t>(data.size() - 1);

        return data[index];
    }

    /**
     * @brief Returns shuffled STL container.
     *
     * @tparam T an element type of the container.
     *
     * @param data The container.
     *
     * @return Container with shuffled elements.
     *
     * @code
     * Helper::arrayElement<char>(std::string{"abcd"}) // "dcba"
     * @endcode
     */
    template <class T>
    static std::vector<T> shuffle(std::vector<T> data)
    {
        std::shuffle(std::begin(data), std::end(data), pseudoRandomGenerator);

        return data;
    }

    /**
     * @brief Returns the given string parsed symbol by symbol and replaced the placeholders with digits ("0" - "9").
     * "!" will be replaced by digits >=2 ("2" - "9").
     *
     * @param str The template to parse string.
     *
     * @param symbol The symbol to replace with digits. Defaults to '#'.
     *
     * @return The string replaced symbols with digits.
     *
     * @code
     * Helper::replaceSymbolWithNumber() // ""
     * Helper::replaceSymbolWithNumber("#####") // "04812"
     * Helper::replaceSymbolWithNumber("!####") // "27378"
     * Helper::replaceSymbolWithNumber("Your pin is: !####") // "29841"
     * @endcode
     */
    static std::string replaceSymbolWithNumber(std::string str, const char & symbol = '#')
    {
        for (char& ch : str)
        {
            if(ch == symbol)
            {
                ch = static_cast<char>(Number::integer(0,9) + '0');
            }
            else if(ch == '!')
            {
                ch = static_cast<char>(Number::integer(2,9) + '2');
            }
        }
        return str;
    }

    /**
     * @brief Returns credit card schema with replaced symbols and patterns in a credit card  including Luhn checksum
     * This method supports both range patterns `[4-9]` as well as the patterns used by `replaceSymbolWithNumber()`.
     * `L` will be replaced with the appropriate Luhn checksum.
     *
     * @param inputString TThe credit card format pattern. Defaults to "6453-####-####-####-###L".
     *
     * @param symbol The symbol to replace with a digit. Defaults to '#'.
     *
     * @return The string replaced symbols with digits.
     *
     * @code
     * Helper::replaceCreditCardSymbols() // "6453-4876-8626-8995-3771"
     * Helper::replaceCreditCardSymbols("1234-[4-9]-##!!-L") // "1234-9-5298-2"
     * @endcode
     */
    static std::string replaceCreditCardSymbols(const std::string& inputString = "6453-####-####-####-###L", char symbol = '#') {
        // Replace regex-like expressions in the given string with matching values.
        std::string modifiedString = regexpStyleStringParse(inputString);

        // Replace ### with random numbers (where ### is the symbol)
        modifiedString = replaceSymbolWithNumber(modifiedString, symbol);

        // Calculate the luhnCheckValue and replace 'L' with the checkNum
        int checkNum = luhnCheckValue(modifiedString);
        size_t pos = modifiedString.find('L');
        if (pos != std::string::npos) {
            modifiedString.replace(pos, 1, std::to_string(checkNum));
        }

        return modifiedString;
    }

    /**
     * @brief Returns the replaced regex-like expression in the string with matching values.
     *
     * Supported patterns:
     * - `.{times}` => Repeat the character exactly `times` times.
     * - `.{min,max}` => Repeat the character `min` to `max` times.
     * - `[min-max]` => Generate a number between min and max (inclusive).
     *
     * @param input The template string to to parse.
     *
     * @return The replaced regex-like expression in the string with matching values.
     *
     * @code
     * Helper::regexpStyleStringParse() // ""
     * Helper::regexpStyleStringParse("#{5}") // "#####"
     * Helper::regexpStyleStringParse("#{2,9}") // "#######"
     * Helper::regexpStyleStringParse("[500-15000]") // "8375"
     * Helper::regexpStyleStringParse("#{3}test[1-5]") // "###test3"
     * @endcode
     */
    static std::string regexpStyleStringParse(const std::string& input) {
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

            int repetitions = Number::integer(min, max);
            string =
                string.substr(0, static_cast<unsigned long>(token.position())) +
                StringHelper::repeat(token[1], repetitions) +
                string.substr(static_cast<unsigned long>(token.position() + token.length()));
        }

        // Deal with repeat `{num}`
        while (std::regex_search(string, token, REP_REG)) {
            int repetitions = std::stoi(token[2]);
            string =
                string.substr(0, static_cast<unsigned long>(token.position())) +
                StringHelper::repeat(token[1], repetitions) +
                string.substr(static_cast<unsigned long>(token.position() + token.length()));
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

            string =
                string.substr(0, static_cast<unsigned long>(token.position())) +
                std::to_string(Number::integer(min, max)) +
                string.substr(static_cast<unsigned long>(token.position() + token.length()));
        }

        return string;
    }

    /**
     * @brief Returns the luhn check value for the given string.
     *
     * @param inputString The string to calculate the check value for.
     *
     * @return the luhn check value for the given string.
     *
     */
    static int luhnCheckValue(const std::string& inputString) {
        std::string str = inputString;
        str = std::regex_replace(str, std::regex("[\\s-]"), "");
        int sum = 0;
        bool alternate = false;

        for (std::string::size_type i = str.length() - 1; i != std::string::npos; i--) {
            int n = str[i] - '0';
            if (alternate) {
                n *= 2;
                if (n > 9) {
                    n = (n % 10) + 1;
                }
            }

            sum += n;
            alternate = !alternate;
        }

        return sum % 10;
    }

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}
