#include "faker-cxx/number.h"

#include <cassert>
#include <set>
#include <string>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"

namespace faker::number
{
namespace
{

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

std::string generateAtLeastString(const GuaranteeMap& guarantee)
{
    std::string result;

    for (auto& it : guarantee)
    {
        result += std::string(it.second.atLeastCount, it.first);
    }

    return result;
}


std::string binary(int length)
{
    if (length < 0)
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
    if (min > max)
    {
        throw std::invalid_argument("min cannot be greater than max");
    }

    if (min < 0 || max < 0)
    {
        throw std::invalid_argument("The output binary string cannot be negative");
    }

    int num = number::integer<int>(min, max);

    if (num == 0)
    {
        return "0b0";
    }

    std::string output;

    while (num > 0)
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
}
}