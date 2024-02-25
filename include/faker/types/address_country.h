#ifndef FAKER_TYPES_ADDRESS_COUNTRY_H
#define FAKER_TYPES_ADDRESS_COUNTRY_H

#include <array>
#include <string_view>

namespace faker {
// TODO: remove when AddressCountry enum values will be same as Country values
enum class AddressCountry {
    Usa,
    Poland,
    France,
    Russia,
    Ukraine,
    Italy,
    Germany,
    Czech,
    Australia,
    India,
    Denmark,
    Spain,
    Brazil,
    Finland,
    Estonia
};

extern const std::array<AddressCountry, 14> addressCountries;

std::string_view toString(AddressCountry country);
}

#endif