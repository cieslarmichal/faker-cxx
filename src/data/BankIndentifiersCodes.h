#pragma once

#include <map>
#include <string>
#include <vector>

#include "include/faker-cxx/types/Country.h"

namespace faker
{
const std::map<Country, std::vector<std::string>> bankIdentifiersCodesMapping = {
    {Country::Poland,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}}

};

const std::vector<Country> supportedBankIdentifiersCodesCountries{Country::Poland};
}
