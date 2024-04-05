#include "faker-cxx/Food.h"

#include "data/AlcoholicBeverages.h"
#include "data/DishNames.h"
#include "data/FoodCategories.h"
#include "data/Fruits.h"
#include "data/Grains.h"
#include "data/Meats.h"
#include "data/MilkProducts.h"
#include "data/NonalcoholicBeverages.h"
#include "data/Nuts.h"
#include "data/Oils.h"
#include "data/Seafoods.h"
#include "data/Seeds.h"
#include "data/SugarProducts.h"
#include "data/Vegetables.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Food::alcoholicBeverage()
{
    return Helper::arrayElement<std::string>(alcoholicBeverages);
}

std::string Food::dishName()
{
    return Helper::arrayElement<std::string>(dishNames);
}

std::string Food::foodCategory()
{
    return Helper::arrayElement<std::string>(foodCategories);
}

std::string Food::fruit()
{
    return Helper::arrayElement<std::string>(fruits);
}

std::string Food::grain()
{
    return Helper::arrayElement<std::string>(grains);
}

std::string Food::meat()
{
    return Helper::arrayElement<std::string>(meats);
}

std::string Food::milkProduct()
{
    return Helper::arrayElement<std::string>(milkProducts);
}

std::string Food::nonalcoholicBeverage()
{
    return Helper::arrayElement<std::string>(nonalcoholicBeverages);
}

std::string Food::nut()
{
    return Helper::arrayElement<std::string>(nuts);
}

std::string Food::oil()
{
    return Helper::arrayElement<std::string>(oils);
}

std::string Food::seafood()
{
    return Helper::arrayElement<std::string>(seafoods);
}

std::string Food::seed()
{
    return Helper::arrayElement<std::string>(seeds);
}

std::string Food::sugarProduct()
{
    return Helper::arrayElement<std::string>(sugarProducts);
}

std::string Food::vegetable()
{
    return Helper::arrayElement<std::string>(vegetables);
}
}
