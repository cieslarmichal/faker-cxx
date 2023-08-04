#pragma once

#include <vector>

namespace faker
{
enum class IbanCountry
{
    Austria,
    Belgium,
    Bulgaria,
    Croatia,
    Cyprus,
    Czechia,
    Denmark,
    Estonia,
    Finland,
    France,
    Germany,
    Greece,
    Hungary,
    Ireland,
    Italy,
    Latvia,
    Lithuania,
    Luxembourg,
    Malta,
    Netherlands,
    Poland,
    Portugal,
    Romania,
    Slovakia,
    Slovenia,
    Spain,
    Sweden
};

const std::vector<IbanCountry> supportedIbanCountries{IbanCountry::Poland, IbanCountry::France, IbanCountry::Germany,
                                                      IbanCountry::Italy};

}
