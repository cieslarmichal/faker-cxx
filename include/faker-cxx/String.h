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
     * @brief Generated an Universally Unique Identifier with version 4.
     *
     * @returns UUIDv4
     *
     * @code
     * Person::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
     * @endcode
     */
    static std::string uuid();

    /**
     * @brief Generating a string consisting of letters in the English alphabet.
     *
     * @param length The number of characters to generate. Defaults to `1`
     * @param casing The casing of the characters. Defaults to `'Mixed'`.
     *
     * @returns Alpha string
     *
     * @code
     * Person::alpha() // "b"
     * Person::alpha(5, StringCasing::Upper) // "DTCIC"
     * Person::alpha(4, StringCasing::Lower) // "AGQT"
     * @endcode
     */
    static std::string alpha(unsigned length = 1, StringCasing casing = StringCasing::Mixed);
};
}
