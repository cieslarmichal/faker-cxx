#include "String.h"

#include <Helper.h>
#include <map>
#include <random>
#include <sstream>

namespace faker
{
namespace
{
const std::string upperCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string lowerCharacters = "abcdefghijklmnopqrstuvwxyz";
const std::string mixedCharacters = upperCharacters + lowerCharacters;
const std::map<StringCasing, std::string> stringCasingToCharactersMapping{
    {StringCasing::Lower, lowerCharacters},
    {StringCasing::Upper, upperCharacters},
    {StringCasing::Mixed, mixedCharacters},
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
    const auto& targetCharacters = stringCasingToCharactersMapping.at(casing);

    std::string alpha;

    for (unsigned i = 0; i < length; i++)
    {
        alpha += Helper::arrayElement<char>(targetCharacters);
    }

    return alpha;
}
}
