#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "animal_data.h"
#include "faker-cxx/animal.h"

using namespace ::testing;
using namespace faker;
using namespace faker::animal;

namespace
{
const struct AnimalDefinition& getAnimalDefinition(Locale locale)
{
    switch(locale)
    {
    default:
        return enUSAnimalDefinition;
    }
}
}

class AnimalTest : public TestWithParam<Locale>
{
public:
};

TEST_P(AnimalTest, shouldGenerateBear)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedBear = bear(locale);

    ASSERT_TRUE(
        std::ranges::any_of(animalDefinition.bears, [generatedBear](const std::string_view& bear) { return bear == generatedBear; }));
}

TEST_P(AnimalTest, shouldGenerateBird)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedBird = bird(locale);

    ASSERT_TRUE(
        std::ranges::any_of(animalDefinition.birds, [generatedBird](const std::string_view& bird) { return bird == generatedBird; }));
}

TEST_P(AnimalTest, shouldGenerateCat)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedCat = cat(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.cats, [generatedCat](const std::string_view& cat) { return cat == generatedCat; }));
}

TEST_P(AnimalTest, shouldGenerateCetacean)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedCetacean = cetacean(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.cetaceans, [generatedCetacean](const std::string_view& cetacean)
                                    { return cetacean == generatedCetacean; }));
}

TEST_P(AnimalTest, shouldGenerateCow)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedCow = cow(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.cows, [generatedCow](const std::string_view& cow) { return cow == generatedCow; }));
}

TEST_P(AnimalTest, shouldGenerateCrocodile)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedCrocodile = crocodile(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.crocodiles, [generatedCrocodile](const std::string_view& crocodile)
                                    { return crocodile == generatedCrocodile; }));
}

TEST_P(AnimalTest, shouldGenerateDog)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedDog = dog(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.dogs, [generatedDog](const std::string_view& dog) { return dog == generatedDog; }));
}

TEST_P(AnimalTest, shouldGenerateFish)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedFish = fish(locale);

    ASSERT_TRUE(
        std::ranges::any_of(animalDefinition.fishes, [generatedFish](const std::string_view& fish) { return fish == generatedFish; }));
}

TEST_P(AnimalTest, shouldGenerateHorse)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedHorse = horse(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.horses, [generatedHorse](const std::string_view& horse)
                                    { return horse == generatedHorse; }));
}

TEST_P(AnimalTest, shouldGenerateInsect)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedInsect = insect(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.insects, [generatedInsect](const std::string_view& insect)
                                    { return insect == generatedInsect; }));
}

TEST_P(AnimalTest, shouldGenerateLion)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedLion = lion(locale);

    ASSERT_TRUE(
        std::ranges::any_of(animalDefinition.lions, [generatedLion](const std::string_view& lion) { return lion == generatedLion; }));
}

TEST_P(AnimalTest, shouldGenerateRabbit)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedRabbit = rabbit(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.rabbits, [generatedRabbit](const std::string_view& rabbit)
                                    { return rabbit == generatedRabbit; }));
}

TEST_P(AnimalTest, shouldGenerateRodent)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedRodent = rodent(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.rodents, [generatedRodent](const std::string_view& rodent)
                                    { return rodent == generatedRodent; }));
}

TEST_P(AnimalTest, shouldGenerateSnake)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedSnake = snake(locale);

    ASSERT_TRUE(std::ranges::any_of(animalDefinition.snakes, [generatedSnake](const std::string_view& snake)
                                    { return snake == generatedSnake; }));
}

TEST_P(AnimalTest, shouldGenerateType)
{
    const auto locale = GetParam();

    const auto& animalDefinition = getAnimalDefinition(locale);

    const auto generatedType = type(locale);

    ASSERT_TRUE(
        std::ranges::any_of(animalDefinition.types, [generatedType](const std::string_view& type) { return type == generatedType; }));
}

INSTANTIATE_TEST_SUITE_P(TestAnimalByLocale, AnimalTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });