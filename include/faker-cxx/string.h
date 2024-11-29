#pragma once

#include <chrono>
#include <iomanip>
#include <limits>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <time.h>

#include "faker-cxx/export.h"
#include "helpers/ulid/ulid.h"
#include "random_generator.h"
#include "types/uuid.h"

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

/**
 * Specify the count required for specific chars
 */
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

#pragma region UUID_IMPLEMENTATIONS

template <typename T = std::mt19937>
std::string uuidV1(RandomGenerator<T> gen = RandomGenerator<T>{})
{
    // Get current timestamp in 100-nanosecond intervals since UUID epoch (15 Oct 1582)
    const uint64_t UUID_EPOCH_OFFSET =
        0x01B21DD213814000ULL; // Number of 100-ns intervals between UUID epoch and Unix epoch
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();

    // Adjusted to use microseconds
    uint64_t timestamp =
        UUID_EPOCH_OFFSET +
        static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(since_epoch).count() * 10);

    // Generate clock sequence (14 bits)
    std::uniform_int_distribution<uint16_t> clock_seq_dist(0, 0x3FFF);
    uint16_t clock_seq = gen(clock_seq_dist);

    // Generate node identifier (48 bits)
    std::uniform_int_distribution<uint64_t> node_dist(0, 0xFFFFFFFFFFFFULL);
    uint64_t node = gen(node_dist) & 0xFFFFFFFFFFFFULL;

    // Extract time components
    uint32_t time_low = static_cast<uint32_t>(timestamp & 0xFFFFFFFFULL);
    uint16_t time_mid = static_cast<uint16_t>((timestamp >> 32) & 0xFFFFULL);
    uint16_t time_hi_and_version = static_cast<uint16_t>((timestamp >> 48) & 0x0FFFULL);
    time_hi_and_version |= (1 << 12); // Set the version number to 1

    // Clock sequence fields
    uint8_t clock_seq_low = clock_seq & 0xFF;
    uint8_t clock_seq_hi_and_reserved = ((clock_seq >> 8) & 0x3F) | 0x80; // Set the variant to '10'

    // Format UUID string
    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    ss << std::setw(8) << time_low << '-';
    ss << std::setw(4) << time_mid << '-';
    ss << std::setw(4) << time_hi_and_version << '-';
    ss << std::setw(2) << static_cast<int>(clock_seq_hi_and_reserved);
    ss << std::setw(2) << static_cast<int>(clock_seq_low) << '-';
    ss << std::setw(12) << std::setw(12) << node;

    return ss.str();
}

template <typename T = std::mt19937>
std::string uuidV4(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
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

#pragma endregion

/**
 * @brief Generates an Universally Unique Identifier, defaults to V4.
 *
 * @param gen A random number generator (type RandomGenerator)
 *
 * @returns UUID.
 *
 * @code
 * faker::string::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
 * @endcode
 */
template <typename T = std::mt19937>
std::string uuid(RandomGenerator<T> gen)
{
    return uuid(Uuid::V4, gen);
}

/**
 * @brief Generates an Universally Unique Identifier, defaults to V4.
 *
 * @param gen A random number generator (type RandomGenerator)
 *
 * @returns UUID.
 *
 * @code
 * faker::string::uuid() // "27666229-cedb-4a45-8018-98b1e1d921e2"
 * @endcode
 */
template <typename T = std::mt19937>
std::string uuid(Uuid uuid = Uuid::V4, RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    switch (uuid)
    {
    case Uuid::V1:
        return uuidV1(gen);
    case Uuid::V2:
        return uuidV4(gen);
    case Uuid::V3:
        return uuidV4(gen);
    case Uuid::V4:
        return uuidV4(gen);
    case Uuid::V5:
        return uuidV4(gen);
    case Uuid::V6:
        return uuidV4(gen);
    case Uuid::V7:
        return uuidV4(gen);
    case Uuid::V8:
        return uuidV4(gen);
    default:
        return uuidV4(gen);
    }
}

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
FAKER_CXX_EXPORT std::string ulid(time_t refDate = std::time(nullptr)); // Based on https://github.com/suyash/ulid

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