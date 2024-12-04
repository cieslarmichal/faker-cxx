#include "faker-cxx/food.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "food_data.h"

namespace faker::food
{
namespace
{
const struct FoodDefinition& getFoodDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSFoodDefinition;
    }
}
}

std::string_view alcoholicBeverage(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.alcoholicBeverages);
}

std::string_view dishName(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.dishNames);
}

std::string_view foodCategory(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.foodCategories);
}

std::string_view fruit(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.fruits);
}

std::string_view grain(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.grains);
}

std::string_view meat(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.meats);
}

std::string_view milkProduct(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.milkProducts);
}

std::string_view nonalcoholicBeverage(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.nonalcoholicBeverages);
}

std::string_view nut(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.nuts);
}

std::string_view oil(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.oils);
}

std::string_view seafood(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.seafoods);
}

std::string_view seed(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.seeds);
}

std::string_view sugarProduct(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.sugarProducts);
}

std::string_view vegetable(Locale locale)
{
    const auto& foodDefinition = getFoodDefinition(locale);
    return helper::randomElement(foodDefinition.vegetables);
}
}
