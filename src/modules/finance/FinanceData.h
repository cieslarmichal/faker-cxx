#pragma once

#include <array>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "faker-cxx/Finance.h"

namespace faker
{
extern const std::array<Finance::BicCountry, 10> bicCountries;
extern const std::array<Finance::IbanCountry, 27> ibanCountries;
extern const std::array<std::string_view, 8> accountTypes;
extern const std::unordered_map<Finance::BicCountry, std::vector<std::string_view>> bicCountriesCodes;
extern const std::array<Finance::CreditCardType, 4> creditCardTypes;
extern const std::array<std::string_view, 4> creditCardNames;
extern const std::array<std::string_view, 2> americanExpressCreditCardFormats;
extern const std::array<std::string_view, 6> discoverCreditCardFormats;
extern const std::array<std::string_view, 2> masterCardCreditCardFormats;
extern const std::array<std::string_view, 2> visaCreditCardFormats;
extern const std::array<Currency, 154> currencies;
extern const std::unordered_map<Finance::IbanCountry, std::vector<std::string_view>> ibanFormats;
}
