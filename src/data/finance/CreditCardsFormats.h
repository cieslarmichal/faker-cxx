#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> americanExpressCreditCardFormats = {"34##-######-####", "37##-######-####"};

const std::vector<std::string> discoverCreditCardFormats = {"6011-####-####-###",      "65##-####-####-###",
                                                            "647#-####-####-###",      "6011-62##-####-####-###",
                                                            "65##-62##-####-####-###", "648#-62##-####-####-###"};

const std::vector<std::string> masterCardCreditCardFormats = {"58##-####-####-###", "6771-89##-####-###"};

const std::vector<std::string> visaCreditCardFormats = {"4###########", "4###-####-####-###"};
}
