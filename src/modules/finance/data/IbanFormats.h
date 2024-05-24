#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "faker-cxx/Finance.h"

namespace faker
{
// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::unordered_map<Finance::IbanCountry, std::vector<std::string>> ibanFormats{
    {Finance::IbanCountry::Austria, {"AT", "2n", "5n", "11n"}},
    {Finance::IbanCountry::Belgium, {"BE", "2n", "3n", "7n", "2n"}},
    {Finance::IbanCountry::Bulgaria, {"BG", "2n", "4a", "4n", "2n", "8c"}},
    {Finance::IbanCountry::Croatia, {"HR", "2n", "7n", "10n"}},
    {Finance::IbanCountry::Cyprus, {"CY", "2n", "3n", "5n", "16c"}},
    {Finance::IbanCountry::Czechia, {"CZ", "2n", "4n", "6n", "10n"}},
    {Finance::IbanCountry::Denmark, {"DK", "2n", "4n", "9n", "1n"}},
    {Finance::IbanCountry::Estonia, {"EE", "2n", "2n", "2n", "11n", "1n"}},
    {Finance::IbanCountry::Finland, {"FI", "2n", "6n", "7n", "1n"}},
    {Finance::IbanCountry::France, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {Finance::IbanCountry::Germany, {"DE", "2n", "8n", "10n"}},
    {Finance::IbanCountry::Greece, {"GR", "2n", "3n", "4n", "16c"}},
    {Finance::IbanCountry::Hungary, {"HU", "2n", "3n", "4n", "1n", "15n", "1n"}},
    {Finance::IbanCountry::Ireland, {"IE", "2n", "4a", "6n", "8n"}},
    {Finance::IbanCountry::Italy, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {Finance::IbanCountry::Latvia, {"LV", "2n", "4a", "13n"}},
    {Finance::IbanCountry::Lithuania, {"LT", "2n", "5n", "11n"}},
    {Finance::IbanCountry::Luxembourg, {"LU", "2n", "3n", "13c"}},
    {Finance::IbanCountry::Malta, {"MT", "2n", "4a", "5n", "18c"}},
    {Finance::IbanCountry::Netherlands, {"NL", "2n", "4a", "10n"}},
    {Finance::IbanCountry::Poland, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {Finance::IbanCountry::Portugal, {"PT", "2n", "4n", "4n", "11n", "2n"}},
    {Finance::IbanCountry::Romania, {"RO", "2n", "4a", "16c"}},
    {Finance::IbanCountry::Slovakia, {"SK", "2n", "4n", "6n", "10n"}},
    {Finance::IbanCountry::Slovenia, {"SI", "2n", "2n", "3n", "8n", "2n"}},
    {Finance::IbanCountry::Spain, {"ES", "2n", "4n", "4n", "2n", "10n"}},
    {Finance::IbanCountry::Sweden, {"SE", "2n", "3n", "16n", "1n"}},
};
}
