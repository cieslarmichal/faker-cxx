#pragma once

#include <string>
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

const std::vector<IbanCountry> ibanCountries = {IbanCountry::Poland, IbanCountry::France, IbanCountry::Germany,
                                                IbanCountry::Italy};

}
