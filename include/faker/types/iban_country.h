#ifndef FAKER_TYPES_IBAN_COUNTRY_H
#define FAKER_TYPES_IBAN_COUNTRY_H

#include <array>

namespace faker {
enum class IbanCountry {
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

extern const std::array<IbanCountry, 27> supportedIbanCountries;

}

#endif