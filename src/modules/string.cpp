#include "../common/helper.h"
#include "string_data.h"
#include <cassert>
#include <faker/number.h>
#include <faker/string.h>
#include <random>
#include <stdexcept>
#include <unordered_map>

namespace faker::string {

std::string_view hexPrefixToStringMapping(HexPrefix prefix)
{
    switch (prefix) {
    case HexPrefix::ZeroX:
        return "0x";
    case HexPrefix::Hash:
        return "#";
    case HexPrefix::None:
        return "";
    default:
        assert(false && "Invalid hex prefix");
        return "";
    }
}

bool is_valid_guarantee(
    GuaranteeMap& guarantee, std::unordered_set<char>& targetCharacters, unsigned int length)
{
    unsigned int atleastCountSum {};
    unsigned int atmostCountSum {};
    for (auto& it : guarantee) {
        // if a char in guarantee is not in char set, it is an invalid guarantee
        if (targetCharacters.find(it.first) == targetCharacters.end())
            return false;
        atleastCountSum += it.second.atleastCount;
        atmostCountSum += it.second.atmostCount;
    }
    // if atleastCount sums up greater than total length of string, it is an invalid guarantee
    // if all chars in targetCharacters are mapped in guarantee, we need to check for validity of
    // atmostCount if atmostCount sumps up less than total length of string, it in an invalid
    // guarantee
    if (atleastCountSum > length
        || (guarantee.size() == targetCharacters.size() && atmostCountSum < length))
        return false;
    return true;
}

std::string generateAtleastString(const GuaranteeMap& guarantee)
{
    std::string result;
    for (auto& it : guarantee) {
        result += std::string(it.second.atleastCount, it.first);
    }
    return result;
}

std::string generateStringWithGuarantee(
    GuaranteeMap& guarantee, std::unordered_set<char>& targetCharacters, unsigned int length)
{
    std::string output {};
    output += generateAtleastString(guarantee);
    // string with least required chars cannot be greater than the total length
    assert(output.size() <= length);
    // we will generate chars for remaining length only
    length -= static_cast<unsigned>(output.size());
    for (unsigned i = 0; i < length; ++i) {
        char generatedChar;
        // generate chars till we find a usable char
        while (true) {
            // pick random char from targetCharacters
            generatedChar = Helper::setElement(targetCharacters);

            auto it = guarantee.find(generatedChar);
            // if no constraint on generated char, break out of loop
            if (it == guarantee.end())
                break;
            auto remainingUses = it->second.atmostCount - it->second.atleastCount;
            if (remainingUses > 0) {
                // decrement no of possible uses as we will use it right now
                --it->second.atmostCount;
                break;
            }
            // remove this char from targetCharacters as it is no longer valid and regenerate char
            else {
                targetCharacters.erase(it->first);
            }
        }
        output += generatedChar;
    }
    // shuffle the generated string as the atleast string generated earlier was not generated
    // randomly
    output = Helper::shuffleString(output);
    return output;
}

template <typename T> class RandomGenerator {
public:
    RandomGenerator()
        : generator_ { T(std::random_device {}()) }
    {
    }
    ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = default;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = default;
    RandomGenerator& operator=(RandomGenerator&&) = default;

    int operator()(std::uniform_int_distribution<>& dist) { return dist(generator_); }

private:
    T generator_;
};

template <typename T = std::mt19937>
std::string uuid(RandomGenerator<T> gen = RandomGenerator<std::mt19937> {})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);
    static std::string_view hexCharacters { "0123456789abcdef" };

    std::string result;
    result.reserve(36);

    for (int i = 0; i < 8; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    for (int i = 0; i < 4; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    result.append(1, '4');
    for (int i = 0; i < 3; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    result.append(1, hexCharacters[gen(dist2)]);
    for (int i = 0; i < 3; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    for (int i = 0; i < 12; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    };

    return result;
}

std::string uuid()
{
    static RandomGenerator<std::mt19937> gen;

    return uuid(gen);
}

std::string sample(unsigned int length)
{
    std::string sample;

    for (unsigned i = 0; i < length; i++) {
        sample += static_cast<char>(number::integer(33, 125));
    }

    return sample;
}

std::string sample(GuaranteeMap&& guarantee, unsigned int length)
{
    auto targetCharacters = data::utf16CharSet;
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string from_chars(const std::string& characters, unsigned int length)
{
    std::string result;

    for (unsigned i = 0; i < length; i++) {
        result += Helper::arrayElement(characters);
    }

    return result;
}

std::string from_chars(GuaranteeMap&& guarantee, const std::string& characters, unsigned length)
{
    std::unordered_set<char> targetCharacters;
    for (auto character : characters) {
        targetCharacters.insert(character);
    }
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alpha(unsigned length, StringCasing casing, const std::string& excludeCharacters)
{
    static const std::unordered_map<StringCasing, std::string_view>
        stringCasingToAlphaCharactersMapping {
            { StringCasing::Lower, data::lowerCharacters },
            { StringCasing::Upper, data::upperCharacters },
            { StringCasing::Mixed, data::mixedAlphaCharacters },
        };

    const auto& alphaCharacters = stringCasingToAlphaCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& character : alphaCharacters) {
        if (excludeCharacters.find(character) == std::string::npos) {
            targetCharacters += character;
        }
    }

    std::string alpha;

    for (unsigned i = 0; i < length; i++) {
        alpha += Helper::arrayElement(targetCharacters);
    }

    return alpha;
}

std::string alpha(GuaranteeMap&& guarantee, unsigned int length, StringCasing casing)
{
    auto targetCharacters = data::stringCasingToAlphaCharSetMapping.at(casing);
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alphanumeric(
    unsigned int length, StringCasing casing, const std::string& excludeCharacters)
{
    static const std::unordered_map<StringCasing, std::string_view>
        stringCasingToAlphanumericCharactersMapping {
            { StringCasing::Lower, data::lowerAlphanumericCharacters },
            { StringCasing::Upper, data::upperAlphanumericCharacters },
            { StringCasing::Mixed, data::mixedAlphanumericCharacters },
        };

    const auto& alphanumericCharacters = stringCasingToAlphanumericCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& alphanumericCharacter : alphanumericCharacters) {
        if (excludeCharacters.find(alphanumericCharacter) == std::string::npos) {
            targetCharacters += alphanumericCharacter;
        }
    }

    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++) {
        alphanumeric += Helper::arrayElement(targetCharacters);
    }

    return alphanumeric;
}

std::string alphanumeric(GuaranteeMap&& guarantee, unsigned length, StringCasing casing)
{
    auto targetCharacters = data::digitSet;
    auto charSet = data::stringCasingToAlphaCharSetMapping.at(casing);
    targetCharacters.merge(charSet);
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string numeric(unsigned int length, bool allowLeadingZeros)
{
    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++) {
        if (i == 0 && allowLeadingZeros) {
            alphanumeric += Helper::arrayElement(data::numericCharacters);
        } else {
            alphanumeric += Helper::arrayElement(data::numericCharactersWithoutZero);
        }
    }

    return alphanumeric;
}

std::string numeric(GuaranteeMap&& guarantee, const unsigned length, bool allowLeadingZeros)
{
    // if leading zero not allowed, atleastCount of '0' cannot be equal to length
    if (!allowLeadingZeros) {
        auto it = guarantee.find('0');
        if (it != guarantee.end() && it->second.atleastCount > length - 1) {
            throw std::invalid_argument { "Invalid guarantee." };
        }
    }
    auto targetCharacters = data::digitSet;
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    if (allowLeadingZeros)
        return generateStringWithGuarantee(guarantee, targetCharacters, length);
    // if leading zero not allowed, pick first digit a non zero
    else {
        auto firstChar = std::to_string(number::integer(1, 9));
        auto it = guarantee.find(firstChar[0]);
        if (it != guarantee.end()) {
            // decrement possible number of uses as we just used it as first char
            --it->second.atmostCount;
        }
        return firstChar + generateStringWithGuarantee(guarantee, targetCharacters, length - 1);
    }
}

std::string hexadecimal(unsigned int length, HexCasing casing, HexPrefix prefix)
{
    auto hexadecimalPrefix = hexPrefixToStringMapping(prefix);

    std::string hexadecimal;
    hexadecimal.reserve(length + hexadecimalPrefix.size());
    hexadecimal += hexadecimalPrefix;

    switch (casing) {
    case HexCasing::Lower:
        for (unsigned i = 0; i < length; i++) {
            hexadecimal += Helper::arrayElement(data::hexLowerCharacters);
        }
        break;
    case HexCasing::Upper:
        for (unsigned i = 0; i < length; i++) {
            hexadecimal += Helper::arrayElement(data::hexUpperCharacters);
        }
        break;
    default:
        assert(false && "Invalid hex casing");
    }

    return hexadecimal;
}

std::string hexadecimal(
    GuaranteeMap&& guarantee, unsigned int length, HexCasing casing, HexPrefix prefix)
{
    static const std::unordered_map<HexCasing, std::unordered_set<char>> hexCasingToCharSetMapping {
        { HexCasing::Lower, data::hexLowerCharSet },
        { HexCasing::Upper, data::hexUpperCharSet },
    };

    std::unordered_set<char> targetCharacters = hexCasingToCharSetMapping.at(casing);
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }
    std::string result { hexPrefixToStringMapping(prefix) };
    return result + generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string binary(unsigned int length)
{
    std::string binaryNumber;
    for (unsigned int i = 0; i < length; ++i) {
        binaryNumber += static_cast<char>(number::integer(1));
    }
    return "0b" + binaryNumber;
}

std::string binary(GuaranteeMap&& guarantee, unsigned int length)
{
    // numbers used by binary representation
    std::unordered_set<char> targetCharacters { '0', '1' };
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return "0b" + generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string octal(unsigned int length)
{
    std::string octalNumber;
    for (unsigned int i = 0; i < length; ++i) {
        octalNumber += static_cast<char>(number::integer(7));
    }
    return "0o" + octalNumber;
}
std::string octal(GuaranteeMap&& guarantee, unsigned int length)
{
    // numbers used by octal representation
    std::unordered_set<char> targetCharacters { '0', '1', '2', '3', '4', '5', '6', '7' };
    // throw if guarantee is invalid
    if (!is_valid_guarantee(guarantee, targetCharacters, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return "0o" + generateStringWithGuarantee(guarantee, targetCharacters, length);
}

}
