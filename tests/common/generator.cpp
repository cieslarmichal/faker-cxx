#include "common/generator.h"
#include "faker-cxx/random_generator.h"
#include "gtest/gtest.h"

#include <cstdint>
#include <thread>

using namespace ::testing;
using namespace faker;

TEST(GeneratorTest, shouldReturnDeterministicValueWhenSeeded)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 100);
    constexpr unsigned int arbitrary_seed = 42;
    common::SetSeed(arbitrary_seed);
    std::mt19937_64& generator = common::GetGenerator();
    const auto first = distribution(generator);
    const auto second = distribution(generator);

    // These are the numbers generated on the first test run
    // and should not change since the seed is fixed
    EXPECT_EQ(first, 86);
    EXPECT_EQ(second, 40);
}

TEST(GeneratorTest, sameSeedShouldResetGenerator)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 100);
    // We are using a seed_seq in this test to also cover this overload of SetSeed
    std::vector<uint32_t> seed_data = {12345, 67890, 54321};
    std::seed_seq arbitrary_seed(seed_data.begin(), seed_data.end());

    common::SetSeed(arbitrary_seed);
    std::mt19937_64& generator = common::GetGenerator();
    const auto first = distribution(generator);

    common::SetSeed(arbitrary_seed);
    const auto second = distribution(generator);

    // The generator should generate the same number
    // since it uses the same seed
    EXPECT_EQ(first, second);
}

TEST(GeneratorTest, seedOnOneThreadShouldNotAffectOtherThreads)
{
    // We make the range as large as possible to lower the chances of randomly
    // generating the same number two times
    std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);

    constexpr unsigned int seed_t1 = 42;
    common::SetSeed(seed_t1);
    std::mt19937_64& generator_t1 = common::GetGenerator();
    const auto value_t1 = distribution(generator_t1);

    std::thread t2([&distribution, value_t1]() {
        // Default seed of mt19937 is expected to be different from "42"
        std::mt19937_64& generator_t2 = common::GetGenerator();
        const auto value_t2 = distribution(generator_t2);
        EXPECT_NE(value_t1, value_t2);
    });

    t2.join();
}

TEST(GeneratorTest, randomSeedIsUsedWhenNoneProvided)
{
    // We make the range as large as possible to lower the chances of randomly
    // generating the same number two times
    std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);

    std::mt19937_64 generator_with_default_seed;
    std::mt19937_64& generator_with_random_seed = common::GetGenerator();

    bool is_different = false;
    for (int i = 0; i < 10; i++) {
        const auto value_default = distribution(generator_with_default_seed);
        const auto value_random = distribution(generator_with_random_seed);
        if (value_default != value_random) {
            is_different = true;
            break;
        }
    }

    // The second generator has a seed other than the default value because
    // different values have been generated
    EXPECT_TRUE(is_different);
}

TEST(GeneratorTest, seededStateIsCopiedToRandomGenerator)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 1000);

    constexpr unsigned int arbitrary_seed = 42;
    common::SetSeed(arbitrary_seed);
    std::mt19937_64& generator1 = common::GetGenerator();

    // Move internal state
    std::ignore = distribution(generator1);

    // Calls the copy constructor of std::mt19937_64
    RandomGenerator<std::mt19937_64> generator2 {generator1};

    const auto first = distribution(generator1);
    const auto second = generator2(distribution);
    EXPECT_EQ(first, second);
}