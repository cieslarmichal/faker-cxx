#pragma once

#include <array>
#include <string_view>

namespace faker {
constexpr unsigned int kMinDiscountCodeLength = 6;
constexpr unsigned int kMaxDiscountCodeLength = 12;
constexpr double kMinDiscountAmountValue = 10.;
constexpr double kMaxDiscountAmountValue = 1000.;
constexpr double kMinDiscountPercentageValue = 1.;
constexpr double kMaxDiscountPercentageValue = 90.;

extern const std::array<std::string_view, 22> departments;
extern const std::array<std::string_view, 24> productAdjectives;
extern const std::array<std::string_view, 12> productMaterials;
extern const std::array<std::string_view, 24> productNames;
extern const std::array<std::string_view, 5> paymentTypes;
extern const std::array<std::string_view, 7> paymentProviders;
extern const std::array<std::string_view, 18> productDescriptions;
extern const std::array<std::string_view, 20> productCategoryNames;
extern const std::array<std::string_view, 20> productReviews;
extern const std::array<std::string_view, 2> discountTypes;
}
