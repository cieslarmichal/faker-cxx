#pragma once

#include <chrono>
#include <random>
#include <regex>
#include <span>
#include <string_view>
#include <vector>

#include "../../src/common/LuhnCheck.h"
#include "../src/common/StringHelper.h"
#include "Number.h"

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
    static std::string replaceSymbolWithNumber(std::string str, const char & symbol = '#');

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
    static std::string replaceCreditCardSymbols(const std::string& inputString = "6453-####-####-####-###L", char symbol = '#');

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
    static std::string regexpStyleStringParse(const std::string& input);

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}
