#include <faker/types/ssn_country.h>
#include <stdexcept>

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
    switch (country) {
    case SsnCountry::UnitedStates:
        return "UnitedStates";
    case SsnCountry::UnitedKingdom:
        return "UnitedKingdom";
    case SsnCountry::Poland:
        return "Poland";
    case SsnCountry::Italy:
        return "Italy";
    case SsnCountry::France:
        return "France";
    case SsnCountry::Germany:
        return "Germany";
    case SsnCountry::India:
        return "India";
    case SsnCountry::Spain:
        return "Spain";
    default:
        throw std::invalid_argument("Invalid country");
    }
}

}
