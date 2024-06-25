#include "faker-cxx/Number.h"

#include <random>

namespace faker::number
{
std::random_device randomDevice;

std::mt19937 pseudoRandomGenerator(randomDevice());
}
