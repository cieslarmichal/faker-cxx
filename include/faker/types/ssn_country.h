#ifndef FAKER_TYPES_SSN_COUNTRY_H
#define FAKER_TYPES_SSN_COUNTRY_H

#include <array>
#include <string_view>

namespace faker {
enum class SsnCountry {
    Poland,
    UnitedStates,
    UnitedKingdom,
    Germany,
    France,
    Italy,
    Spain,
    India,
};

extern const std::array<SsnCountry, 8> supportedSsnCountries;

std::string_view toString(SsnCountry country);

}

#endif