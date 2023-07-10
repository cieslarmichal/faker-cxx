#pragma once

#include <map>
#include <string>
#include <vector>

#include "types/BicCountry.h"

namespace faker
{
const std::map<BicCountry, std::vector<std::string>> bankIdentifiersCodesMapping = {
    {BicCountry::Poland,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}}

};
}
