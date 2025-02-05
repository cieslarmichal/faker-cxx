#pragma once

#include <random>

#include "faker-cxx/export.h"

namespace faker
{

FAKER_CXX_EXPORT std::mt19937_64& getGenerator();

FAKER_CXX_EXPORT void setSeed(std::mt19937_64::result_type seed);

FAKER_CXX_EXPORT void setSeed(std::seed_seq& seq);

}
