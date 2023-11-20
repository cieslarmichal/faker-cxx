#include "faker-cxx/String.h"

#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>

#include "data/Characters.h"
#include "faker-cxx/Helper.h"

namespace faker
{
namespace
{
const std::map<StringCasing, std::string> stringCasingToAlphaCharactersMapping{
    {StringCasing::Lower, lowerCharacters},
    {StringCasing::Upper, upperCharacters},
    {StringCasing::Mixed, mixedAlphaCharacters},
};
const std::map<StringCasing, std::string> stringCasingToAlphanumericCharactersMapping{
    {StringCasing::Lower, lowerAlphanumericCharacters},
    {StringCasing::Upper, upperAlphanumericCharacters},
    {StringCasing::Mixed, mixedAlphanumericCharacters},
};
const std::map<HexCasing, std::string> hexCasingToCharactersMapping{
    {HexCasing::Lower, hexLowerCharacters},
    {HexCasing::Upper, hexUpperCharacters},
};
const std::map<HexPrefix, std::string> hexPrefixToStringMapping{
    {HexPrefix::ZeroX, "0x"},
    {HexPrefix::Hash, "#"},
    {HexPrefix::None, ""},
};
}

bool isValidGuarantee(std::map<char, CharCount>& guarantee, std::string& targetCharacters, unsigned int length)
{
    unsigned int atleastCountSum{};
    unsigned int atmostCountSum{};
    for (auto& it : guarantee)
    {
        // if a char in guarantee is not in char set, it is an invalid guarantee
        if (targetCharacters.find(it.first) == std::string::npos)
            return false;
        atleastCountSum += it.second.atleastCount;
        atmostCountSum += it.second.atmostCount;
    }
    // if atleastCount sums up greater than total length of string, it is an invalid guarantee
    // if all chars in targetCharacters are mapped in guarantee, we need to check for validity of atmostCount
    // if atmostCount sumps up less than total length of string, it in an invalid guarantee
    if (atleastCountSum > length || (guarantee.size() == targetCharacters.size() && atmostCountSum < length))
        return false;
    return true;
}

std::string generateAtleastString(const std::map<char, CharCount>& guarantee)
{
    std::string result;
    for (auto& it : guarantee)
        result += std::string(it.second.atleastCount, it.first);
    return result;
}

std::string String::sample(unsigned int length)
{
    std::string sample;

    for (unsigned i = 0; i < length; i++)
    {
        sample += static_cast<char>(Number::integer(33, 125));
    }

    return sample;
}

std::string String::fromCharacters(const std::string& characters, unsigned int length)
{
    std::string result;

    for (unsigned i = 0; i < length; i++)
    {
        result += Helper::arrayElement<char>(characters);
    }

    return result;
}

std::string String::alpha(unsigned length, StringCasing casing)
{
    const auto& targetCharacters = stringCasingToAlphaCharactersMapping.at(casing);

    std::string alpha;

    for (unsigned i = 0; i < length; i++)
    {
        alpha += Helper::arrayElement<char>(targetCharacters);
    }

    return alpha;
}

std::string String::alphanumeric(unsigned int length, StringCasing casing, const std::string& excludeCharacters)
{
    const auto& alphanumericCharacters = stringCasingToAlphanumericCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& alphanumericCharacter : alphanumericCharacters)
    {
        if (excludeCharacters.find(alphanumericCharacter) == std::string::npos)
        {
            targetCharacters += alphanumericCharacter;
        }
    }

    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++)
    {
        alphanumeric += Helper::arrayElement<char>(targetCharacters);
    }

    return alphanumeric;
}

std::string String::numeric(unsigned int length, bool allowLeadingZeros)
{
    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++)
    {
        if (i == 0 && allowLeadingZeros)
        {
            alphanumeric += Helper::arrayElement<char>(numericCharacters);
        }
        else
        {
            alphanumeric += Helper::arrayElement<char>(numericCharactersWithoutZero);
        }
    }

    return alphanumeric;
}

std::string String::hexadecimal(unsigned int length, HexCasing casing, HexPrefix prefix)
{
    const auto& hexadecimalCharacters = hexCasingToCharactersMapping.at(casing);

    const auto& hexadecimalPrefix = hexPrefixToStringMapping.at(prefix);

    std::string hexadecimal{hexadecimalPrefix};

    for (unsigned i = 0; i < length; i++)
    {
        hexadecimal += Helper::arrayElement<char>(hexadecimalCharacters);
    }

    return hexadecimal;
}

std::string String::binary(std::map<char, CharCount>&& guarantee, unsigned int length)
{
    std::string targetCharacters{"01"};
    // throw if guarantee is invalid
    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    std::string binary{};
    binary += generateAtleastString(guarantee);
    // string with least required chars cannot be greater than the total length
    assert(binary.size() <= length);
    // we will generate chars for remaining length only
    length -= binary.size();
    for (unsigned i = 0; i < length; i++)
    {
        binary += static_cast<char>(Number::integer(1));
    }
    // TODO shuffle `binary`

    return "0b" + binary;
}

std::string String::octal(unsigned int length)
{
    std::string octal{"0o"};

    for (unsigned i = 0; i < length; i++)
    {
        octal += static_cast<char>(Number::integer(7));
    }

    return octal;
}
}
