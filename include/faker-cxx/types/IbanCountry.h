#pragma once

#include <vector>

namespace faker
{
enum class IbanCountry
{
    Poland,
    France,
    Germany,
    Italy
};

const std::vector<IbanCountry> supportedIbanCountries{IbanCountry::Poland, IbanCountry::France, IbanCountry::Germany,
                                                      IbanCountry::Italy};

}
