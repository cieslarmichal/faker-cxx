#pragma once

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
