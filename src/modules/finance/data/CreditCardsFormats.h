#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> americanExpressCreditCardFormats = {"34##-######-####L", "37##-######-####L"};

const std::vector<std::string> discoverCreditCardFormats = {"6011-####-####-###L",      "65##-####-####-###L",
                                                            "64[4-9]#-####-####-###L",  "6011-62##-####-####-###L",
                                                            "65##-62##-####-####-###L", "64[4-9]#-62##-####-####-###L"};

const std::vector<std::string> masterCardCreditCardFormats = {"5[1-5]##-####-####-###L", "6771-89##-####-###L"};

const std::vector<std::string> visaCreditCardFormats = {"4###########L", "4###-####-####-###L"};
}
