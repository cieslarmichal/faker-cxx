#include "faker-cxx/Plant.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "plant/PlantData.h"

using namespace ::testing;
using namespace faker::plant;

class PlantTest : public Test
{
public:
};

TEST_F(PlantTest, shouldGenerateTree)
{
    const auto generatedTree = tree();

    ASSERT_TRUE(
        std::ranges::any_of(trees, [generatedTree](const std::string_view& tree) { return tree == generatedTree; }));
}

TEST_F(PlantTest, shouldGenerateFlower)
{
    const auto generatedFlower = flower();

    ASSERT_TRUE(std::ranges::any_of(flowers, [generatedFlower](const std::string_view& flower)
                                    { return flower == generatedFlower; }));
}

TEST_F(PlantTest, shouldGenerateShrub)
{
    const auto generatedShrub = shrub();

    ASSERT_TRUE(std::ranges::any_of(shrubs, [generatedShrub](const std::string_view& shrub)
                                    { return shrub == generatedShrub; }));
}

TEST_F(PlantTest, shouldGenerateGrass)
{
    const auto generatedGrass = grass();

    ASSERT_TRUE(std::ranges::any_of(grasses, [generatedGrass](const std::string_view& grass)
                                    { return grass == generatedGrass; }));
}

TEST_F(PlantTest, shouldGenerateFern)
{
    const auto generatedFern = fern();

    ASSERT_TRUE(
        std::ranges::any_of(ferns, [generatedFern](const std::string_view& fern) { return fern == generatedFern; }));
}

TEST_F(PlantTest, shouldGenerateSucculent)
{
    const auto generatedSucculent = succulent();

    ASSERT_TRUE(std::ranges::any_of(succulents, [generatedSucculent](const std::string_view& succulent)
                                    { return succulent == generatedSucculent; }));
}

TEST_F(PlantTest, shouldGenerateVine)
{
    const auto generatedVine = vine();

    ASSERT_TRUE(
        std::ranges::any_of(vines, [generatedVine](const std::string_view& vine) { return vine == generatedVine; }));
}

TEST_F(PlantTest, shouldGenerateType)
{
    const auto generatedType = plantType();

    ASSERT_TRUE(std::ranges::any_of(plantTypes, [generatedType](const std::string_view& plantType)
                                    { return plantType == generatedType; }));
}
