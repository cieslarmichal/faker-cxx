#include <faker/number.h>
#include <random>
#include <sstream>

namespace faker::number {

std::random_device randomDevice;

std::mt19937 pseudoRandomGenerator(randomDevice());

std::string convertToHex(int number)
{
    std::stringstream stream;

    stream << std::hex << number;

    return stream.str();
}

int integer(int min, int max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

unsigned integer(unsigned min, unsigned max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_int_distribution<unsigned> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

long integer(long min, long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_int_distribution<long> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

unsigned long integer(unsigned long min, unsigned long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_int_distribution<unsigned long> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

float decimal(float min, float max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_real_distribution<float> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

double decimal(double min, double max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(pseudoRandomGenerator);
}

std::string hex(std::optional<int> min, std::optional<int> max)
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

}
