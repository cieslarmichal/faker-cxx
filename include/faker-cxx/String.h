#pragma once

#include <iostream>
#include <random>
#include <sstream>
#include <string>

#include "types/Hex.h"
#include "types/RandomGenerator.hpp"

namespace faker
{
enum class StringCasing
{
    Mixed,
    Lower,
    Upper
};

class String
{
public:
    /**
     * @brief Generates an Universally Unique Identifier with version 4.
     *
     * @returns UUIDv4.
     *
     * @param gen A random number generator (type RandomGenerator)
     * @code
     * String::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
     * @endcode
     */
    template <typename T = std::mt19937>
    static std::string uuid(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
    {
        static std::uniform_int_distribution<> dist(0, 15);
        static std::uniform_int_distribution<> dist2(8, 11);

        std::stringstream ss;
        ss << std::hex;

        for (int i = 0; i < 8; i++)
        {
            ss << gen(dist);
        }

        ss << "-";
        for (int i = 0; i < 4; i++)
        {
            ss << gen(dist);
        }

        ss << "-4";
        for (int i = 0; i < 3; i++)
        {
            ss << gen(dist);
        }

        ss << "-";

        ss << gen(dist2);

        for (int i = 0; i < 3; i++)
        {
            ss << gen(dist);
        }

        ss << "-";

        for (int i = 0; i < 12; i++)
        {
            ss << gen(dist);
        };

        return ss.str();
    }

    /**
     * @brief Returns a string containing UTF-16 chars between 33 and 125 (`!` to `}`).
     *
     * @param length The number of characters to generate. Defaults to `10`.
     *
     * @returns Sample string.
     *
     * @code
     * String::sample() // "Zo!.:*e>wR"
     * String::sample(5) // "6Bye8"
     * @endcode
     */
    static std::string sample(unsigned length = 10);

    /**
     * @brief Generates a string consisting of given characters.
     *
     * @param characters The characters to generate string with.
     * @param length The number of characters to generate. Defaults to `1`.
     *
     * @returns String from characters.
     *
     * @code
     * String::fromCharacters("abc") // "b"
     * String::fromCharacters("qwerty", 5) // "qrwqt"
     * @endcode
     */
    static std::string fromCharacters(const std::string& characters, unsigned length = 1);

    /**
     * @brief Generates a string consisting of letters in the English alphabet.
     *
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     *
     * @returns Alpha string.
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
     * @param length The number of characters to generate. Defaults to `1`.
     * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
     * @param excludeCharacters The characters to be excluded from alphanumeric characters to generate string from.
     * Defaults to ``.
     *
     * @returns Alphanumeric string.
     *
     * @code
     * String::alphanumeric() // "4"
     * String::alphanumeric(5, StringCasing::Upper) // "3e5V7"
     * String::alphanumeric(4, StringCasing::Lower) // "1nrq"
     * @endcode
     */
    static std::string alphanumeric(unsigned length = 1, StringCasing casing = StringCasing::Mixed,
                                    const std::string& excludeCharacters = "");

    /**
     * @brief Generates a given length string of digits.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     * @param allowLeadingZeros Whether leading zeros are allowed or not. Defaults to `true`.
     *
     * @returns Numeric string.
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
     * @param length The number of digits to generate. Defaults to `1`.
     * @param casing Casing of the generated string. Defaults to `HexCasing::Lower`.
     * @param prefix Prefix for the generated string. Defaults to `0x`.
     *
     * @returns Hexadecimal string.
     *
     * @code
     * String::hexadecimal() // "0xb"
     * String::hexadecimal(10) // "0xae13d044cb"
     * String::hexadecimal(6, HexCasing::Upper, HexPrefix::Hash) // "#E3F380"
     * String::hexadecimal(6, HexCasing::Lower, HexPrefix::None) // "e3f380"
     * @endcode
     */
    static std::string hexadecimal(unsigned length = 1, HexCasing casing = HexCasing::Lower,
                                   HexPrefix prefix = HexPrefix::ZeroX);

    /**
     * @brief Generates a binary string.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Binary string.
     *
     * @code
     * String::binary(8) // "0b01110101"
     * @endcode
     */
    static std::string binary(unsigned length = 1);

    /**
     * @brief Generates an octal string.
     *
     * @param length The number of digits to generate. Defaults to `1`.
     *
     * @returns Octal string.
     *
     * @code
     * String::octal(8) // "0o52561721"
     * @endcode
     */
    static std::string octal(unsigned length = 1);
};
}
