#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/food.h"
#include "food_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::food;

namespace 
{
    const struct FoodDefinition& getFoodDefinition(Locale locale)
    {
        switch(locale)
        {
            default:
                return enUSFoodDefinition;
        }
    }
}

class FoodTest : public TestWithParam<Locale>
{
public:
};

TEST_P(FoodTest, shouldGenerateAlcoholicBeverage)
{
    const auto locale = GetParam();

    const auto& foodDefinition = getFoodDefinition(locale);

    const auto generatedAlcoholicBeverage = alcoholicBeverage(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.alcoholicBeverages,
                                    [generatedAlcoholicBeverage](const std::string_view& alcoholicBeverage)
                                    { return generatedAlcoholicBeverage == alcoholicBeverage; }));
}

TEST_P(FoodTest, shouldGenerateDishName)
{
    const auto locale = GetParam();

    const auto& foodDefinition = getFoodDefinition(locale);

    const auto generatedDishName = dishName(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.dishNames, [generatedDishName](const std::string_view& dishName)
                                    { return generatedDishName == dishName; }));
}

TEST_P(FoodTest, shouldGenerateFoodCategories)
{
    const auto locale = GetParam();

    const auto& foodDefinition = getFoodDefinition(locale);

    const auto generatedFoodCategory = foodCategory(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.foodCategories, [generatedFoodCategory](const std::string_view& foodCategory)
                                    { return generatedFoodCategory == foodCategory; }));
}

TEST_P(FoodTest, shouldGenerateFruit)
{
    const auto locale = GetParam();

    const auto& foodDefinition = getFoodDefinition(locale);

    const auto generatedFruit = fruit(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.fruits, [generatedFruit](const std::string_view& fruit)
                                    { return generatedFruit == fruit; }));
}

TEST_P(FoodTest, shouldGenerateMeat)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedMeat = meat(locale);

    ASSERT_TRUE(
        std::ranges::any_of(foodDefinition.meats, [generatedMeat](const std::string_view& meat) { return generatedMeat == meat; }));
}

TEST_P(FoodTest, shouldGenerateMilkProduct)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedMilkProduct = milkProduct(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.milkProducts, [generatedMilkProduct](const std::string_view& milkProduct)
                                    { return generatedMilkProduct == milkProduct; }));
}

TEST_P(FoodTest, shouldGenerateNonalcoholicBeverages)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedNonalcoholicBeverages = nonalcoholicBeverage(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.nonalcoholicBeverages,
                                    [generatedNonalcoholicBeverages](const std::string_view& nonalcoholicBeverage)
                                    { return generatedNonalcoholicBeverages == nonalcoholicBeverage; }));
}

TEST_P(FoodTest, shouldGenerateNut)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedNut = nut(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.nuts, [generatedNut](const std::string_view& nut) { return generatedNut == nut; }));
}

TEST_P(FoodTest, shouldGenerateOil)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedOil = oil(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.oils, [generatedOil](const std::string_view& oil) { return generatedOil == oil; }));
}

TEST_P(FoodTest, shouldGenerateSeafood)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedSeafood = seafood(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.seafoods, [generatedSeafood](const std::string_view& seafood)
                                    { return generatedSeafood == seafood; }));
}

TEST_P(FoodTest, shouldGenerateSeed)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedSeed = seed(locale);

    ASSERT_TRUE(
        std::ranges::any_of(foodDefinition.seeds, [generatedSeed](const std::string_view& seed) { return generatedSeed == seed; }));
}

TEST_P(FoodTest, shouldGenerateGrain)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedGrain = grain(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.grains, [generatedGrain](const std::string_view& grain)
                                    { return generatedGrain == grain; }));
}

TEST_P(FoodTest, shouldGenerateSugarProduct)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedSugarProduct = sugarProduct(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.sugarProducts, [generatedSugarProduct](const std::string_view& sugarProduct)
                                    { return generatedSugarProduct == sugarProduct; }));
}

TEST_P(FoodTest, shouldGenerateVegetable)
{
    const auto locale = GetParam();
    const auto& foodDefinition = getFoodDefinition(locale);
    const auto generatedVegetable = vegetable(locale);

    ASSERT_TRUE(std::ranges::any_of(foodDefinition.vegetables, [generatedVegetable](const std::string_view& vegetable)
                                    { return generatedVegetable == vegetable; }));
}

INSTANTIATE_TEST_SUITE_P(TestFoodByLocale, FoodTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });

