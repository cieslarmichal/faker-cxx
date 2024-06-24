#include "faker-cxx/Food.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "FoodData.h"

namespace faker::food
{
std::string_view alcoholicBeverage()
{
    return Helper::arrayElement(alcoholicBeverages);
}

std::string_view dishName()
{
    return Helper::arrayElement(dishNames);
}

std::string_view foodCategory()
{
    return Helper::arrayElement(foodCategories);
}

std::string_view fruit()
{
    return Helper::arrayElement(fruits);
}

std::string_view grain()
{
    return Helper::arrayElement(grains);
}

std::string_view meat()
{
    return Helper::arrayElement(meats);
}

std::string_view milkProduct()
{
    return Helper::arrayElement(milkProducts);
}

std::string_view nonalcoholicBeverage()
{
    return Helper::arrayElement(nonalcoholicBeverages);
}

std::string_view nut()
{
    return Helper::arrayElement(nuts);
}

std::string_view oil()
{
    return Helper::arrayElement(oils);
}

std::string_view seafood()
{
    return Helper::arrayElement(seafoods);
}

std::string_view seed()
{
    return Helper::arrayElement(seeds);
}

std::string_view sugarProduct()
{
    return Helper::arrayElement(sugarProducts);
}

std::string_view vegetable()
{
    return Helper::arrayElement(vegetables);
}
}
