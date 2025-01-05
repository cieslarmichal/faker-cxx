#pragma once

#include <random>

namespace faker::common {

std::mt19937_64& GetGenerator();

void SetSeed(std::mt19937_64::result_type seed);

void SetSeed(std::seed_seq& seq);

}
