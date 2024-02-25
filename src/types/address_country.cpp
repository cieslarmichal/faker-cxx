#include <faker/types/address_country.h>
#include <unordered_map>

namespace faker {
const std::array<AddressCountry, 14> addressCountries {
    AddressCountry::Usa,
    AddressCountry::Poland,
    AddressCountry::France,
    AddressCountry::Russia,
    AddressCountry::Ukraine,
    AddressCountry::Italy,
    AddressCountry::Germany,
    AddressCountry::Czech,
    AddressCountry::India,
    AddressCountry::Denmark,
    AddressCountry::Australia,
    AddressCountry::Spain,
    AddressCountry::Brazil,
    AddressCountry::Finland,
};

std::string_view toString(AddressCountry country)
{
    static std::unordered_map<AddressCountry, std::string_view> countryToStringMapping {
        { AddressCountry::Usa, "Usa" },
        { AddressCountry::Poland, "Poland" },
        { AddressCountry::France, "France" },
        { AddressCountry::Russia, "Russia" },
        { AddressCountry::Ukraine, "Ukraine" },
        { AddressCountry::Italy, "Italy" },
        { AddressCountry::Germany, "Germany" },
        { AddressCountry::Czech, "Czech" },
        { AddressCountry::Australia, "Australia" },
        { AddressCountry::India, "India" },
        { AddressCountry::Denmark, "Denmark" },
        { AddressCountry::Spain, "Spain" },
        { AddressCountry::Brazil, "Brazil" },
        { AddressCountry::Finland, "Finland" },
    };

    return countryToStringMapping.at(country);
}
}