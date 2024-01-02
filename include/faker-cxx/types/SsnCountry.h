#pragma once

#include <vector>

namespace faker
{
enum class SsnCountry
{
    Poland,
    UnitedStates,
    UnitedKingdom,
    Germany,
    France,
    Italy,
    Spain,
    India,
};

const std::vector<SsnCountry> supportedSsnCountries{
    SsnCountry::Poland, SsnCountry::UnitedStates, SsnCountry::UnitedKingdom, SsnCountry::Germany,
    SsnCountry::France, SsnCountry::Italy,        SsnCountry::Spain,         SsnCountry::India,
};

inline std::string toString(SsnCountry country)
{
    std::map<SsnCountry, std::string> countryToStringMapping{
        {SsnCountry::UnitedStates, "UnitedStates"},
        {SsnCountry::UnitedKingdom, "UnitedKingdom"},
        {SsnCountry::Poland, "Poland"},
        {SsnCountry::Italy, "Italy"},
        {SsnCountry::France, "France"},
        {SsnCountry::Germany, "Germany"},
        {SsnCountry::India, "India"},
        {SsnCountry::Spain, "Spain"},
    };

    return countryToStringMapping.at(country);
}

inline std::ostream& operator<<(std::ostream& os, SsnCountry country)
{
    return os << toString(country);
}

}
