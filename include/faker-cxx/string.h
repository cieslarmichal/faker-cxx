#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <limits>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "random_generator.h"

namespace faker::string
{
enum class StringCasing
{
    Mixed,
    Lower,
    Upper
};

struct FAKER_CXX_EXPORT CharCount
{
    unsigned int atLeastCount{(std::numeric_limits<unsigned>::min)()};
    unsigned int atMostCount{(std::numeric_limits<unsigned>::max)()};
};

using GuaranteeMap = std::map<char, CharCount>;

/**
 * @brief Checks if the given guarantee map is valid for given targetCharacters and length.
 *
 * @param guarantee A std::map that maps the count range of specific characters required
 * @param targetCharacters A std::string consisting of all chars available for that string generating function
 * @param length The number of characters to generate.
 *
 * @returns A bool.
 *
 * @code
 * GuaranteeMap guarantee = {{'0',{5,10}},{'1',{6,10}}};
 * std::string targetCharacters = "01";
 * unsigned int length = 10;
 * faker::string::isValidGuarantee(guarantee,targetCharacters,length) // false
 * @endcode
 */
FAKER_CXX_EXPORT bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned length);

/**
 * @brief Generates the least required string for a given guarantee map.
 *
 * @param guarantee A std::map<char,CharCount> which stores the guarantee specified by the user
 *
 * @returns Least required std::string.
 *
 * @code
 * GuaranteeMap guarantee { {'0',{3,10}},{'a',{6,8}} }; // "000aaaaaa"
 * faker::string::generateAtLeastString(guarantee);
 * @endcode
 */
FAKER_CXX_EXPORT std::string generateAtLeastString(const GuaranteeMap& guarantee);

/**
 * @brief Generates an Universally Unique Identifier version 1.
 *
 * @returns UUID v1.
 *
 * @code
 * faker::string::uuidV1() // "29915d84-c5e8-11ef-9cd2-0242ac120002"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV1();

/**
 * @brief Generates an Universally Unique Identifier version 3.
 *
 * @returns UUID V3.
 *
 * @code
 * faker::string::uuidV3() // "c6437ef1-5b86-3a4e-a071-c2d4ad414e65"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV3();

/**
 * @brief Generates an Universally Unique Identifier version 4.
 *
 * @returns UUID V4.
 *
 * @code
 * faker::string::uuidV4() // "78754621-9544-4c79-9c1d-76d3ba881f53"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV4();

/**
 * @brief Generates an Universally Unique Identifier version 5.
 *
 * @returns UUID V5.
 *
 * @code
 * faker::string::uuidV5("hello") // "6c7f25c1-1f94-53df-aab6-627ed664b1a7"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV5(const std::string& input,
                                    const std::string& namespaceUuid = "dbedb1fb-a628-49f3-9e4d-58166108df5f");

/**
 * @brief Generates an Universally Unique Identifier version 6.
 *
 * @returns UUID V6.
 *
 * @code
 * faker::string::uuidV6() // "1efc5e90-f32e-6420-bab1-7bdb35fa2abb"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV6();

/**
 * @brief Generates an Universally Unique Identifier version 7.
 *
 * @returns UUID V7.
 *
 * @code
 * faker::string::uuidV7() // "0194129b-f344-783c-ab87-d1a79bcf9a4e"
 * @endcode
 */
FAKER_CXX_EXPORT std::string uuidV7();

/**
 * @brief Generates an Universally Unique Lexicographically Sortable Identifier.
 *
 * @param refDate A reference date (type time_t)
 *
 * @returns ULID UINT128.
 *
 * @code
 * faker::string::ulid() // "0001C7STHC0G2081040G208104"
 * faker::string::ulid(1484581420) // "0001C7STHC0G2081040G208104"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ulid(time_t refDate = std::time(nullptr));

/**
 * @brief Returns a string containing UTF-16 chars between 33 and 125 (`!` to `}`).
 *
 * @param length The number of characters to generate. Defaults to `10`.
 *
 * @returns Sample string.
 *
 * @code
 * faker::string::sample() // "Zo!.:*e>wR"
 * faker::string::sample(5) // "6Bye8"
 * @endcode
 */
FAKER_CXX_EXPORT std::string sample(unsigned length = 10);

/**
 * @brief Returns a string containing UTF-16 chars between 33 and 125 (`!` to `}`).
 *
 * @param guarantee A map specifying char count constraints if any
 * @param length The number of characters to generate. Defaults to `10`.
 *
 * @returns Sample string.
 *
 * @code
 * faker::string::sample({}) // "Zo!.:*e>wR"
 * faker::string::sample({{'|' ,{2,2}},{'^',{0,0}},{':',{1,8}}}, 8) // "|6Bye8:|"
 * @endcode
 */
FAKER_CXX_EXPORT std::string sample(GuaranteeMap&& guarantee, unsigned length = 10);

/**
 * @brief Returns a string containing "~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/".
 *
 * @param minLength The number of minimum characters to generate. Defaults to `1`.
 * @param maxLength The number of maximum characters to generate. Defaults to `10`.
 *
 * @returns Sample string.
 *
 * @code
 * faker::string::sample() // "#$%^&#$%^&"
 * faker::string::sample(1,5) // "#$%^&"
 * @endcode
 */
FAKER_CXX_EXPORT std::string symbol(unsigned minLength = 1, unsigned maxLength = 10);

