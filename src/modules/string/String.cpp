#include "faker-cxx/String.h"

#include <iostream>
#include <map>
#include <random>

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

std::string String::binary(unsigned int length)
{
    std::string binary{"0b"};

    for (unsigned i = 0; i < length; i++)
    {
        binary += static_cast<char>(Number::integer(1));
    }

    return binary;
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
