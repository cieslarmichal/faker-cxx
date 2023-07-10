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
     * Person::alpha() // "b"
     * Person::alpha(5, StringCasing::Upper) // "DTCIC"
     * Person::alpha(4, StringCasing::Lower) // "brpt"
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
     * Person::alphanumeric() // "4"
     * Person::alphanumeric(5, StringCasing::Upper) // "3e5V7"
     * Person::alphanumeric(4, StringCasing::Lower) // "1nrq"
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
     * Person::numeric() // "1"
     * Person::numeric(6) // "035742"
     * Person::numeric(6, false) // "254429"
     * @endcode
     */
    static std::string numeric(unsigned length = 1, bool allowLeadingZeros = true);
};
}
