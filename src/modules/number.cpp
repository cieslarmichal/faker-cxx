#include "../common/formatter.h"
#include "../common/random.h"
#include <faker/number.h>
#include <random>

namespace faker::number {

int integer(int min, int max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

unsigned integer(unsigned min, unsigned max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

long integer(long min, long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

unsigned long integer(unsigned long min, unsigned long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

long long integer(long long min, long long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

unsigned long long integer(unsigned long long min, unsigned long long max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::integer(min, max);
}

float decimal(float min, float max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::decimal(min, max);
}

double decimal(double min, double max)
{
    if (min > max) {
        throw std::invalid_argument("Minimum value must be smaller than maximum value.");
    }

    return random::decimal(min, max);
}

std::string hex(std::optional<int> min, std::optional<int> max)
{
    return utils::format("{:x}", integer(min.value_or(0), max.value_or(15)));
}

}
