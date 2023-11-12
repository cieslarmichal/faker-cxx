#include "faker-cxx/Food.h"

#include "data/alcoholicBeverages.h"
#include "data/dishNames.h"
#include "data/foodCategories.h"
#include "data/fruits.h"
#include "data/grains.h"
#include "data/meats.h"
#include "data/milkProducts.h"
#include "data/nonalcoholicBeverages.h"
#include "data/nuts.h"
#include "data/oils.h"
#include "data/seafoods.h"
#include "data/seeds.h"
#include "data/sugarProducts.h"
#include "data/vegetables.h"

#include "faker-cxx/Helper.h"

namespace faker {

std::string Food::alcoholicBeverage() {
    return Helper::arrayElement<std::string>(alcoholicBeverages);
}

std::string Food::dishName() {
    return Helper::arrayElement<std::string>(dishNames);
}

std::string Food::foodCategory() {
    return Helper::arrayElement<std::string>(foodCategories);
}

std::string Food::fruit() {
    return Helper::arrayElement<std::string>(fruits);
}

std::string Food::grain() {
    return Helper::arrayElement<std::string>(grains);
}

std::string Food::meat() {
    return Helper::arrayElement<std::string>(meats);
}

std::string Food::milkProduct() {
    return Helper::arrayElement<std::string>(milkProducts);
}

std::string Food::nonalcoholicBeverage() {
    return Helper::arrayElement<std::string>(nonalcoholicBeverages);
}

std::string Food::nut() {
    return Helper::arrayElement<std::string>(nuts);
}

std::string Food::oil() {
    return Helper::arrayElement<std::string>(oils);
}

std::string Food::seafood() {
    return Helper::arrayElement<std::string>(seafoods);
}

std::string Food::seed() {
    return Helper::arrayElement<std::string>(seeds);
}

std::string Food::sugarProduct() {
    return Helper::arrayElement<std::string>(sugarProducts);
}

std::string Food::vegetable() {
    return Helper::arrayElement<std::string>(vegetables);
}
}