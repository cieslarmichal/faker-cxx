#ifndef FAKER_MODULES_FINANCE_DATA_H
#define FAKER_MODULES_FINANCE_DATA_H

#include <array>
#include <faker/finance.h>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace faker::finance::data {
extern const std::array<BicCountry, 10> supportedBicCountries;
extern const std::array<IbanCountry, 27> supportedIbanCountries;
extern const std::array<std::string_view, 8> accountTypes;
extern const std::unordered_map<BicCountry, std::vector<std::string_view>>
    bankIdentifiersCodesMapping;
extern const std::array<std::string_view, 2> americanExpressCreditCardFormats;
extern const std::array<std::string_view, 6> discoverCreditCardFormats;
extern const std::array<std::string_view, 2> masterCardCreditCardFormats;
extern const std::array<std::string_view, 2> visaCreditCardFormats;
extern const std::array<Currency, 154> currencies;
extern const std::unordered_map<IbanCountry, std::vector<std::string_view>> ibanFormats;
}

#endif