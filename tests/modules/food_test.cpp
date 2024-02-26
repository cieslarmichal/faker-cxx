#include "../test_helpers.h"
#include <faker/food.h>
#include <modules/food_data.h>

using namespace faker;

TEST(FoodTest, shouldGenerateAlcoholicBeverage)
{
    auto generatedAlcoholicBeverage = food::alcoholicBeverage();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::alcoholicBeverages, generatedAlcoholicBeverage);
}

TEST(FoodTest, shouldGenerateDishName)
{
    auto generatedDishName = food::dishName();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::dishNames, generatedDishName);
}

TEST(FoodTest, shouldGenerateFoodCategories)
{
    auto generatedFoodCategory = food::foodCategory();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::foodCategories, generatedFoodCategory);
}

TEST(FoodTest, shouldGenerateFruit)
{
    auto generatedFruit = food::fruit();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::fruits, generatedFruit);
}

TEST(FoodTest, shouldGenerateMeat)
{
    auto generatedMeat = food::meat();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::meats, generatedMeat);
}

TEST(FoodTest, shouldGenerateMilkProduct)
{
    auto generatedMilkProduct = food::milkProduct();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::milkProducts, generatedMilkProduct);
}

TEST(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    auto generatedNonalcoholicBeverages = food::nonalcoholicBeverage();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        food::data::nonalcoholicBeverages, generatedNonalcoholicBeverages);
}

TEST(FoodTest, shouldGenerateNut)
{
    auto generatedNut = food::nut();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::nuts, generatedNut);
}

TEST(FoodTest, shouldGenerateOil)
{
    auto generatedOil = food::oil();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::oils, generatedOil);
}

TEST(FoodTest, shouldGenerateSeafood)
{
    auto generatedSeafood = food::seafood();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::seafoods, generatedSeafood);
}

TEST(FoodTest, shouldGenerateSeed)
{
    auto generatedSeed = food::seed();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::seeds, generatedSeed);
}

TEST(FoodTest, shouldGenerateGrain)
{
    auto generatedGrain = food::grain();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::grains, generatedGrain);
}

TEST(FoodTest, shouldGenerateSugarProduct)
{
    auto generatedSugarProduct = food::sugarProduct();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::sugarProducts, generatedSugarProduct);
}

TEST(FoodTest, shouldGenerateVegetable)
{
    auto generatedVegetable = food::vegetable();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::vegetables, generatedVegetable);
}
