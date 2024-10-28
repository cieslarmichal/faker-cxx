#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/plant.h"
#include "plant_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::plant;

namespace
{
const struct PlantDefinition& getPlantDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSPlantDefinition;
    }
}
}

class PlantTest : public TestWithParam<Locale>
{
public:
};

TEST_P(PlantTest, shouldGenerateTree)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedTree = tree(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.trees,
                                    [generatedTree](const std::string_view& tree) { return tree == generatedTree; }));
}

TEST_P(PlantTest, shouldGenerateFlower)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedFlower = flower(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.flowers, [generatedFlower](const std::string_view& flower)
                                    { return flower == generatedFlower; }));
}

TEST_P(PlantTest, shouldGenerateShrub)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedShrub = shrub(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.shrubs, [generatedShrub](const std::string_view& shrub)
                                    { return shrub == generatedShrub; }));
}

TEST_P(PlantTest, shouldGenerateGrass)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedGrass = grass(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.grasses, [generatedGrass](const std::string_view& grass)
                                    { return grass == generatedGrass; }));
}

TEST_P(PlantTest, shouldGenerateFern)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedFern = fern(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.ferns,
                                    [generatedFern](const std::string_view& fern) { return fern == generatedFern; }));
}

TEST_P(PlantTest, shouldGenerateSucculent)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedSucculent = succulent(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.succulents, [generatedSucculent](const std::string_view& succulent)
                                    { return succulent == generatedSucculent; }));
}

TEST_P(PlantTest, shouldGenerateVine)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedVine = vine(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.vines,
                                    [generatedVine](const std::string_view& vine) { return vine == generatedVine; }));
}

TEST_P(PlantTest, shouldGenerateType)
{
    const auto locale = GetParam();

    const auto& plantDefinition = getPlantDefinition(locale);

    const auto generatedType = plantType(locale);

    ASSERT_TRUE(std::ranges::any_of(plantDefinition.plantTypes, [generatedType](const std::string_view& plantType)
                                    { return plantType == generatedType; }));
}

INSTANTIATE_TEST_SUITE_P(TestPlantByLocale, PlantTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
