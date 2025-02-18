#include "faker-cxx/number.h"

#include <map>

#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/types/hex.h"
#include "number_data.h"

namespace faker::number
{
namespace
{
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

std::string octal(unsigned int length)
{
    std::string octalNumber;

    for (unsigned int i = 0; i < length; ++i)
    {
        octalNumber += static_cast<char>(number::integer(7));
    }

    return "0o" + octalNumber;
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

int64_t bigInt(int64_t min, int64_t max)
{
    if (max < min) {
        throw std::invalid_argument("Max " + std::to_string(max) +
                                    " should be larger than min " + std::to_string(min) + ".");
    }

    if (max == min) {
        return min;
    }

    int64_t delta = max - min;
    std::mt19937_64& rng = getGenerator();
    std::uniform_int_distribution<int64_t> distribution(0, delta);
    int64_t offset = distribution(rng);
    return min + offset;
}

int64_t bigInt(int64_t max)
{
    return bigInt(0, max);
}

int64_t bigInt()
{
    const int64_t default_min = 0;
    const int64_t default_range = 999999999999999LL;
    return bigInt(default_min, default_min + default_range);
}

}
