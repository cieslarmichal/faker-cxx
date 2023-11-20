#include "faker-cxx/String.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>

#include "data/Characters.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

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

bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length)
{
    unsigned int atleastCountSum{};
    unsigned int atmostCountSum{};
    for (auto& it : guarantee)
    {
        // if a char in guarantee is not in char set, it is an invalid guarantee
        if (targetCharacters.find(it.first) == targetCharacters.end())
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

std::string generateAtleastString(const GuaranteeMap& guarantee)
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

std::string String::binary(GuaranteeMap&& guarantee, unsigned int length)
{
    std::set<char> targetCharacters{'0', '1'};
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
    for (unsigned i = 0; i < length; ++i)
    {
        char generatedChar;
        // generate chars till we find a usable char
        while (true)
        {
            // pick random char from targetCharacters
            std::mt19937 gen(std::random_device{}());
            std::sample(targetCharacters.begin(), targetCharacters.end(), &generatedChar, 1, gen);

            auto it = guarantee.find(generatedChar);
            // if no constraint on generated char, break out of loop
            if (it == guarantee.end())
                break;
            auto remainingUses = it->second.atmostCount - it->second.atleastCount;
            if (remainingUses > 0)
            {
                // decrement no of possible uses as we will use it right now
                --it->second.atmostCount;
                break;
            }
            // remove this char from targetCharacters as it is no longer valid and regenerate char
            else
            {
                targetCharacters.erase(it->first);
            }
        }
        binary += generatedChar;
    }
    // shuffle the generated string as the atleast string generated earlier was not generated randomly
    binary = Helper::shuffleString(binary);
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
