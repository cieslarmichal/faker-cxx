#ifndef FAKER_STRING_H
#define FAKER_STRING_H

#include <faker/types/hex.h>
#include <limits>
#include <string>
#include <vector>

namespace faker::string {

enum class string_case { mixed, lower, upper };

struct Spec {
    char c;
    unsigned min_count { std::numeric_limits<unsigned>::min() };
    unsigned max_count { std::numeric_limits<unsigned>::max() };
};

/**
 * @brief Generates the least required string for a given specs map
 *
 * @returns least required std::string
 *
 * @param specs A std::unordered_map<char,CharCount> which stores the specs specified by the
 * user
 *
 * @code
 * std::vector<Spec> specs { {'0',{3,10}},{'a',{6,8}} }; // "000aaaaaa"
 * faker::generate(specs);
 * @endcode
 */
std::string generate(const std::vector<Spec>& specs);

/**
 * @brief Generates an Universally Unique Identifier with version 4.
 *
 * @returns UUIDv4.
 *
 * @code
 * string::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
 * @endcode
 */
std::string uuid();

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
 * @param specs A map specifying char count constraints if any
 * @param length The number of characters to generate. Defaults to `10`.
 *
 * @returns Sample string.
 *
 * @code
 * string::sample({}) // "Zo!.:*e>wR"
 * string::sample({{'|' ,{2,2}},{'^',{0,0}},{':',{1,8}}}, 8) // "|6Bye8:|"
 * @endcode
 */
std::string sample(const std::vector<Spec>& specs, unsigned length = 10);

/**
 * @brief Generates a string consisting of given characters.
 *
 * @param allowed_chars The characters to generate string with.
 * @param length The number of characters to generate. Defaults to `1`.
 *
 * @returns string from characters.
 *
 * @code
 * string::from_chars("abc") // "b"
 * string::from_chars("qwerty", 5) // "qrwqt"
 * @endcode
 */
std::string from_chars(const std::string& allowed_chars, unsigned length = 1);

/**
 * @brief Generates a string consisting of given characters.
 *
 * @param specs A map specifying char count constraints if any
 * @param allowed_chars The characters to generate string with.
 * @param length The number of characters to generate. Defaults to `1`.
 *
 * @returns string from characters.
 *
 * @code
 * string::from_chars({}, "abc") // "b"
 * string::from_chars({{'q',{2,2}},{'e',{1,5}}}, "qwerty", 8) // "yqreqety"
 * @endcode
 */
std::string from_chars(
    const std::vector<Spec>& specs, const std::string& allowed_chars, unsigned length = 1);

/**
 * @brief Generates a string consisting of letters in the English alphabet.
 *
 * @param length The number of characters to generate. Defaults to `1`.
 * @param casing The casing of the characters. Defaults to `string_case::mixed`.
 * @param excluded_chars The characters to be excluded from the string to generate. Defaults
 * to ``.
 *
 *
 * @returns Alpha string.
 *
 * @code
 * string::alpha() // "b"
 * string::alpha(5, string_case::upper) // "DTCIC"
 * string::alpha(4, string_case::lower) // "brpt"
 * @endcode
 */
std::string alpha(unsigned length = 1, string_case casing = string_case::mixed,
    const std::string& excluded_chars = "");

/**
 * @brief Generates a string consisting of letters in the English alphabet.
 *
 * @param specs A map specifying char count constraints if any
 * @param length The number of characters to generate. Defaults to `1`.
 * @param casing The casing of the characters. Defaults to `string_case::mixed`.
 *
 * @returns Alpha string.
 *
 * @code
 * string::alpha({}) // "b"
 * string::alpha({{'A',{2,2}}, 5, string_case::upper) // "DACAC"
 * string::alpha({{'a',{0,0}},{'b',{3,3}},{'c', {0,2}}}, 10, string_case::lower) //
 * "bicnmmkbbp"
 * @endcode
 */
std::string alpha(
    const std::vector<Spec>& specs, unsigned length = 1, string_case casing = string_case::mixed);

/**
 * @brief Generates a string consisting of alpha characters and digits.
 *
 * @param length The number of characters to generate. Defaults to `1`.
 * @param casing The casing of the characters. Defaults to `string_case::mixed`.
 * @param excluded_chars The characters to be excluded from alphanumeric characters to
 * generate string from. Defaults to ``.
 *
 * @returns Alphanumeric string.
 *
 * @code
 * string::alphanumeric() // "4"
 * string::alphanumeric(5, string_case::upper) // "3e5V7"
 * string::alphanumeric(4, string_case::lower) // "1nrq"
 * @endcode
 */
std::string alphanumeric(unsigned length = 1, string_case casing = string_case::mixed,
    const std::string& excluded_chars = "");

/**
 * @brief Generates a string consisting of alpha characters and digits.
 *
 * @param specs A map specifying char count constraints if any
 * @param length The number of characters to generate. Defaults to `1`.
 * @param casing The casing of the characters. Defaults to `string_case::mixed`.
 *
 * @returns Alphanumeric string.
 *
 * @code
 * string::alphanumeric({}) // "4"
 * string::alphanumeric({{'A', {3,6}},{'1', {1,1}}, 5, string_case::upper) // "1EAAA"
 * string::alphanumeric({{'a',{0,2}},{'2',{0,3}},{'z',{3,5}}}, 10, string_case::lower) //
 * "z1naazrqz0"
 * @endcode
 */
std::string alphanumeric(
    const std::vector<Spec>& specs, unsigned length = 1, string_case casing = string_case::mixed);

/**
 * @brief Generates a given length string of digits.
 *
 * @param length The number of digits to generate. Defaults to `1`.
 * @param allow_leading_zeroes Whether leading zeros are allowed or not. Defaults to `true`.
 *
 * @returns Numeric string.
 *
 * @code
 * string::numeric() // "1"
 * string::numeric(6) // "035742"
 * string::numeric(6, false) // "254429"
 * @endcode
 */
std::string numeric(unsigned length = 1, bool allow_leading_zeroes = true);

/**
 * @brief Generates a given length string of digits.
 *
 * @param specs A map specifying char count constraints if any
 * @param length The number of digits to generate. Defaults to `1`.
 * @param allow_leading_zeroes Whether leading zeros are allowed or not. Defaults to `true`.
 *
 * @returns Numeric string.
 *
 * @code
 * string::numeric({}) // "1"
 * string::numeric({'5',{3,6}}, 6) // "055542"
 * string::numeric({'0',{0,0}}, {'4',{1,1}}, 6, false) // "854829"
 * @endcode
 */
std::string numeric(
    const std::vector<Spec>& specs, unsigned length = 1, bool allow_leading_zeroes = true);

/**
 * @brief Generates a hexadecimal string.
 *
 * @param length The number of digits to generate. Defaults to `1`.
 * @param casing Casing of the generated string. Defaults to `hex_case::lower`.
 * @param prefix Prefix for the generated string. Defaults to `0x`.
 *
 * @returns Hexadecimal string.
 *
 * @code
 * string::hexadecimal() // "0xb"
 * string::hexadecimal(10) // "0xae13d044cb"
 * string::hexadecimal(6, hex_case_t::upper, hex_prefix_t::hash) // "#E3F380"
 * string::hexadecimal(6, hex_case_t::lower, hex_prefix_t::none) // "e3f380"
 * @endcode
 */
std::string hexadecimal(unsigned length = 1, hex_case_t casing = hex_case_t::lower,
    hex_prefix_t prefix = hex_prefix_t::zero_x);

/**
 * @brief Generates a hexadecimal string.
 *
 * @param specs A map specifying char count constraints if any
 * @param length The number of digits to generate. Defaults to `1`.
 * @param casing Casing of the generated string. Defaults to `hex_case_t::lower`.
 * @param prefix Prefix for the generated string. Defaults to `0x`.
 *
 * @returns Hexadecimal string.
 *
 * @code
 * string::hexadecimal({}) // "0xb"
 * string::hexadecimal({'a',{2,2}}, 10) // "0xae13d04acb"
 * string::hexadecimal({'F', {2,4}}, 6, hex_case_t::upper, hex_prefix_t::hash) // "#E3FFF0"
 * string::hexadecimal({'1', {1,4}, {'2', {1, 4}, {'c', {1,1}}, 6, hex_case_t::lower,
 * hex_prefix_t::none) // "121a1c"
 * @endcode
 */
std::string hexadecimal(const std::vector<Spec>& specs, unsigned length = 1,
    hex_case_t casing = hex_case_t::lower, hex_prefix_t prefix = hex_prefix_t::zero_x);

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
 * @param specs A map specifying char count constraints if any
 * @param length The number of digits to generate. Defaults to `1`.
 *
 * @returns Binary string.
 *
 * @code
 * string::binary({'1',{7,8}}, 8) // "0b11110111"
 * @endcode
 */
std::string binary(const std::vector<Spec>& specs, unsigned length = 1);

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
 * @param specs A map specifying char count constraints if any
 * @param length The number of digits to generate. Defaults to `1`.
 *
 * @returns Octal string.
 *
 * @code
 * string::octal({'4',{4,5}}, 8) // "0o42444041"
 * @endcode
 */
std::string octal(const std::vector<Spec>& specs, unsigned length = 1);
}

#endif