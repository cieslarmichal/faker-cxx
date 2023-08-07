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

const std::vector<IbanCountry> supportedIbanCountries{
    IbanCountry::Austria,
    IbanCountry::Belgium,
    IbanCountry::Bulgaria,
    IbanCountry::Croatia,
    IbanCountry::Cyprus,
    IbanCountry::Czechia,
    IbanCountry::Denmark,
    IbanCountry::Estonia,
    IbanCountry::Finland,
    IbanCountry::France,
    IbanCountry::Germany,
    IbanCountry::Greece,
    IbanCountry::Hungary,
    IbanCountry::Ireland,
    IbanCountry::Italy,
    IbanCountry::Latvia,
    IbanCountry::Lithuania,
    IbanCountry::Luxembourg,
    IbanCountry::Malta,
    IbanCountry::Netherlands,
    IbanCountry::Poland,
    IbanCountry::Portugal,
    IbanCountry::Romania,
    IbanCountry::Slovakia,
    IbanCountry::Slovenia,
    IbanCountry::Spain,
    IbanCountry::Sweden,
};

}
