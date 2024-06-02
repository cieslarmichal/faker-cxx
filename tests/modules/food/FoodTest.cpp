#include "faker-cxx/Food.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "food/FoodData.h"

using namespace ::testing;
using namespace faker;

class FoodTest : public Test
{
public:
};

TEST_F(FoodTest, shouldGenerateAlcoholicBeverage)
{
    const auto generatedAlcoholicBeverage = Food::alcoholicBeverage();

    ASSERT_TRUE(std::ranges::any_of(alcoholicBeverages,
                                    [generatedAlcoholicBeverage](const std::string_view& alcoholicBeverage)
                                    { return generatedAlcoholicBeverage == alcoholicBeverage; }));
}

TEST_F(FoodTest, shouldGenerateDishName)
{
    const auto generatedDishName = Food::dishName();

    ASSERT_TRUE(std::ranges::any_of(dishNames, [generatedDishName](const std::string_view& dishName)
                                    { return generatedDishName == dishName; }));
}

TEST_F(FoodTest, shouldGenerateFoodCategories)
{
    const auto generatedFoodCategory = Food::foodCategory();

    ASSERT_TRUE(std::ranges::any_of(foodCategories, [generatedFoodCategory](const std::string_view& foodCategory)
                                    { return generatedFoodCategory == foodCategory; }));
}

TEST_F(FoodTest, shouldGenerateFruit)
{
    const auto generatedFruit = Food::fruit();

    ASSERT_TRUE(std::ranges::any_of(fruits, [generatedFruit](const std::string_view& fruit)
                                    { return generatedFruit == fruit; }));
}

TEST_F(FoodTest, shouldGenerateMeat)
{
    const auto generatedMeat = Food::meat();

    ASSERT_TRUE(
        std::ranges::any_of(meats, [generatedMeat](const std::string_view& meat) { return generatedMeat == meat; }));
}

TEST_F(FoodTest, shouldGenerateMilkProduct)
{
    const auto generatedMilkProduct = Food::milkProduct();

    ASSERT_TRUE(std::ranges::any_of(milkProducts, [generatedMilkProduct](const std::string_view& milkProduct)
                                    { return generatedMilkProduct == milkProduct; }));
}

TEST_F(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    const auto generatedNonalcoholicBeverages = Food::nonalcoholicBeverage();

    ASSERT_TRUE(std::ranges::any_of(nonalcoholicBeverages,
                                    [generatedNonalcoholicBeverages](const std::string_view& nonalcoholicBeverage)
                                    { return generatedNonalcoholicBeverages == nonalcoholicBeverage; }));
}

TEST_F(FoodTest, shouldGenerateNut)
{
    const auto generatedNut = Food::nut();

    ASSERT_TRUE(std::ranges::any_of(nuts, [generatedNut](const std::string_view& nut) { return generatedNut == nut; }));
}

TEST_F(FoodTest, shouldGenerateOil)
{
    const auto generatedOil = Food::oil();

    ASSERT_TRUE(std::ranges::any_of(oils, [generatedOil](const std::string_view& oil) { return generatedOil == oil; }));
}

TEST_F(FoodTest, shouldGenerateSeafood)
{
    const auto generatedSeafood = Food::seafood();

    ASSERT_TRUE(std::ranges::any_of(seafoods, [generatedSeafood](const std::string_view& seafood)
                                    { return generatedSeafood == seafood; }));
}

TEST_F(FoodTest, shouldGenerateSeed)
{
    const auto generatedSeed = Food::seed();

    ASSERT_TRUE(
        std::ranges::any_of(seeds, [generatedSeed](const std::string_view& seed) { return generatedSeed == seed; }));
}

TEST_F(FoodTest, shouldGenerateGrain)
{
    const auto generatedGrain = Food::grain();

    ASSERT_TRUE(std::ranges::any_of(grains, [generatedGrain](const std::string_view& grain)
                                    { return generatedGrain == grain; }));
}

TEST_F(FoodTest, shouldGenerateSugarProduct)
{
    const auto generatedSugarProduct = Food::sugarProduct();

    ASSERT_TRUE(std::ranges::any_of(sugarProducts, [generatedSugarProduct](const std::string_view& sugarProduct)
                                    { return generatedSugarProduct == sugarProduct; }));
}

TEST_F(FoodTest, shouldGenerateVegetable)
{
    const auto generatedVegetable = Food::vegetable();

    ASSERT_TRUE(std::ranges::any_of(vegetables, [generatedVegetable](const std::string_view& vegetable)
                                    { return generatedVegetable == vegetable; }));
}
