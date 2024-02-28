#include "../common/formatter.h"
#include "../common/random.h"
#include "commerce_data.h"
#include <faker/commerce.h>
#include <faker/finance.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::commerce {
std::string_view department() { return random::element(data::departments); }

std::string price(double min, double max) { return finance::amount(min, max); }

std::string sku(unsigned int length) { return string::numeric(length, false); }

std::string_view product_adjective() { return random::element(data::product_adjectives); }

std::string_view product_material() { return random::element(data::product_materials); }

std::string_view product_name() { return random::element(data::product_names); }

std::string product_full_name()
{
    return utils::format("{} {} {}", product_adjective(), product_material(), product_name());
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

    int check_digit = sum % 10;

    if (check_digit != 0) {
        check_digit = 10 - check_digit;
    }

    return ean13 + std::to_string(check_digit);
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

    int check_digit = sum % 10;

    if (check_digit != 0) {
        check_digit = 10 - check_digit;
    }

    return ean8 + std::to_string(check_digit);
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

    int check_digit = sum % 10;

    if (check_digit != 0) {
        check_digit = 10 - check_digit;
    }

    return isbn13 + std::to_string(check_digit);
}

std::string isbn10()
{
    std::string isbn10 = string::numeric(9, true);

    int sum = 0, weight = 10;
    for (size_t i = 0; i < 9; i++) {
        sum += (isbn10[i] - '0') * weight;
        weight--;
    }

    int check_digit = sum % 11;

    if (check_digit != 0) {
        check_digit = 11 - check_digit;
    }

    if (check_digit == 10) {
        return isbn10 + "X";
    }

    return isbn10 + std::to_string(check_digit);
}

std::string product_id() { return string::alphanumeric(10, string::string_case::upper, ""); }

std::string_view payment_type() { return random::element(data::payment_types); }

std::string_view payment_provider() { return random::element(data::payment_providers); }

std::string_view product_description() { return random::element(data::product_descriptions); }

std::string_view product_category() { return random::element(data::product_category_names); }

std::string_view product_review() { return random::element(data::product_reviews); }

double product_rating() { return std::ceil(number::decimal(5.) * 100) / 100; }

std::string_view discount_type() { return random::element(data::discount_types); }

std::string discount_code()
{
    return string::alphanumeric(
        number::integer(data::min_discount_code_length, data::max_discount_code_length),
        string::string_case::upper);
}

double discount_amount()
{
    return std::ceil(number::decimal(data::min_discount_amount, data::max_discount_amount) * 100)
        / 100;
}

double discount_percentage()
{
    return std::ceil(
               number::decimal(data::min_discount_percentage, data::max_discount_percentage) * 100)
        / 100;
}

}
