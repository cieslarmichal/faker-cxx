#pragma once

#include <limits>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <string>

#include "RandomGenerator.h"
#include "types/Hex.h"

namespace faker::string
{
enum class StringCasing
{
    Mixed,
    Lower,
    Upper
};

struct CharCount
{
    unsigned int atLeastCount{(std::numeric_limits<unsigned int>::min)()};
    unsigned int atMostCount{(std::numeric_limits<unsigned int>::max)()};
};

/**
 * A std::map where user can specify the count required for specific chars
 */
using GuaranteeMap = std::map<char, CharCount>;

/**
 * @brief Checks if the given guarantee map is valid for given targetCharacters and length.
 *
 * @returns a bool.
 *
 * @param guarantee A std::map that maps the count range of specific characters required
 * @param targetCharacters A std::string consisting of all chars available for that string generating function
 * @param length The number of characters to generate.
 *
 * @code
 * GuaranteeMap guarantee = {{'0',{5,10}},{'1',{6,10}}};
 * std::string targetCharacters = "01";
 * unsigned int length = 10;
 * faker::string::isValidGuarantee(guarantee,targetCharacters,length) // false
 * @endcode
 */
bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length);

/**
 * @brief Generates the least required string for a given guarantee map
 *
 * @returns least required std::string
 *
 * @param guarantee A std::map<char,CharCount> which stores the guarantee specified by the user
 *
 * @code
 * GuaranteeMap guarantee { {'0',{3,10}},{'a',{6,8}} }; // "000aaaaaa"
 * faker::string::generateAtLeastString(guarantee);
 * @endcode
 */
