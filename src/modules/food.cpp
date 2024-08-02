#include "faker-cxx/food.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "food_data.h"

namespace faker::food
{
std::string_view alcoholicBeverage()
{
    return helper::randomElement(alcoholicBeverages);
}

std::string_view dishName()
{
    return helper::randomElement(dishNames);
}

std::string_view foodCategory()
{
    return helper::randomElement(foodCategories);
}

std::string_view fruit()
{
    return helper::randomElement(fruits);
}

std::string_view grain()
{
    return helper::randomElement(grains);
}

std::string_view meat()
{
    return helper::randomElement(meats);
}

std::string_view milkProduct()
{
    return helper::randomElement(milkProducts);
}

std::string_view nonalcoholicBeverage()
{
    return helper::randomElement(nonalcoholicBeverages);
}

std::string_view nut()
{
    return helper::randomElement(nuts);
}

std::string_view oil()
{
    return helper::randomElement(oils);
}

std::string_view seafood()
{
    return helper::randomElement(seafoods);
}

std::string_view seed()
{
    return helper::randomElement(seeds);
}

std::string_view sugarProduct()
{
    return helper::randomElement(sugarProducts);
}

std::string_view vegetable()
{
    return helper::randomElement(vegetables);
}
}
