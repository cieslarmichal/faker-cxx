#include "faker-cxx/string.h"

#include <algorithm>
#include <cassert>
#include <map>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <math.h>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/types/hex.h"
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
const std::map<HexCasing, std::string> hexCasingToCharactersMapping{
    {HexCasing::Lower, hexLowerCharacters},
    {HexCasing::Upper, hexUpperCharacters},
};
const std::map<HexPrefix, std::string> hexPrefixToStringMapping{
    {HexPrefix::ZeroX, "0x"},
    {HexPrefix::Hash, "#"},
    {HexPrefix::None, ""},
};

const std::map<StringCasing, std::set<char>> stringCasingToAlphaCharSetMapping{
    {StringCasing::Lower, lowerCharSet},
    {StringCasing::Upper, upperCharSet},
    {StringCasing::Mixed, mixedAlphaCharSet},
};

const std::map<HexCasing, std::set<char>> hexCasingToCharSetMapping{
    {HexCasing::Lower, hexLowerCharSet},
    {HexCasing::Upper, hexUpperCharSet},
};

std::string generateStringWithGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length)
{
    std::string output{};
    output += generateAtLeastString(guarantee);
    // string with least required chars cannot be greater than the total length
    assert(output.size() <= length);
    // we will generate chars for remaining length only
    length -= static_cast<unsigned>(output.size());
    for (unsigned i = 0; i < length; ++i)
    {
        char generatedChar;
        // generate chars till we find a usable char
        while (true)
        {
            // pick random char from targetCharacters
            generatedChar = helper::setElement(targetCharacters);

            auto it = guarantee.find(generatedChar);
            // if no constraint on generated char, break out of loop
            if (it == guarantee.end())
                break;
            auto remainingUses = it->second.atMostCount - it->second.atLeastCount;
            if (remainingUses > 0)
            {
                // decrement no of possible uses as we will use it right now
                --it->second.atMostCount;
                break;
            }
            // remove this char from targetCharacters as it is no longer valid and regenerate char
            else
            {
                targetCharacters.erase(it->first);
            }
        }
        output += generatedChar;
    }
    // shuffle the generated string as the atleast string generated earlier was not generated randomly
    output = helper::shuffleString(output);
    return output;
}
}

bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned int length)
{
    unsigned int atleastCountSum{};
    unsigned int atmostCountSum{};

    for (auto& it : guarantee)
    {
        if (std::find(targetCharacters.begin(), targetCharacters.end(), it.first) == targetCharacters.end())
        {
            return false;
        }
        atleastCountSum += it.second.atLeastCount;
        atmostCountSum += it.second.atMostCount;
    }

    if (atleastCountSum > length || (guarantee.size() == targetCharacters.size() && atmostCountSum < length))
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

std::string hexadecimal(unsigned int length, HexCasing casing, HexPrefix prefix)
{
    const auto& hexadecimalCharacters = hexCasingToCharactersMapping.at(casing);

    const auto& hexadecimalPrefix = hexPrefixToStringMapping.at(prefix);

    std::string hexadecimal{hexadecimalPrefix};

    for (unsigned i = 0; i < length; i++)
    {
        hexadecimal += helper::randomElement(hexadecimalCharacters);
    }

    return hexadecimal;
}

std::string hexadecimal(std::optional<int> min, std::optional<int> max)
{
    int defaultMin = 0;
    int defaultMax = 15;

    if (min.has_value())
    {
        defaultMin = min.value();
    }

    if (max.has_value())
    {
        defaultMax = max.value();
    }

    return common::format("{:x}", number::integer(defaultMin, defaultMax));
}

std::string hexadecimal(GuaranteeMap&& guarantee, unsigned int length, HexCasing casing, HexPrefix prefix)
{
    std::set<char> targetCharacters = hexCasingToCharSetMapping.at(casing);

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    const auto& hexadecimalPrefix = hexPrefixToStringMapping.at(prefix);

    return hexadecimalPrefix + generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string binary(int length)
{
    if(length < 0)
    {
        throw std::invalid_argument("The length of a binary number cannot be negative");
    }

    std::string binaryNumber;

    for (int i = 0; i < length; ++i)
    {
        binaryNumber += static_cast<char>(number::integer(1));
    }

    return "0b" + binaryNumber;
}

std::string binary(int min, int max)
{
    if(min > max)
    {
        throw std::invalid_argument("min cannot be greater than max");
    }

    if(min < 0 || max < 0)
    {
        throw std::invalid_argument("The output binary string cannot be negative");
    }

    int num = number::integer<int>(min, max);

    if(num == 0)
    {
        return "0b0";
    }

    std::string output = "";

    while(num > 0)
    {
        int remainder = num % 2;
        output = std::to_string(remainder) + output;
        num /= 2;
    }

    return "0b" + output;
}

std::string binary(GuaranteeMap&& guarantee, unsigned int length)
{
    std::set<char> targetCharacters{'0', '1'};

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return "0b" + generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string octal(unsigned int length)
{
    std::string octalNumber;

    for (unsigned int i = 0; i < length; ++i)
    {
        octalNumber += static_cast<char>(number::integer(7));
    }

    return "0o" + octalNumber;
}

std::string octal(GuaranteeMap&& guarantee, unsigned int length)
{
    std::set<char> targetCharacters{'0', '1', '2', '3', '4', '5', '6', '7'};

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return "0o" + generateStringWithGuarantee(guarantee, targetCharacters, length);
}
}
