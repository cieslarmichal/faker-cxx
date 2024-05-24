#include "faker-cxx/Animal.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "animal/AnimalData.h"

using namespace ::testing;
using namespace faker;

class AnimalTest : public Test
{
public:
};

TEST_F(AnimalTest, shouldGenerateBear)
{
    const auto generatedBear = Animal::bear();

    ASSERT_TRUE(
        std::ranges::any_of(bears, [generatedBear](const std::string_view& bear) { return bear == generatedBear; }));
}

TEST_F(AnimalTest, shouldGenerateBird)
{
    const auto generatedBird = Animal::bird();

    ASSERT_TRUE(
        std::ranges::any_of(birds, [generatedBird](const std::string_view& bird) { return bird == generatedBird; }));
}

TEST_F(AnimalTest, shouldGenerateCat)
{
    const auto generatedCat = Animal::cat();

    ASSERT_TRUE(std::ranges::any_of(cats, [generatedCat](const std::string_view& cat) { return cat == generatedCat; }));
}

TEST_F(AnimalTest, shouldGenerateCetacean)
{
    const auto generatedCetacean = Animal::cetacean();

    ASSERT_TRUE(std::ranges::any_of(cetaceans, [generatedCetacean](const std::string_view& cetacean)
                                    { return cetacean == generatedCetacean; }));
}

TEST_F(AnimalTest, shouldGenerateCow)
{
    const auto generatedCow = Animal::cow();

    ASSERT_TRUE(std::ranges::any_of(cows, [generatedCow](const std::string_view& cow) { return cow == generatedCow; }));
}

TEST_F(AnimalTest, shouldGenerateCrocodile)
{
    const auto generatedCrocodile = Animal::crocodile();

    ASSERT_TRUE(std::ranges::any_of(crocodiles, [generatedCrocodile](const std::string_view& crocodile)
                                    { return crocodile == generatedCrocodile; }));
}

TEST_F(AnimalTest, shouldGenerateDog)
{
    const auto generatedDog = Animal::dog();

    ASSERT_TRUE(std::ranges::any_of(dogs, [generatedDog](const std::string_view& dog) { return dog == generatedDog; }));
}

TEST_F(AnimalTest, shouldGenerateFish)
{
    const auto generatedFish = Animal::fish();

    ASSERT_TRUE(
        std::ranges::any_of(fishes, [generatedFish](const std::string_view& fish) { return fish == generatedFish; }));
}

TEST_F(AnimalTest, shouldGenerateHorse)
{
    const auto generatedHorse = Animal::horse();

    ASSERT_TRUE(std::ranges::any_of(horses, [generatedHorse](const std::string_view& horse)
                                    { return horse == generatedHorse; }));
}

TEST_F(AnimalTest, shouldGenerateInsect)
{
    const auto generatedInsect = Animal::insect();

    ASSERT_TRUE(std::ranges::any_of(insects, [generatedInsect](const std::string_view& insect)
                                    { return insect == generatedInsect; }));
}

TEST_F(AnimalTest, shouldGenerateLion)
{
    const auto generatedLion = Animal::lion();

    ASSERT_TRUE(
        std::ranges::any_of(lions, [generatedLion](const std::string_view& lion) { return lion == generatedLion; }));
}

TEST_F(AnimalTest, shouldGenerateRabbit)
{
    const auto generatedRabbit = Animal::rabbit();

    ASSERT_TRUE(std::ranges::any_of(rabbits, [generatedRabbit](const std::string_view& rabbit)
                                    { return rabbit == generatedRabbit; }));
}

TEST_F(AnimalTest, shouldGenerateRodent)
{
    const auto generatedRodent = Animal::rodent();

    ASSERT_TRUE(std::ranges::any_of(rodents, [generatedRodent](const std::string_view& rodent)
                                    { return rodent == generatedRodent; }));
}

TEST_F(AnimalTest, shouldGenerateSnake)
{
    const auto generatedSnake = Animal::snake();

    ASSERT_TRUE(std::ranges::any_of(snakes, [generatedSnake](const std::string_view& snake)
                                    { return snake == generatedSnake; }));
}

TEST_F(AnimalTest, shouldGenerateType)
{
    const auto generatedType = Animal::type();

    ASSERT_TRUE(
        std::ranges::any_of(types, [generatedType](const std::string_view& type) { return type == generatedType; }));
}
