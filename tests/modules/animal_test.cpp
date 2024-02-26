#include "../test_helpers.h"
#include <algorithm>
#include <faker/animal.h>
#include <modules/animal_data.h>

using namespace faker;

TEST(AnimalTest, shouldGenerateBear)
{
    auto generatedBear = animal::bear();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::bears, generatedBear);
}

TEST(AnimalTest, shouldGenerateBird)
{
    auto generatedBird = animal::bird();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::birds, generatedBird);
}

TEST(AnimalTest, shouldGenerateCat)
{
    auto generatedCat = animal::cat();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cats, generatedCat);
}

TEST(AnimalTest, shouldGenerateCetacean)
{
    auto generatedCetacean = animal::cetacean();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cetaceans, generatedCetacean);
}

TEST(AnimalTest, shouldGenerateCow)
{
    auto generatedCow = animal::cow();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cows, generatedCow);
}

TEST(AnimalTest, shouldGenerateCrocodilia)
{
    auto generatedCrocodilia = animal::crocodilia();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::crocodilia, generatedCrocodilia);
}

TEST(AnimalTest, shouldGenerateDog)
{
    auto generatedDog = animal::dog();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::dogs, generatedDog);
}

TEST(AnimalTest, shouldGenerateFish)
{
    auto generatedFish = animal::fish();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::fishes, generatedFish);
}

TEST(AnimalTest, shouldGenerateHorse)
{
    auto generatedHorse = animal::horse();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::horses, generatedHorse);
}

TEST(AnimalTest, shouldGenerateInsect)
{
    auto generatedInsect = animal::insect();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::insects, generatedInsect);
}

TEST(AnimalTest, shouldGenerateLion)
{
    auto generatedLion = animal::lion();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::lions, generatedLion);
}

TEST(AnimalTest, shouldGenerateRabbit)
{
    auto generatedRabbit = animal::rabbit();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::rabbits, generatedRabbit);
}

TEST(AnimalTest, shouldGenerateRodent)
{
    auto generatedRodent = animal::rodent();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::rodents, generatedRodent);
}

TEST(AnimalTest, shouldGenerateSnake)
{
    auto generatedSnake = animal::snake();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::snakes, generatedSnake);
}

TEST(AnimalTest, shouldGenerateType)
{
    auto generatedType = animal::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::types, generatedType);
}