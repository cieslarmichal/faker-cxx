#pragma once

#include <map>
#include <string>
#include <vector>

namespace faker
{
// TODO: remove when AddressCountry enum values will be same as Country values
enum class AddressCountry
{
    Usa,
    Poland,
    France,
    Russia,
};

const std::vector<AddressCountry> addressCountries{
    AddressCountry::Usa,
    AddressCountry::Poland,
    AddressCountry::France,
    AddressCountry::Russia,
};

inline std::string toString(AddressCountry country)
{
    std::map<AddressCountry, std::string> countryToStringMapping{
        {AddressCountry::Usa, "Usa"},
        {AddressCountry::Poland, "Poland"},
        {AddressCountry::France, "France"},
        {AddressCountry::Russia, "Russia"},
    };

    return countryToStringMapping.at(country);
}

inline std::ostream& operator<<(std::ostream& os, AddressCountry country)
{
    return os << toString(country);
}
}
