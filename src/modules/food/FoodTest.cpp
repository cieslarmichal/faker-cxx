#include "faker-cxx/Food.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/alcoholicBeverages.h"
#include "data/dishNames.h"
#include "data/foodCategories.h"
#include "data/fruits.h"
#include "data/grains.h"
#include "data/meats.h"
#include "data/milkProducts.h"
#include "data/nonalcoholicBeverages.h"
#include "data/nuts.h"
#include "data/oils.h"
#include "data/seafoods.h"
#include "data/seeds.h"
#include "data/sugarProducts.h"
#include "data/vegetables.h"

using namespace ::testing;
using namespace faker;

class FoodTest : public Test
{
public:
};

TEST_F(FoodTest, shouldGenerateAlcoholicBeverage)
{
    const auto generatedAlcoholicBeverage = Food::alcoholicBeverage();

    ASSERT_TRUE(
        std::ranges::any_of(alcoholicBeverages, [generatedAlcoholicBeverage](const std::string& alcoholicBeverage) { return generatedAlcoholicBeverage == alcoholicBeverage; }));
}

TEST_F(FoodTest, shouldGenerateDishName)
{
    const auto generatedDishName = Food::dishName();

    ASSERT_TRUE(std::ranges::any_of(dishNames, [generatedDishName](const std::string& dishName)
                                    { return generatedDishName == dishName; }));
}

TEST_F(FoodTest, shouldGenerateFoodCategories)
{
    const auto generatedFoodCategory = Food::foodCategory();

    ASSERT_TRUE(std::ranges::any_of(foodCategories, [generatedFoodCategory](const std::string& foodCategory)
                                    { return generatedFoodCategory == foodCategory; }));
}

TEST_F(FoodTest, shouldGenerateFruit)
{
    const auto generatedFruit = Food::fruit();

    ASSERT_TRUE(
        std::ranges::any_of(fruits, [generatedFruit](const std::string& fruit) { return generatedFruit == fruit; }));
}

TEST_F(FoodTest, shouldGenerateMeat)
{
    const auto generatedMeat = Food::meat();

    ASSERT_TRUE(std::ranges::any_of(meats, [generatedMeat](const std::string& meat)
                                    { return generatedMeat == meat; }));
}

TEST_F(FoodTest, shouldGenerateMilkProduct)
{
    const auto generatedMilkProduct = Food::milkProduct();

    ASSERT_TRUE(std::ranges::any_of(milkProducts, [generatedMilkProduct](const std::string& milkProduct)
                                    { return generatedMilkProduct == milkProduct; }));
}

TEST_F(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    const auto generatedNonalcoholicBeverages = Food::nonalcoholicBeverage();

    ASSERT_TRUE(std::ranges::any_of(nonalcoholicBeverages, [generatedNonalcoholicBeverages](const std::string& nonalcoholicBeverage)
                                    { return generatedNonalcoholicBeverages == nonalcoholicBeverage; }));
}

TEST_F(FoodTest, shouldGenerateNut)
{
    const auto generatedNut = Food::nut();

    ASSERT_TRUE(std::ranges::any_of(nuts, [generatedNut](const std::string& nut)
                                    { return generatedNut == nut; }));
}

TEST_F(FoodTest, shouldGenerateOil)
{
    const auto generatedOil = Food::oil();

    ASSERT_TRUE(std::ranges::any_of(oils, [generatedOil](const std::string& oil)
                                    { return generatedOil == oil; }));
}

TEST_F(FoodTest, shouldGenerateSeafood)
{
    const auto generatedSeafood = Food::seafood();

    ASSERT_TRUE(std::ranges::any_of(seafoods, [generatedSeafood](const std::string& seafood)
                                    { return generatedSeafood == seafood; }));
}

TEST_F(FoodTest, shouldGenerateSeed)
{
    const auto generatedSeed = Food::seed();

    ASSERT_TRUE(std::ranges::any_of(seeds, [generatedSeed](const std::string& seed)
                                    { return generatedSeed == seed; }));
}

TEST_F(FoodTest, shouldGenerateSugarProduct)
{
    const auto generatedSugarProduct = Food::sugarProduct();

    ASSERT_TRUE(std::ranges::any_of(sugarProducts, [generatedSugarProduct](const std::string& sugarProduct)
                                    { return generatedSugarProduct == sugarProduct; }));
}

TEST_F(FoodTest, shouldGenerateVegetable)
{
    const auto generatedVegetable = Food::vegetable();

    ASSERT_TRUE(std::ranges::any_of(vegetables, [generatedVegetable](const std::string& vegetable)
                                    { return generatedVegetable == vegetable; }));
}
