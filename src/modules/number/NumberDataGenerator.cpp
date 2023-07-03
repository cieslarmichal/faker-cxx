#include "NumberDataGenerator.h"

#include <random>
#include <stdexcept>

namespace faker::number
{
int NumberDataGenerator::integer(int min, int max)
{
    if (min > max)
    {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::random_device randomDevice;

    std::mt19937 pseudoRandomGenerator{randomDevice()};

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}
}
