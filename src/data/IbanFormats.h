#pragma once

#include <map>
#include <string>
#include <vector>

#include "types/Country.h"

namespace faker
{
// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::map<Country, std::vector<std::string>> ibanFormats{
    {Country::Poland, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {Country::France, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {Country::Italy, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {Country::Germany, {"DE", "2n", "8n", "10n"}},
};

const std::vector<Country> supportedIbanCountries{Country::Poland};

}