std::string generateAtLeastString(const GuaranteeMap& guarantee);

    // namespace {
    //     std::string generateStringWithGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters,
    //                                                unsigned int length);
    // }
    /**
     * @brief Generates an Universally Unique Identifier with version 4.
     *
     * @returns UUIDv4.
     *
     * @param gen A random number generator (type RandomGenerator)
     *
     * @code
     * string::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
     * @endcode
     */
    template <typename T = std::mt19937>
    std::string uuid(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
    {
        static std::uniform_int_distribution<> dist(0, 15);
        static std::uniform_int_distribution<> dist2(8, 11);
        static std::string_view hexCharacters{"0123456789abcdef"};

        std::string result;
        result.reserve(36);

        for (int i = 0; i < 8; i++)
        {
            result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
        }
        result.append(1, '-');

        for (int i = 0; i < 4; i++)
        {
            result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
        }
        result.append(1, '-');

        result.append(1, '4');
        for (int i = 0; i < 3; i++)
        {
            result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
        }
        result.append(1, '-');

        result.append(1, hexCharacters[static_cast<size_t>(gen(dist2))]);

        for (int i = 0; i < 3; i++)
        {
            result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
        }
        result.append(1, '-');

        for (int i = 0; i < 12; i++)
        {
            result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
        }

        return result;
    }

    /**
     * @brief Returns a string containing UTF-16 chars between 33 and 125 (`!` to `}`).
     *
     * @param length The number of characters to generate. Defaults to `10`.
     *
     * @returns Sample string.
     *
     * @code
     * string::sample() // "Zo!.:*e>wR"
     * string::sample(5) // "6Bye8"
     * @endcode
     */
    std::string sample(unsigned length = 10);

    /**
     * @brief Returns a string containing UTF-16 chars between 33 and 125 (`!` to `}`).
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of characters to generate. Defaults to `10`.
     *
     * @returns Sample string.
     *
     * @code
     * string::sample({}) // "Zo!.:*e>wR"
     * string::sample({{'|' ,{2,2}},{'^',{0,0}},{':',{1,8}}}, 8) // "|6Bye8:|"
     * @endcode
     */
    std::string sample(GuaranteeMap&& guarantee, unsigned length = 10);

    /**
     * @brief Generates a string consisting of given characters.
     *
     * @param characters The characters to generate string with.
     * @param length The number of characters to generate. Defaults to `1`.
     *
     * @returns String from characters.
     *
     * @code
     * string::fromCharacters("abc") // "b"
     * string::fromCharacters("qwerty", 5) // "qrwqt"
     * @endcode
     */
    std::string fromCharacters(const std::string& characters, unsigned length = 1);

    /**
     * @brief Generates a string consisting of given characters.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param characters The characters to generate string with.
     * @param length The number of characters to generate. Defaults to `1`.
     *
     * @returns String from characters.
     *
     * @code
     * string::fromCharacters({}, "abc") // "b"
     * string::fromCharacters({{'q',{2,2}},{'e',{1,5}}}, "qwerty", 8) // "yqreqety"
     * @endcode
     */
    std::string fromCharacters(GuaranteeMap&& guarantee, const std::string& characters, unsigned length = 1);

    /**
     * @brief Generates a string consisting of letters in the English alphabet.
     *
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     * @param excludeCharacters The characters to be excluded from the string to generate. Defaults to ``.
     *
     *
     * @returns Alpha string.
     *
     * @code
     * string::alpha() // "b"
     * string::alpha(5, StringCasing::Upper) // "DTCIC"
     * string::alpha(4, StringCasing::Lower) // "brpt"
     * @endcode
     */
    std::string alpha(unsigned length = 1, StringCasing casing = StringCasing::Mixed,
                             const std::string& excludeCharacters = "");

    /**
     * @brief Generates a string consisting of letters in the English alphabet.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     *
     * @returns Alpha string.
     *
     * @code
     * string::alpha({}) // "b"
     * string::alpha({{'A',{2,2}}, 5, StringCasing::Upper) // "DACAC"
     * string::alpha({{'a',{0,0}},{'b',{3,3}},{'c', {0,2}}}, 10, StringCasing::Lower) // "bicnmmkbbp"
     * @endcode
     */
    std::string alpha(GuaranteeMap&& guarantee, unsigned length = 1, StringCasing casing = StringCasing::Mixed);

    /**
     * @brief Generates a string consisting of alpha characters and digits.
     *
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     * @param excludeCharacters The characters to be excluded from alphanumeric characters to generate
     * string from. Defaults to ``.
     *
     * @returns Alphanumeric string.
     *
     * @code
     * string::alphanumeric() // "4"
     * string::alphanumeric(5, StringCasing::Upper) // "3e5V7"
     * string::alphanumeric(4, StringCasing::Lower) // "1nrq"
     * @endcode
     */
    std::string alphanumeric(unsigned length = 1, StringCasing casing = StringCasing::Mixed,
                                    const std::string& excludeCharacters = "");

    /**
     * @brief Generates a string consisting of alpha characters and digits.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     *
     * @returns Alphanumeric string.
     *
     * @code
     * string::alphanumeric({}) // "4"
     * string::alphanumeric({{'A', {3,6}},{'1', {1,1}}, 5, StringCasing::Upper) // "1EAAA"
     * string::alphanumeric({{'a',{0,2}},{'2',{0,3}},{'z',{3,5}}}, 10, StringCasing::Lower) // "z1naazrqz0"
     * @endcode
     */
    std::string alphanumeric(GuaranteeMap&& guarantee, unsigned length = 1,
                                    StringCasing casing = StringCasing::Mixed);

    /**
     * @brief Generates a given length string of digits.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     * @param allowLeadingZeros Whether leading zeros are allowed or not. Defaults to `true`.
     *
     * @returns Numeric string.
     *
     * @code
     * string::numeric() // "1"
     * string::numeric(6) // "035742"
     * string::numeric(6, false) // "254429"
     * @endcode
     */
    std::string numeric(unsigned length = 1, bool allowLeadingZeros = true);

    /**
     * @brief Generates a given length string of digits.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of digits to generate. Defaults to `1`.
     * @param allowLeadingZeros Whether leading zeros are allowed or not. Defaults to `true`.
     *
     * @returns Numeric string.
     *
     * @code
     * string::numeric({}) // "1"
     * string::numeric({'5',{3,6}}, 6) // "055542"
     * string::numeric({'0',{0,0}}, {'4',{1,1}}, 6, false) // "854829"
     * @endcode
     */
    std::string numeric(GuaranteeMap&& guarantee, unsigned length = 1, bool allowLeadingZeros = true);

    /**
     * @brief Generates a hexadecimal string.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     * @param casing Casing of the generated string. Defaults to `HexCasing::Lower`.
     * @param prefix Prefix for the generated string. Defaults to `0x`.
     *
     * @returns Hexadecimal string.
     *
     * @code
     * string::hexadecimal() // "0xb"
     * string::hexadecimal(10) // "0xae13d044cb"
     * string::hexadecimal(6, HexCasing::Upper, HexPrefix::Hash) // "#E3F380"
     * string::hexadecimal(6, HexCasing::Lower, HexPrefix::None) // "e3f380"
     * @endcode
     */
    std::string hexadecimal(unsigned length = 1, HexCasing casing = HexCasing::Lower,
                                   HexPrefix prefix = HexPrefix::ZeroX);

    /**
     * @brief Returns a lowercase hexadecimal number.
     *
     * @param min Optional parameter for lower bound of generated number.
     * @param max Optional parameter for upper bound of generated number.
     *
     * @return A lowercase hexadecimal number.
     *
     * @code
     * string::hexadecimal() // "b"
     * string::hexadecimal(0, 255) // "9d"
     * @endcode
     */
    std::string hexadecimal(std::optional<int> min = std::nullopt, std::optional<int> max = std::nullopt);

    /**
     * @brief Generates a hexadecimal string.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of digits to generate. Defaults to `1`.
     * @param casing Casing of the generated string. Defaults to `HexCasing::Lower`.
     * @param prefix Prefix for the generated string. Defaults to `0x`.
     *
     * @returns Hexadecimal string.
     *
     * @code
     * string::hexadecimal({}) // "0xb"
     * string::hexadecimal({'a',{2,2}}, 10) // "0xae13d04acb"
     * string::hexadecimal({'F', {2,4}}, 6, HexCasing::Upper, HexPrefix::Hash) // "#E3FFF0"
     * string::hexadecimal({'1', {1,4}, {'2', {1, 4}, {'c', {1,1}}, 6, HexCasing::Lower, HexPrefix::None) // "121a1c"
     * @endcode
     */
    std::string hexadecimal(GuaranteeMap&& guarantee, unsigned length = 1, HexCasing casing = HexCasing::Lower,
                                   HexPrefix prefix = HexPrefix::ZeroX);

    /**
     * @brief Generates a binary string.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Binary string.
     *
     * @code
     * string::binary(8) // "0b01110101"
     * @endcode
     */
    std::string binary(unsigned length = 1);

    /**
     * @brief Generates a binary string.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Binary string.
     *
     * @code
     * string::binary({'1',{7,8}}, 8) // "0b11110111"
     * @endcode
     */
    std::string binary(GuaranteeMap&& guarantee, unsigned length = 1);

    /**
     * @brief Generates an octal string.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Octal string.
     *
     * @code
     * string::octal(8) // "0o52561721"
     * @endcode
     */
    std::string octal(unsigned length = 1);

    /**
     * @brief Generates an octal string.
     *
     * @param guarantee A map specifying char count constraints if any
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Octal string.
     *
     * @code
     * string::octal({'4',{4,5}}, 8) // "0o42444041"
     * @endcode
     */
    std::string octal(GuaranteeMap&& guarantee, unsigned length = 1);
}