/**
 * @brief Generates a string consisting of given characters.
 *
 * @param characters The characters to generate string with.
 * @param length The number of characters to generate. Defaults to `1`.
 *
 * @returns String from characters.
 *
 * @code
 * faker::string::fromCharacters("abc") // "b"
 * faker::string::fromCharacters("qwerty", 5) // "qrwqt"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fromCharacters(const std::string& characters, unsigned length = 1);

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
 * faker::string::fromCharacters({}, "abc") // "b"
 * faker::string::fromCharacters({{'q',{2,2}},{'e',{1,5}}}, "qwerty", 8) // "yqreqety"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fromCharacters(GuaranteeMap&& guarantee, const std::string& characters,
                                            unsigned length = 1);

/**
 * @brief Generates a string consisting of letters in the English alphabet.
 *
 * @param length The number of characters to generate. Defaults to `1`.
 * @param casing The casing of the characters. Defaults to `StringCasing::Mixed`.
 * @param excludeCharacters The characters to be excluded from the string to generate. Defaults to ``.
 *
 * @returns Alpha string.
 *
 * @code
 * faker::string::alpha() // "b"
 * faker::string::alpha(5, StringCasing::Upper) // "DTCIC"
 * faker::string::alpha(4, StringCasing::Lower) // "brpt"
 * @endcode
 */
FAKER_CXX_EXPORT std::string alpha(unsigned length = 1, StringCasing casing = StringCasing::Mixed,
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
 * faker::string::alpha({}) // "b"
 * faker::string::alpha({{'A',{2,2}}, 5, StringCasing::Upper) // "DACAC"
 * faker::string::alpha({{'a',{0,0}},{'b',{3,3}},{'c', {0,2}}}, 10, StringCasing::Lower) // "bicnmmkbbp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string alpha(GuaranteeMap&& guarantee, unsigned length = 1,
                                   StringCasing casing = StringCasing::Mixed);

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
 * faker::string::alphanumeric() // "4"
 * faker::string::alphanumeric(5, StringCasing::Upper) // "3e5V7"
 * faker::string::alphanumeric(4, StringCasing::Lower) // "1nrq"
 * @endcode
 */
FAKER_CXX_EXPORT std::string alphanumeric(unsigned length = 1, StringCasing casing = StringCasing::Mixed,
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
 * faker::string::alphanumeric({}) // "4"
 * faker::string::alphanumeric({{'A', {3,6}},{'1', {1,1}}, 5, StringCasing::Upper) // "1EAAA"
 * faker::string::alphanumeric({{'a',{0,2}},{'2',{0,3}},{'z',{3,5}}}, 10, StringCasing::Lower) // "z1naazrqz0"
 * @endcode
 */
FAKER_CXX_EXPORT std::string alphanumeric(GuaranteeMap&& guarantee, unsigned length = 1,
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
 * faker::string::numeric() // "1"
 * faker::string::numeric(6) // "035742"
 * faker::string::numeric(6, false) // "254429"
 * @endcode
 */
FAKER_CXX_EXPORT std::string numeric(unsigned length = 1, bool allowLeadingZeros = true);

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
 * faker::string::numeric({}) // "1"
 * faker::string::numeric({'5',{3,6}}, 6) // "055542"
 * faker::string::numeric({'0',{0,0}}, {'4',{1,1}}, 6, false) // "854829"
 * @endcode
 */
FAKER_CXX_EXPORT std::string numeric(GuaranteeMap&& guarantee, unsigned length = 1, bool allowLeadingZeros = true);

/**
 * @brief Generates a unique, URL-safe string identifier of the specified length.
 *
 * This function generates a unique identifier using a cryptographically secure
 * random number generator, with the output length set by the `length` parameter.
 *
 * @param length The exact length of the identifier to generate.
 *
 * @returns A unique, URL-safe string identifier of the specified length.
 *
 * @code
 * nanoId(10); // Possible output: "F8aXz1Q4wB"
 * nanoId(21); // Possible output: "V2JlO7GZ1kPl9FxErRqzS"
 * @endcode
 */
FAKER_CXX_EXPORT std::string nanoId(int length);

/**
 * @brief Generates a unique, URL-safe string identifier of default length.
 *
 * This function generates a unique identifier with a default length of 10 characters.
 * The identifier is URL-safe and created using a cryptographically secure
 * random number generator.
 *
 * @returns A unique, URL-safe string identifier of default length (10 characters).
 *
 * @code
 * nanoId(); // Possible output: "Hf5lN8L2wQ"
 * @endcode
 */
FAKER_CXX_EXPORT std::string nanoId();

/**
 * @brief Generates a unique, URL-safe string identifier of random length within a specified range.
 *
 * This function generates a unique identifier with a length that varies between
 * `minLength` and `maxLength`, inclusive. The identifier is URL-safe and created
 * using a cryptographically secure random number generator.
 *
 * @param minLength The minimum length of the identifier.
 * @param maxLength The maximum length of the identifier.
 *
 * @returns A unique, URL-safe string identifier with a length between `minLength` and `maxLength`.
 *
 * @code
 * nanoId(10, 15); // Possible output: "Vb2Ej8G9wPcQ2"
 * nanoId(5, 8);   // Possible output: "P1zZ3x"
 * @endcode
 */
FAKER_CXX_EXPORT std::string nanoId(int minLength, int maxLength);
}
