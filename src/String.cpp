#include "String.h"

#include <Helper.h>
#include <map>
#include <random>
#include <sstream>

#include "data/AlphanumericCharacters.h"

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
}

// TODO: refactor
std::string String::uuid()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    std::stringstream ss;
    ss << std::hex;

    for (int i = 0; i < 8; i++)
    {
        ss << dist(gen);
    }

    ss << "-";
    for (int i = 0; i < 4; i++)
    {
        ss << dist(gen);
    }

    ss << "-4";
    for (int i = 0; i < 3; i++)
    {
        ss << dist(gen);
    }

    ss << "-";

    ss << dist2(gen);

    for (int i = 0; i < 3; i++)
    {
        ss << dist(gen);
    }

    ss << "-";

    for (int i = 0; i < 12; i++)
    {
        ss << dist(gen);
    };

    return ss.str();
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

std::string String::alphanumeric(unsigned int length, StringCasing casing)
{
    const auto& targetCharacters = stringCasingToAlphanumericCharactersMapping.at(casing);

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
            alphanumeric += Helper::arrayElement<char>(numericCharactersWithoutZero);
        }
        else
        {
            alphanumeric += Helper::arrayElement<char>(numericCharacters);
        }
    }

    return alphanumeric;
}
}
