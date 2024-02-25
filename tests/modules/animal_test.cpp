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

    FAKER_EXPECT_CONTAINS(bears, generatedBear);
}

TEST_F(AnimalTest, shouldGenerateBird)
{
    const auto generatedBird = animal::bird();

    FAKER_EXPECT_CONTAINS(birds, generatedBird);
}

TEST_F(AnimalTest, shouldGenerateCat)
{
    const auto generatedCat = animal::cat();

    FAKER_EXPECT_CONTAINS(cats, generatedCat);
}

TEST_F(AnimalTest, shouldGenerateCetacean)
{
    const auto generatedCetacean = animal::cetacean();

    FAKER_EXPECT_CONTAINS(cetaceans, generatedCetacean);
}

TEST_F(AnimalTest, shouldGenerateCow)
{
    const auto generatedCow = animal::cow();

    FAKER_EXPECT_CONTAINS(cows, generatedCow);
}

TEST_F(AnimalTest, shouldGenerateCrocodilia)
{
    const auto generatedCrocodilia = animal::crocodilia();

    FAKER_EXPECT_CONTAINS(crocodilia, generatedCrocodilia);
}

TEST_F(AnimalTest, shouldGenerateDog)
{
    const auto generatedDog = animal::dog();

    FAKER_EXPECT_CONTAINS(dogs, generatedDog);
}

TEST_F(AnimalTest, shouldGenerateFish)
{
    const auto generatedFish = animal::fish();

    FAKER_EXPECT_CONTAINS(fishes, generatedFish);
}

TEST_F(AnimalTest, shouldGenerateHorse)
{
    const auto generatedHorse = animal::horse();

    FAKER_EXPECT_CONTAINS(horses, generatedHorse);
}

TEST_F(AnimalTest, shouldGenerateInsect)
{
    const auto generatedInsect = animal::insect();

    FAKER_EXPECT_CONTAINS(insects, generatedInsect);
}

TEST_F(AnimalTest, shouldGenerateLion)
{
    const auto generatedLion = animal::lion();

    FAKER_EXPECT_CONTAINS(lions, generatedLion);
}

TEST_F(AnimalTest, shouldGenerateRabbit)
{
    const auto generatedRabbit = animal::rabbit();

    FAKER_EXPECT_CONTAINS(rabbits, generatedRabbit);
}

TEST_F(AnimalTest, shouldGenerateRodent)
{
    const auto generatedRodent = animal::rodent();

    FAKER_EXPECT_CONTAINS(rodents, generatedRodent);
}

TEST_F(AnimalTest, shouldGenerateSnake)
{
    const auto generatedSnake = animal::snake();

    FAKER_EXPECT_CONTAINS(snakes, generatedSnake);
}

TEST_F(AnimalTest, shouldGenerateType)
{
    const auto generatedType = animal::type();

    FAKER_EXPECT_CONTAINS(types, generatedType);
}