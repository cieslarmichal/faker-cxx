#include <faker/types/address_country.h>

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
    switch (country) {
    case AddressCountry::Usa:
        return "Usa";
    case AddressCountry::Poland:
        return "Poland";
    case AddressCountry::France:
        return "France";
    case AddressCountry::Russia:
        return "Russia";
    case AddressCountry::Ukraine:
        return "Ukraine";
    case AddressCountry::Italy:
        return "Italy";
    case AddressCountry::Germany:
        return "Germany";
    case AddressCountry::Czech:
        return "Czech";
    case AddressCountry::Australia:
        return "Australia";
    case AddressCountry::India:
        return "India";
    case AddressCountry::Denmark:
        return "Denmark";
    case AddressCountry::Spain:
        return "Spain";
    case AddressCountry::Brazil:
        return "Brazil";
    case AddressCountry::Finland:
        return "Finland";
    default:
        throw std::invalid_argument("Invalid country");
    }
}
}