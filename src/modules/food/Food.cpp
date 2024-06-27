#include "faker-cxx/Food.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "FoodData.h"

namespace faker::food
{
std::string_view alcoholicBeverage()
{
    return helper::arrayElement(alcoholicBeverages);
}

std::string_view dishName()
{
    return helper::arrayElement(dishNames);
}

std::string_view foodCategory()
{
    return helper::arrayElement(foodCategories);
}

std::string_view fruit()
{
    return helper::arrayElement(fruits);
}

std::string_view grain()
{
    return helper::arrayElement(grains);
}

std::string_view meat()
{
    return helper::arrayElement(meats);
}

std::string_view milkProduct()
{
    return helper::arrayElement(milkProducts);
}

std::string_view nonalcoholicBeverage()
{
    return helper::arrayElement(nonalcoholicBeverages);
}

std::string_view nut()
{
    return helper::arrayElement(nuts);
}

std::string_view oil()
{
    return helper::arrayElement(oils);
}

std::string_view seafood()
{
    return helper::arrayElement(seafoods);
}

std::string_view seed()
{
    return helper::arrayElement(seeds);
}

std::string_view sugarProduct()
{
    return helper::arrayElement(sugarProducts);
}

std::string_view vegetable()
{
    return helper::arrayElement(vegetables);
}
}
