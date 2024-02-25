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

    FAKER_EXPECT_CONTAINS(alcoholicBeverages, generatedAlcoholicBeverage);
}

TEST_F(FoodTest, shouldGenerateDishName)
{
    const auto generatedDishName = food::dishName();

    FAKER_EXPECT_CONTAINS(dishNames, generatedDishName);
}

TEST_F(FoodTest, shouldGenerateFoodCategories)
{
    const auto generatedFoodCategory = food::foodCategory();

    FAKER_EXPECT_CONTAINS(foodCategories, generatedFoodCategory);
}

TEST_F(FoodTest, shouldGenerateFruit)
{
    const auto generatedFruit = food::fruit();

    FAKER_EXPECT_CONTAINS(fruits, generatedFruit);
}

TEST_F(FoodTest, shouldGenerateMeat)
{
    const auto generatedMeat = food::meat();

    FAKER_EXPECT_CONTAINS(meats, generatedMeat);
}

TEST_F(FoodTest, shouldGenerateMilkProduct)
{
    const auto generatedMilkProduct = food::milkProduct();

    FAKER_EXPECT_CONTAINS(milkProducts, generatedMilkProduct);
}

TEST_F(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    const auto generatedNonalcoholicBeverages = food::nonalcoholicBeverage();

    FAKER_EXPECT_CONTAINS(nonalcoholicBeverages, generatedNonalcoholicBeverages);
}

TEST_F(FoodTest, shouldGenerateNut)
{
    const auto generatedNut = food::nut();

    FAKER_EXPECT_CONTAINS(nuts, generatedNut);
}

TEST_F(FoodTest, shouldGenerateOil)
{
    const auto generatedOil = food::oil();

    FAKER_EXPECT_CONTAINS(oils, generatedOil);
}

TEST_F(FoodTest, shouldGenerateSeafood)
{
    const auto generatedSeafood = food::seafood();

    FAKER_EXPECT_CONTAINS(seafoods, generatedSeafood);
}

TEST_F(FoodTest, shouldGenerateSeed)
{
    const auto generatedSeed = food::seed();

    FAKER_EXPECT_CONTAINS(seeds, generatedSeed);
}

TEST_F(FoodTest, shouldGenerateGrain)
{
    const auto generatedGrain = food::grain();

    FAKER_EXPECT_CONTAINS(grains, generatedGrain);
}

TEST_F(FoodTest, shouldGenerateSugarProduct)
{
    const auto generatedSugarProduct = food::sugarProduct();

    FAKER_EXPECT_CONTAINS(sugarProducts, generatedSugarProduct);
}

TEST_F(FoodTest, shouldGenerateVegetable)
{
    const auto generatedVegetable = food::vegetable();

    FAKER_EXPECT_CONTAINS(vegetables, generatedVegetable);
}
