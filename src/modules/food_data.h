#ifndef FAKER_MODULES_FOOD_DATA_H
#define FAKER_MODULES_FOOD_DATA_H

#include <array>
#include <string_view>

namespace faker::food::data {
extern const std::array<std::string_view, 47> alcoholicBeverages;
extern const std::array<std::string_view, 85> dishNames;
extern const std::array<std::string_view, 11> foodCategories;
extern const std::array<std::string_view, 41> fruits;
extern const std::array<std::string_view, 28> grains;
extern const std::array<std::string_view, 21> meats;
extern const std::array<std::string_view, 32> milkProducts;
extern const std::array<std::string_view, 31> nonalcoholicBeverages;
extern const std::array<std::string_view, 11> nuts;
extern const std::array<std::string_view, 20> oils;
extern const std::array<std::string_view, 28> seafoods;
extern const std::array<std::string_view, 29> seeds;
extern const std::array<std::string_view, 24> sugarProducts;
extern const std::array<std::string_view, 30> vegetables;
}

#endif