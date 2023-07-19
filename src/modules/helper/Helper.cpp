#include "faker-cxx/Helper.h"

namespace faker
{
std::random_device Helper::randomDevice;

std::mt19937 Helper::pseudoRandomGenerator(Helper::randomDevice());
}
