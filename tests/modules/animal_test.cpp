#include "../test_helpers.h"
#include <algorithm>
#include <faker/animal.h>
#include <modules/animal_data.h>

using namespace faker;

class AnimalTest : public ::testing::Test {
public:
};

TEST_F(AnimalTest, shouldGenerateBear)
{
    const auto generatedBear = animal::bear();

    ASSERT_TRUE(faker::testing::contains(bears, generatedBear));
}

TEST_F(AnimalTest, shouldGenerateBird)
{
    const auto generatedBird = animal::bird();

    ASSERT_TRUE(faker::testing::contains(birds, generatedBird));
}

TEST_F(AnimalTest, shouldGenerateCat)
{
    const auto generatedCat = animal::cat();

    ASSERT_TRUE(faker::testing::contains(cats, generatedCat));
}

TEST_F(AnimalTest, shouldGenerateCetacean)
{
    const auto generatedCetacean = animal::cetacean();

    ASSERT_TRUE(faker::testing::contains(cetaceans, generatedCetacean));
}

TEST_F(AnimalTest, shouldGenerateCow)
{
    const auto generatedCow = animal::cow();

    ASSERT_TRUE(faker::testing::contains(cows, generatedCow));
}

TEST_F(AnimalTest, shouldGenerateCrocodilia)
{
    const auto generatedCrocodilia = animal::crocodilia();

    ASSERT_TRUE(faker::testing::contains(crocodilia, generatedCrocodilia));
}

TEST_F(AnimalTest, shouldGenerateDog)
{
    const auto generatedDog = animal::dog();

    ASSERT_TRUE(faker::testing::contains(dogs, generatedDog));
}

TEST_F(AnimalTest, shouldGenerateFish)
{
    const auto generatedFish = animal::fish();

    ASSERT_TRUE(faker::testing::contains(fishes, generatedFish));
}

TEST_F(AnimalTest, shouldGenerateHorse)
{
    const auto generatedHorse = animal::horse();

    ASSERT_TRUE(faker::testing::contains(horses, generatedHorse));
}

TEST_F(AnimalTest, shouldGenerateInsect)
{
    const auto generatedInsect = animal::insect();

    ASSERT_TRUE(faker::testing::contains(insects, generatedInsect));
}

TEST_F(AnimalTest, shouldGenerateLion)
{
    const auto generatedLion = animal::lion();

    ASSERT_TRUE(faker::testing::contains(lions, generatedLion));
}

TEST_F(AnimalTest, shouldGenerateRabbit)
{
    const auto generatedRabbit = animal::rabbit();

    ASSERT_TRUE(faker::testing::contains(rabbits, generatedRabbit));
}

TEST_F(AnimalTest, shouldGenerateRodent)
{
    const auto generatedRodent = animal::rodent();

    ASSERT_TRUE(faker::testing::contains(rodents, generatedRodent));
}

TEST_F(AnimalTest, shouldGenerateSnake)
{
    const auto generatedSnake = animal::snake();

    ASSERT_TRUE(faker::testing::contains(snakes, generatedSnake));
}

TEST_F(AnimalTest, shouldGenerateType)
{
    const auto generatedType = animal::type();

    ASSERT_TRUE(faker::testing::contains(types, generatedType));
}