#include "faker-cxx/string.h"

#include <cassert>
#include <map>
#include <random>
#include <set>
#include <stdexcept>
#include <string>

#include "common/algo_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "string_data.h"

namespace faker::string
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

const std::map<StringCasing, std::set<char>> stringCasingToAlphaCharSetMapping{
    {StringCasing::Lower, lowerCharSet},
    {StringCasing::Upper, upperCharSet},
    {StringCasing::Mixed, mixedAlphaCharSet},
};

std::string generateStringWithGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length)
{
    std::string output{};
    output += generateAtLeastString(guarantee);
    assert(output.size() <= length);
    length -= static_cast<unsigned>(output.size());
    for (unsigned i = 0; i < length; ++i)
    {
        char generatedChar;
        while (true)
        {
            generatedChar = helper::setElement(targetCharacters);

            auto it = guarantee.find(generatedChar);
            if (it == guarantee.end())
                break;
            auto remainingUses = it->second.atMostCount - it->second.atLeastCount;
            if (remainingUses > 0)
            {
                --it->second.atMostCount;
                break;
            }
            else
            {
                targetCharacters.erase(it->first);
            }
        }
        output += generatedChar;
    }

    output = helper::shuffleString(output);

    return output;
}
}

bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length)
{
    unsigned int atLeastCountSum{};
    unsigned int atMostCountSum{};

    for (auto& it : guarantee)
    {
        if (!targetCharacters.contains(it.first))
        {
            return false;
        }

        atLeastCountSum += it.second.atLeastCount;

        atMostCountSum += it.second.atMostCount;
    }

    if (atLeastCountSum > length || (guarantee.size() == targetCharacters.size() && atMostCountSum < length))
    {
        return false;
    }

    return true;
}

std::string generateAtLeastString(const GuaranteeMap& guarantee)
{
    std::string result;

    for (auto& it : guarantee)
    {
        result += std::string(it.second.atLeastCount, it.first);
    }

    return result;
}

std::string sample(unsigned int length)
{
    std::string sample;

    for (unsigned i = 0; i < length; i++)
    {
        sample += static_cast<char>(number::integer(33, 125));
    }

    return sample;
}

std::string sample(GuaranteeMap&& guarantee, unsigned int length)
{
    auto targetCharacters = utf16CharSet;

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string symbol(unsigned int minLength, unsigned int maxLength)
{
    if (minLength > maxLength)
    {
        std::swap(minLength, maxLength);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(minLength, maxLength);

    unsigned int length = dist(gen);

    return fromCharacters(symbolCharacters, length);
}

std::string symbol(unsigned int length)
{
    return fromCharacters(symbolCharacters, length);
}

std::string fromCharacters(const std::string& characters, unsigned int length)
{
    std::string result;

    for (unsigned i = 0; i < length; i++)
    {
        result += helper::randomElement(characters);
    }

    return result;
}

std::string fromCharacters(GuaranteeMap&& guarantee, const std::string& characters, unsigned length)
{
    std::set<char> targetCharacters;

    for (auto character : characters)
    {
        targetCharacters.insert(character);
    }

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alpha(unsigned length, StringCasing casing, const std::string& excludeCharacters)
{
    const auto& alphaCharacters = stringCasingToAlphaCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& character : alphaCharacters)
    {
        if (excludeCharacters.find(character) == std::string::npos)
        {
            targetCharacters += character;
        }
    }

    std::string alpha;

    for (unsigned i = 0; i < length; i++)
    {
        alpha += helper::randomElement(targetCharacters);
    }

    return alpha;
}

std::string alpha(GuaranteeMap&& guarantee, unsigned int length, StringCasing casing)
{
    auto targetCharacters = stringCasingToAlphaCharSetMapping.at(casing);

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alphanumeric(unsigned int length, StringCasing casing, const std::string& excludeCharacters)
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
        alphanumeric += helper::randomElement(targetCharacters);
    }

    return alphanumeric;
}

std::string alphanumeric(GuaranteeMap&& guarantee, unsigned length, StringCasing casing)
{
    auto targetCharacters = digitSet;

    auto charSet = stringCasingToAlphaCharSetMapping.at(casing);

    targetCharacters.merge(charSet);

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string numeric(unsigned int length, bool allowLeadingZeros)
{
    std::string alphanumericStr;
    alphanumericStr.reserve(length);

    for (unsigned i = 0; i < length; i++)
    {
        if (i == 0 && allowLeadingZeros)
        {
            alphanumericStr.push_back(helper::randomElement(numericCharacters));
        }
        else
        {
            alphanumericStr.push_back(helper::randomElement(numericCharactersWithoutZero));
        }
    }

    return alphanumericStr;
}

std::string numeric(GuaranteeMap&& guarantee, const unsigned length, bool allowLeadingZeros)
{
    if (!allowLeadingZeros)
    {
        auto it = guarantee.find('0');
        if (it != guarantee.end() && it->second.atLeastCount > length - 1)
        {
            throw std::invalid_argument{"Invalid guarantee."};
        }
    }

    auto targetCharacters = digitSet;

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    if (allowLeadingZeros)
    {
        return generateStringWithGuarantee(guarantee, targetCharacters, length);
    }
    else
    {
        auto firstChar = std::to_string(number::integer(1, 9));

        auto it = guarantee.find(firstChar[0]);

        if (it != guarantee.end())
        {
            --it->second.atMostCount;
        }

        return firstChar + generateStringWithGuarantee(guarantee, targetCharacters, length - 1);
    }
}

std::string nanoId(int length)
{

    if (length < 1)
        return "";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[distribution(generator)];
    }

    return id;
}

std::string nanoId()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < 10; ++i)
    {
        id += nanoIdAllowedCharacters[distribution(generator)];
    }

    return id;
}

std::string nanoId(int minLength, int maxLength)
{
    if (maxLength - minLength < 1)
        return "";

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> lengthDistribution(minLength, maxLength);
    int length = lengthDistribution(generator);

    std::uniform_int_distribution<int> charDistribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[charDistribution(generator)];
    }

    return id;
}


}
