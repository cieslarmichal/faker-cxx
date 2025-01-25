#pragma once

#include <random>
#include <type_traits>

namespace faker
{
template <typename T>
    requires std::uniform_random_bit_generator<T>

class RandomGenerator
{
public:
    RandomGenerator() : generator_{T(std::random_device{}())} {}

    explicit RandomGenerator(const T& other) : generator_{other} {}

    ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = default;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = default;
    RandomGenerator& operator=(RandomGenerator&&) = default;

    template <typename Dist>
        requires std::is_invocable_r_v<int, Dist&, T&>

    typename T::result_type operator()(Dist&& dist)
    {
        return std::forward<Dist>(dist)(generator_);
    }

private:
    T generator_;
};
}
