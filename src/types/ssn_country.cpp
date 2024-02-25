#include <faker/types/ssn_country.h>
#include <unordered_map>

namespace faker {
const std::array<SsnCountry, 8> supportedSsnCountries {
    SsnCountry::Poland,
    SsnCountry::UnitedStates,
    SsnCountry::UnitedKingdom,
    SsnCountry::Germany,
    SsnCountry::France,
    SsnCountry::Italy,
    SsnCountry::Spain,
    SsnCountry::India,
};

std::string_view toString(SsnCountry country)
{
    static std::unordered_map<SsnCountry, std::string_view> countryToStringMapping {
        { SsnCountry::UnitedStates, "UnitedStates" },
        { SsnCountry::UnitedKingdom, "UnitedKingdom" },
        { SsnCountry::Poland, "Poland" },
        { SsnCountry::Italy, "Italy" },
        { SsnCountry::France, "France" },
        { SsnCountry::Germany, "Germany" },
        { SsnCountry::India, "India" },
        { SsnCountry::Spain, "Spain" },
    };

    return countryToStringMapping.at(country);
}

}
