#include <cstdint>
#include <thread>

#include "faker-cxx/generator.h"
#include "faker-cxx/random_generator.h"
#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

TEST(GeneratorTest, shouldReturnDeterministicValueWhenSeeded)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 100);
    constexpr unsigned int arbitrary_seed = 42;
    std::mt19937_64& generator = faker::getGenerator();

    faker::setSeed(arbitrary_seed);
    const auto x0 = distribution(generator);
    const auto y0 = distribution(generator);

    faker::setSeed(arbitrary_seed);
    const auto x1 = distribution(generator);
    const auto y1 = distribution(generator);

    ASSERT_EQ(x0, x1);
    ASSERT_EQ(y0, y1);
}

TEST(GeneratorTest, sameSeedShouldResetGenerator)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 100);
    // We are using a seed_seq in this test to also cover this overload of SetSeed
    std::vector<uint32_t> seed_data = {12345, 67890, 54321};
    std::seed_seq arbitrary_seed(seed_data.begin(), seed_data.end());

    faker::setSeed(arbitrary_seed);
    std::mt19937_64& generator = faker::getGenerator();
    const auto first = distribution(generator);

    faker::setSeed(arbitrary_seed);
    const auto second = distribution(generator);

    // The generator should generate the same number
    // since it uses the same seed
    ASSERT_EQ(first, second);
}

TEST(GeneratorTest, seedOnOneThreadShouldNotAffectOtherThreads)
{
    // We make the range as large as possible to lower the chances of randomly
    // generating the same number two times
    std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);

    constexpr unsigned int seed_t1 = 42;
    faker::setSeed(seed_t1);
    std::mt19937_64& generator_t1 = faker::getGenerator();
    const auto value_t1 = distribution(generator_t1);

    std::thread t2([&distribution, value_t1]() {
        // Default seed of mt19937 is expected to be different from "42"
        std::mt19937_64& generator_t2 = faker::getGenerator();
        const auto value_t2 = distribution(generator_t2);
        ASSERT_NE(value_t1, value_t2);
    });

    t2.join();
}

TEST(GeneratorTest, randomSeedIsUsedWhenNoneProvided)
{
    // We make the range as large as possible to lower the chances of randomly
    // generating the same number two times
    std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);

    std::mt19937_64 generator_with_default_seed;
    std::mt19937_64& generator_with_random_seed = faker::getGenerator();

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
    ASSERT_TRUE(is_different);
}

TEST(GeneratorTest, seededStateIsCopiedToRandomGenerator)
{
    std::uniform_int_distribution<uint32_t> distribution(0, 1000);

    constexpr unsigned int arbitrary_seed = 42;
    faker::setSeed(arbitrary_seed);
    std::mt19937_64& generator1 = faker::getGenerator();

    // Move internal state
    std::ignore = distribution(generator1);

    // Calls the copy constructor of std::mt19937_64
    RandomGenerator<std::mt19937_64> generator2 {generator1};

    const auto first = distribution(generator1);
    const auto second = generator2(distribution);
    ASSERT_EQ(first, second);
}