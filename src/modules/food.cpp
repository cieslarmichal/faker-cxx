#include "../common/helper.h"
#include "food_data.h"
#include <faker/food.h>

namespace faker::food {

std::string_view alcoholicBeverage() { return Helper::arrayElement(data::alcoholicBeverages); }

std::string_view dishName() { return Helper::arrayElement(data::dishNames); }

std::string_view foodCategory() { return Helper::arrayElement(data::foodCategories); }

std::string_view fruit() { return Helper::arrayElement(data::fruits); }

std::string_view grain() { return Helper::arrayElement(data::grains); }

std::string_view meat() { return Helper::arrayElement(data::meats); }

std::string_view milkProduct() { return Helper::arrayElement(data::milkProducts); }

std::string_view nonalcoholicBeverage()
{
    return Helper::arrayElement(data::nonalcoholicBeverages);
}

std::string_view nut() { return Helper::arrayElement(data::nuts); }

std::string_view oil() { return Helper::arrayElement(data::oils); }

std::string_view seafood() { return Helper::arrayElement(data::seafoods); }

std::string_view seed() { return Helper::arrayElement(data::seeds); }

std::string_view sugarProduct() { return Helper::arrayElement(data::sugarProducts); }

std::string_view vegetable() { return Helper::arrayElement(data::vegetables); }
}
