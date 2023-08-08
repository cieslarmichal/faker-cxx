#pragma once

#include <map>
#include <string>
#include <vector>
#include <ranges>

#include "faker-cxx/types/IbanCountry.h"

namespace faker
{
// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::map<IbanCountry, std::vector<std::string>> ibanFormats{
    {IbanCountry::Austria, {"AT", "2n", "5n", "11n"}},
    {IbanCountry::Belgium, {"BE", "2n", "3n", "7n", "2n"}},
    {IbanCountry::Bulgaria, {"BG", "2n", "4a", "4n", "2n", "8c"}},
    {IbanCountry::Croatia, {"HR", "2n", "7n", "10n"}},
    {IbanCountry::Cyprus, {"CY", "2n", "3n", "5n", "16c"}},
    {IbanCountry::Czechia, {"CZ", "2n", "4n", "6n", "10n"}},
    {IbanCountry::Denmark, {"DK", "2n", "4n", "9n", "1n"}},
    {IbanCountry::Estonia, {"EE", "2n", "2n", "2n", "11n", "1n"}},
    {IbanCountry::Finland, {"FI", "2n", "6n", "7n", "1n"}},
    {IbanCountry::France, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {IbanCountry::Germany, {"DE", "2n", "8n", "10n"}},
    {IbanCountry::Greece, {"GR", "2n", "3n", "4n", "16c"}},
    {IbanCountry::Hungary, {"HU", "2n", "3n", "4n", "1n", "15n", "1n"}},
    {IbanCountry::Ireland, {"IE", "2n", "4a", "6n", "8n"}},
    {IbanCountry::Italy, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {IbanCountry::Latvia, {"LV", "2n", "4a", "13n"}},
    {IbanCountry::Lithuania, {"LT", "2n", "5n", "11n"}},
    {IbanCountry::Luxembourg, {"LU", "2n", "3n", "13c"}},
    {IbanCountry::Malta, {"MT", "2n", "4a", "5n", "18c"}},
    {IbanCountry::Netherlands, {"NL", "2n", "4a", "10n"}},
    {IbanCountry::Poland, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {IbanCountry::Portugal, {"PT", "2n", "4n", "4n", "11n", "2n"}},
    {IbanCountry::Romania, {"RO", "2n", "4a", "16c"}},
    {IbanCountry::Slovakia, {"SK", "2n", "4n", "6n", "10n"}},
    {IbanCountry::Slovenia, {"SI", "2n", "2n", "3n", "8n", "2n"}},
    {IbanCountry::Spain, {"ES", "2n", "4n", "4n", "2n", "10n"}},
    {IbanCountry::Sweden, {"SE", "2n", "3n", "16n", "1n"}},
};
}
