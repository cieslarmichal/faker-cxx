#pragma once

#include <string>

namespace faker
{
enum class StringCasing
{
    Mixed,
    Lower,
    Upper
};

enum class HexStringCasing
{
    Lower,
    Upper
};

enum class HexStringPrefix
{
    ZeroX,
    Hash
};

class String
{
public:
    /**
     * @brief Generates an Universally Unique Identifier with version 4.
     *
     * @returns UUIDv4
     *
     * @code
     * Person::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
     * @endcode
     */
    static std::string uuid();

    /**
     * @brief Generates a string consisting of letters in the English alphabet.
     *
     * @param length The number of characters to generate. Defaults to `1`
     * @param casing The casing of the characters. Defaults to `'Mixed'`.
     *
     * @returns Alpha string
     *
     * @code
     * String::alpha() // "b"
     * String::alpha(5, StringCasing::Upper) // "DTCIC"
     * String::alpha(4, StringCasing::Lower) // "brpt"
     * @endcode
     */
    static std::string alpha(unsigned length = 1, StringCasing casing = StringCasing::Mixed);

    /**
     * @brief Generates a string consisting of alpha characters and digits.
     *
     * @param length The number of characters to generate. Defaults to `1`
     * @param casing The casing of the characters. Defaults to `'Mixed'`.
     *
     * @returns Alphanumeric string
     *
     * @code
     * String::alphanumeric() // "4"
     * String::alphanumeric(5, StringCasing::Upper) // "3e5V7"
     * String::alphanumeric(4, StringCasing::Lower) // "1nrq"
     * @endcode
     */
    static std::string alphanumeric(unsigned length = 1, StringCasing casing = StringCasing::Mixed);

    /**
     * @brief Generates a given length string of digits.
     *
     * @param length The number of digits to generate. Defaults to `1`
     * @param allowLeadingZeros Whether leading zeros are allowed or not. Defaults to `true`
     *
     * @returns Numeric string
     *
     * @code
     * String::numeric() // "1"
     * String::numeric(6) // "035742"
     * String::numeric(6, false) // "254429"
     * @endcode
     */
    static std::string numeric(unsigned length = 1, bool allowLeadingZeros = true);

    /**
     * @brief Generates a hexadecimal string.
     *
     * @param length The number of digits to generate. Defaults to `1`
     * @param casing Casing of the generated string. Defaults to `'Lower'`.
     * @param prefix Prefix for the generated string. Defaults to `'0x'
     *
     * @returns Hexadecimal string
     *
     * @code
     * String::hexadecimal() // "0xb"
     * String::hexadecimal(10) // "0xae13d044cb"
     * String::hexadecimal(6, HexString::Hash, HexStringCasing::Upper) // "#E3F380"
     * @endcode
     */
    static std::string hexadecimal(unsigned length = 1, HexStringCasing casing = HexStringCasing::Lower,
                                   HexStringPrefix prefix = HexStringPrefix::ZeroX);
};
}
