#include "../test_helpers.h"
#include <faker/food.h>
#include <modules/food_data.h>

using namespace faker;

TEST(FoodTest, shouldGenerateAlcoholicBeverage)
{
    auto generatedAlcoholicBeverage = food::alcoholic_beverage();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::alcoholicBeverages, generatedAlcoholicBeverage);
}

TEST(FoodTest, shouldGenerateDishName)
{
    auto generatedDishName = food::dish_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::dishNames, generatedDishName);
}

TEST(FoodTest, shouldGenerateFoodCategories)
{
    auto generatedFoodCategory = food::category();

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
    auto generatedMilkProduct = food::milk_product();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::milkProducts, generatedMilkProduct);
}

TEST(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    auto generatedNonalcoholicBeverages = food::non_alcoholic_beverage();

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
    auto generatedSugarProduct = food::sugar_product();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::sugarProducts, generatedSugarProduct);
}

TEST(FoodTest, shouldGenerateVegetable)
{
    auto generatedVegetable = food::vegetable();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::vegetables, generatedVegetable);
}
