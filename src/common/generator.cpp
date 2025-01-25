#include "generator.h"

namespace faker::common
{

thread_local bool is_seeded = false;
thread_local std::mt19937_64 generator;

std::mt19937_64& GetGenerator()
{
    if (!is_seeded)
    {
        generator.seed(std::random_device{}());
        is_seeded = true;
    }

    return generator;
}

void SetSeed(std::mt19937_64::result_type seed)
{
    generator.seed(seed);
    is_seeded = true;
}

void SetSeed(std::seed_seq& seq)
{
    generator.seed(seq);
    is_seeded = true;
}

}
