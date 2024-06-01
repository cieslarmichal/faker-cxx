#include "faker-cxx/Number.h"

#include <random>

namespace faker
{
std::random_device Number::randomDevice;

std::mt19937 Number::pseudoRandomGenerator(Number::randomDevice());
}
