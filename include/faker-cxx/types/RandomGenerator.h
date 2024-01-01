#pragma once

#include <random>

namespace faker
{
template <typename T>
requires std::uniform_random_bit_generator<T>
class RandomGenerator
{
public:
    RandomGenerator() : generator_{T(std::random_device{}())} {}
    ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = default;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = default;
    RandomGenerator& operator=(RandomGenerator&&) = default;

    int operator()(std::uniform_int_distribution<>& dist)
    {
        return dist(generator_);
    }

private:
    T generator_;
};
}
