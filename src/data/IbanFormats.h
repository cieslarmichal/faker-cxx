#pragma once

#include <string>
#include <vector>

#include "types/IbanCountry.h"

namespace faker
{
// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::map<IbanCountry, std::vector<std::string>> ibanFormats{
    {IbanCountry::Poland, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {IbanCountry::France, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {IbanCountry::Italy, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {IbanCountry::Germany, {"DE", "2n", "8n", "10n"}},
};
}
