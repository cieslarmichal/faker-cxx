#ifndef FAKER_TYPES_BIC_COUNTRY_H
#define FAKER_TYPES_BIC_COUNTRY_H

#include <array>

namespace faker {
enum class BicCountry {
    Poland,
    United_States,
    United_Kingdom,
    Germany,
    Romania,
    France,
    Italy,
    Spain,
    Netherlands,
    India,
};

extern const std::array<BicCountry, 10> supportedBicCountries;

}

#endif