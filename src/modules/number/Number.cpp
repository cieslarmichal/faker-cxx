#include "faker-cxx/Number.h"

#include <sstream>

namespace faker
{
std::random_device Number::randomDevice;

std::mt19937 Number::pseudoRandomGenerator(Number::randomDevice());

std::string Number::hex(std::optional<int> min, std::optional<int> max)
{
    int defaultMin = 0;
    int defaultMax = 15;

    if (min.has_value()) {
        defaultMin = min.value();
    }

    if (max.has_value()) {
        defaultMax = max.value();
    }


    return convertToHex(integer(defaultMin, defaultMax));
}

std::string Number::convertToHex(int number)
{
    std::stringstream sstream;
    sstream << std::hex << number;
    std::string hexString = sstream.str();
    return hexString;
}

}
