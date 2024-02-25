#include "../test_helpers.h"
#include <algorithm>
#include <faker/food.h>
#include <modules/food_data.h>

using namespace ::testing;
using namespace faker;

class FoodTest : public Test {
public:
};

TEST_F(FoodTest, shouldGenerateAlcoholicBeverage)
{
    const auto generatedAlcoholicBeverage = food::alcoholicBeverage();

    ASSERT_TRUE(faker::testing::contains(alcoholicBeverages, generatedAlcoholicBeverage));
}

TEST_F(FoodTest, shouldGenerateDishName)
{
    const auto generatedDishName = food::dishName();

    ASSERT_TRUE(faker::testing::contains(dishNames, generatedDishName));
}

TEST_F(FoodTest, shouldGenerateFoodCategories)
{
    const auto generatedFoodCategory = food::foodCategory();

    ASSERT_TRUE(faker::testing::contains(foodCategories, generatedFoodCategory));
}

TEST_F(FoodTest, shouldGenerateFruit)
{
    const auto generatedFruit = food::fruit();

    ASSERT_TRUE(faker::testing::contains(fruits, generatedFruit));
}

TEST_F(FoodTest, shouldGenerateMeat)
{
    const auto generatedMeat = food::meat();

    ASSERT_TRUE(faker::testing::contains(meats, generatedMeat));
}

TEST_F(FoodTest, shouldGenerateMilkProduct)
{
    const auto generatedMilkProduct = food::milkProduct();

    ASSERT_TRUE(faker::testing::contains(milkProducts, generatedMilkProduct));
}

TEST_F(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    const auto generatedNonalcoholicBeverages = food::nonalcoholicBeverage();

    ASSERT_TRUE(faker::testing::contains(nonalcoholicBeverages, generatedNonalcoholicBeverages));
}

TEST_F(FoodTest, shouldGenerateNut)
{
    const auto generatedNut = food::nut();

    ASSERT_TRUE(faker::testing::contains(nuts, generatedNut));
}

TEST_F(FoodTest, shouldGenerateOil)
{
    const auto generatedOil = food::oil();

    ASSERT_TRUE(faker::testing::contains(oils, generatedOil));
}

TEST_F(FoodTest, shouldGenerateSeafood)
{
    const auto generatedSeafood = food::seafood();

    ASSERT_TRUE(faker::testing::contains(seafoods, generatedSeafood));
}

TEST_F(FoodTest, shouldGenerateSeed)
{
    const auto generatedSeed = food::seed();

    ASSERT_TRUE(faker::testing::contains(seeds, generatedSeed));
}

TEST_F(FoodTest, shouldGenerateGrain)
{
    const auto generatedGrain = food::grain();

    ASSERT_TRUE(faker::testing::contains(grains, generatedGrain));
}

TEST_F(FoodTest, shouldGenerateSugarProduct)
{
    const auto generatedSugarProduct = food::sugarProduct();

    ASSERT_TRUE(faker::testing::contains(sugarProducts, generatedSugarProduct));
}

TEST_F(FoodTest, shouldGenerateVegetable)
{
    const auto generatedVegetable = food::vegetable();

    ASSERT_TRUE(faker::testing::contains(vegetables, generatedVegetable));
}
