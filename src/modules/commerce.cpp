#include "../common/format_helper.h"
#include "../common/helper.h"
#include "commerce_data.h"
#include <faker/commerce.h>
#include <faker/finance.h>
#include <faker/string.h>

namespace faker::commerce {
std::string_view department() { return Helper::arrayElement(data::departments); }

std::string price(double min, double max) { return finance::amount(min, max); }

std::string sku(unsigned int length) { return string::numeric(length, false); }

std::string_view product_adjective() { return Helper::arrayElement(data::productAdjectives); }

std::string_view product_material() { return Helper::arrayElement(data::productMaterials); }

std::string_view product_name() { return Helper::arrayElement(data::productNames); }

std::string product_full_name()
{
    return FormatHelper::format(
        "{} {} {}", product_adjective(), product_material(), product_name());
}

std::string ean13()
{
    std::string ean13 = string::numeric(12, false);

    int sum = 0;
    for (size_t i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            sum += (ean13[i] - '0');
        } else {
            sum += 3 * (ean13[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0) {
        checkDigit = 10 - checkDigit;
    }

    return ean13 + std::to_string(checkDigit);
}

std::string ean8()
{
    std::string ean8 = string::numeric(7, false);

    int sum = 0;
    for (size_t i = 0; i < 7; i++) {
        if (i % 2 == 0) {
            sum += 3 * (ean8[i] - '0');
        } else {
            sum += (ean8[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0) {
        checkDigit = 10 - checkDigit;
    }

    return ean8 + std::to_string(checkDigit);
}

std::string isbn13()
{
    std::string isbn13 = string::numeric(12, true);

    int sum = 0;
    for (size_t i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            sum += (isbn13[i] - '0');
        } else {
            sum += 3 * (isbn13[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0) {
        checkDigit = 10 - checkDigit;
    }

    return isbn13 + std::to_string(checkDigit);
}

std::string isbn10()
{
    std::string isbn10 = string::numeric(9, true);

    int sum = 0, weight = 10;
    for (size_t i = 0; i < 9; i++) {
        sum += (isbn10[i] - '0') * weight;
        weight--;
    }

    int checkDigit = sum % 11;

    if (checkDigit != 0) {
        checkDigit = 11 - checkDigit;
    }

    if (checkDigit == 10) {
        return isbn10 + "X";
    }

    return isbn10 + std::to_string(checkDigit);
}

std::string product_id() { return string::alphanumeric(10, string::StringCasing::Upper, ""); }

std::string_view payment_type() { return Helper::arrayElement(data::paymentTypes); }

std::string_view payment_provider() { return Helper::arrayElement(data::paymentProviders); }

std::string_view product_description() { return Helper::arrayElement(data::productDescriptions); }

std::string_view product_category() { return Helper::arrayElement(data::productCategoryNames); }

std::string_view product_review() { return Helper::arrayElement(data::productReviews); }

double product_rating()
{
    auto ratingValue = number::decimal(5.);
    return std::ceil(ratingValue * 100) / 100;
}

std::string_view discount_type() { return Helper::arrayElement(data::discountTypes); }

std::string discount_code()
{
    auto codeLength = number::integer(data::kMinDiscountCodeLength, data::kMaxDiscountCodeLength);
    return string::alphanumeric(codeLength, string::StringCasing::Upper);
}

double discount_amount()
{
    auto amountValue
        = number::decimal(data::kMinDiscountAmountValue, data::kMaxDiscountAmountValue);
    return std::ceil(amountValue * 100) / 100;
}

double discount_percentage()
{
    auto percentageValue
        = number::decimal(data::kMinDiscountPercentageValue, data::kMaxDiscountPercentageValue);
    return std::ceil(percentageValue * 100) / 100;
}

}
