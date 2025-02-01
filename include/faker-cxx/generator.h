#pragma once

#include <random>

namespace faker
{

std::mt19937_64& getGenerator();

void setSeed(std::mt19937_64::result_type seed);

void setSeed(std::seed_seq& seq);

}
