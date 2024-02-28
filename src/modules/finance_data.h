#ifndef FAKER_MODULES_FINANCE_DATA_H
#define FAKER_MODULES_FINANCE_DATA_H

#include <array>
#include <faker/finance.h>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace faker::finance::data {
extern const std::array<bic_country, 10> bic_countries;
extern const std::array<iban_country, 27> iban_countries;
extern const std::array<std::string_view, 8> account_types;
extern const std::unordered_map<bic_country, std::vector<std::string_view>> bic_countries_codes;
extern const std::array<credit_card_type, 4> credit_card_types;
extern const std::array<std::string_view, 2> american_express_cc_formats;
extern const std::array<std::string_view, 6> discover_cc_formats;
extern const std::array<std::string_view, 2> mastercard_cc_formats;
extern const std::array<std::string_view, 2> visa_cc_formats;
extern const std::array<currency_info, 154> currencies;
extern const std::unordered_map<iban_country, std::vector<std::string_view>> iban_formats;
}

#endif