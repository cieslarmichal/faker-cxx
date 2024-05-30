#include "faker-cxx/Food.h"

#include "faker-cxx/Helper.h"
#include "FoodData.h"

namespace faker
{
std::string_view Food::alcoholicBeverage()
{
    return Helper::arrayElement(alcoholicBeverages);
}

std::string_view Food::dishName()
{
    return Helper::arrayElement(dishNames);
}

std::string_view Food::foodCategory()
{
    return Helper::arrayElement(foodCategories);
}

std::string_view Food::fruit()
{
    return Helper::arrayElement(fruits);
}

std::string_view Food::grain()
{
    return Helper::arrayElement(grains);
}

std::string_view Food::meat()
{
    return Helper::arrayElement(meats);
}

std::string_view Food::milkProduct()
{
    return Helper::arrayElement(milkProducts);
}

std::string_view Food::nonalcoholicBeverage()
{
    return Helper::arrayElement(nonalcoholicBeverages);
}

std::string_view Food::nut()
{
    return Helper::arrayElement(nuts);
}

std::string_view Food::oil()
{
    return Helper::arrayElement(oils);
}

std::string_view Food::seafood()
{
    return Helper::arrayElement(seafoods);
}

std::string_view Food::seed()
{
    return Helper::arrayElement(seeds);
}

std::string_view Food::sugarProduct()
{
    return Helper::arrayElement(sugarProducts);
}

std::string_view Food::vegetable()
{
    return Helper::arrayElement(vegetables);
}
}
