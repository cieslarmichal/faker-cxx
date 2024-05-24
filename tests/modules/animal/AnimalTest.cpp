#include "faker-cxx/Animal.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "animal/data/Bears.h"
#include "animal/data/Birds.h"
#include "animal/data/Cats.h"
#include "animal/data/Cetaceans.h"
#include "animal/data/Cows.h"
#include "animal/data/Crocodiles.h"
#include "animal/data/Dogs.h"
#include "animal/data/Fishes.h"
#include "animal/data/Horses.h"
#include "animal/data/Insects.h"
#include "animal/data/Lions.h"
#include "animal/data/Rabbits.h"
#include "animal/data/Rodents.h"
#include "animal/data/Snakes.h"
#include "animal/data/Types.h"

using namespace ::testing;
using namespace faker;

class AnimalTest : public Test
{
public:
};

TEST_F(AnimalTest, shouldGenerateBear)
{
    const auto generatedBear = Animal::bear();

    ASSERT_TRUE(std::ranges::any_of(bears, [generatedBear](const std::string& bear) { return bear == generatedBear; }));
}

TEST_F(AnimalTest, shouldGenerateBird)
{
    const auto generatedBird = Animal::bird();

    ASSERT_TRUE(std::ranges::any_of(birds, [generatedBird](const std::string& bird) { return bird == generatedBird; }));
}

TEST_F(AnimalTest, shouldGenerateCat)
{
    const auto generatedCat = Animal::cat();

    ASSERT_TRUE(std::ranges::any_of(cats, [generatedCat](const std::string& cat) { return cat == generatedCat; }));
}

TEST_F(AnimalTest, shouldGenerateCetacean)
{
    const auto generatedCetacean = Animal::cetacean();

    ASSERT_TRUE(std::ranges::any_of(cetaceans, [generatedCetacean](const std::string& cetacean)
                                    { return cetacean == generatedCetacean; }));
}

TEST_F(AnimalTest, shouldGenerateCow)
{
    const auto generatedCow = Animal::cow();

    ASSERT_TRUE(std::ranges::any_of(cows, [generatedCow](const std::string& cow) { return cow == generatedCow; }));
}

TEST_F(AnimalTest, shouldGenerateCrocodile)
{
    const auto generatedCrocodile = Animal::crocodile();

    ASSERT_TRUE(std::ranges::any_of(crocodiles, [generatedCrocodile](const std::string& crocodile)
                                    { return crocodile == generatedCrocodile; }));
}

TEST_F(AnimalTest, shouldGenerateDog)
{
    const auto generatedDog = Animal::dog();

    ASSERT_TRUE(std::ranges::any_of(dogs, [generatedDog](const std::string& dog) { return dog == generatedDog; }));
}

TEST_F(AnimalTest, shouldGenerateFish)
{
    const auto generatedFish = Animal::fish();

    ASSERT_TRUE(
        std::ranges::any_of(fishes, [generatedFish](const std::string& fish) { return fish == generatedFish; }));
}

TEST_F(AnimalTest, shouldGenerateHorse)
{
    const auto generatedHorse = Animal::horse();

    ASSERT_TRUE(
        std::ranges::any_of(horses, [generatedHorse](const std::string& horse) { return horse == generatedHorse; }));
}

TEST_F(AnimalTest, shouldGenerateInsect)
{
    const auto generatedInsect = Animal::insect();

    ASSERT_TRUE(std::ranges::any_of(insects, [generatedInsect](const std::string& insect)
                                    { return insect == generatedInsect; }));
}

TEST_F(AnimalTest, shouldGenerateLion)
{
    const auto generatedLion = Animal::lion();

    ASSERT_TRUE(std::ranges::any_of(lions, [generatedLion](const std::string& lion) { return lion == generatedLion; }));
}

TEST_F(AnimalTest, shouldGenerateRabbit)
{
    const auto generatedRabbit = Animal::rabbit();

    ASSERT_TRUE(std::ranges::any_of(rabbits, [generatedRabbit](const std::string& rabbit)
                                    { return rabbit == generatedRabbit; }));
}

TEST_F(AnimalTest, shouldGenerateRodent)
{
    const auto generatedRodent = Animal::rodent();

    ASSERT_TRUE(std::ranges::any_of(rodents, [generatedRodent](const std::string& rodent)
                                    { return rodent == generatedRodent; }));
}

TEST_F(AnimalTest, shouldGenerateSnake)
{
    const auto generatedSnake = Animal::snake();

    ASSERT_TRUE(
        std::ranges::any_of(snakes, [generatedSnake](const std::string& snake) { return snake == generatedSnake; }));
}

TEST_F(AnimalTest, shouldGenerateType)
{
    const auto generatedType = Animal::type();

    ASSERT_TRUE(std::ranges::any_of(types, [generatedType](const std::string& type) { return type == generatedType; }));
}
