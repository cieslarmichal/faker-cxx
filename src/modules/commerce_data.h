#ifndef FAKER_MODULES_COMMERCE_DATA_H
#define FAKER_MODULES_COMMERCE_DATA_H

#include <array>
#include <string_view>

namespace faker::commerce::data {
constexpr unsigned min_discount_code_length = 6;
constexpr unsigned max_discount_code_length = 12;
constexpr double min_discount_amount = 10.;
constexpr double max_discount_amount = 1000.;
constexpr double min_discount_percentage = 1.;
constexpr double max_discount_percentage = 90.;

extern const std::array<std::string_view, 22> departments;
extern const std::array<std::string_view, 24> product_adjectives;
extern const std::array<std::string_view, 12> product_materials;
extern const std::array<std::string_view, 24> product_names;
extern const std::array<std::string_view, 5> payment_types;
extern const std::array<std::string_view, 7> payment_providers;
extern const std::array<std::string_view, 18> product_descriptions;
extern const std::array<std::string_view, 20> product_category_names;
extern const std::array<std::string_view, 20> product_reviews;
extern const std::array<std::string_view, 2> discount_types;
}

#endif