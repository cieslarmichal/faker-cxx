#include <faker/types/country.h>
#include <stdexcept>

namespace faker {

const std::array<Country, 61> countries {
    Country::Usa,
    Country::England,
    Country::Poland,
    Country::Italy,
    Country::France,
    Country::Germany,
    Country::Russia,
    Country::Romania,
    Country::India,
    Country::Finland,
    Country::Nepal,
    Country::Spain,
    Country::Turkey,
    Country::Czech,
    Country::Slovakia,
    Country::Ukraine,
    Country::Denmark,
    Country::Sweden,
    Country::Brazil,
    Country::Norway,
    Country::Japan,
    Country::Portugal,
    Country::Hungary,
    Country::Croatia,
    Country::Greece,
    Country::Slovenia,
    Country::Austria,
    Country::Switzerland,
    Country::Belgium,
    Country::Netherlands,
    Country::China,
    Country::Korea,
    Country::Canada,
    Country::Mexico,
    Country::Argentina,
    Country::Australia,
    Country::Serbia,
    Country::Macedonia,
    Country::Albania,
    Country::Latvia,
    Country::Ireland,
    Country::Belarus,
    Country::Estonia,
    Country::Iran,
    Country::Bulgaria,
    Country::Moldova,
    Country::Lithuania,
    Country::Iceland,
    Country::Palestine,
    Country::Israel,
    Country::Vietnam,
    Country::Monaco,
    Country::Bosnia,
    Country::Lebanon,
    Country::Syria,
    Country::Malta,
    Country::SouthAfrica,
    Country::Azerbaijan,
    Country::Ghana,
    Country::Kazakhstan,
    Country::Maldives,
};

std::string_view toString(Country country)
{
    switch (country) {
    case Country::Usa:
        return "Usa";
    case Country::England:
        return "England";
    case Country::Poland:
        return "Poland";
    case Country::Italy:
        return "Italy";
    case Country::France:
        return "France";
    case Country::Germany:
        return "Germany";
    case Country::Russia:
        return "Russia";
    case Country::Romania:
        return "Romania";
    case Country::India:
        return "India";
    case Country::Finland:
        return "Finland";
    case Country::Nepal:
        return "Nepal";
    case Country::Spain:
        return "Spain";
    case Country::Turkey:
        return "Turkey";
    case Country::Czech:
        return "Czech";
    case Country::Slovakia:
        return "Slovakia";
    case Country::Ukraine:
        return "Ukraine";
    case Country::Denmark:
        return "Denmark";
    case Country::Sweden:
        return "Sweden";
    case Country::Brazil:
        return "Brazil";
    case Country::Norway:
        return "Norway";
    case Country::Japan:
        return "Japan";
    case Country::Portugal:
        return "Portugal";
    case Country::Hungary:
        return "Hungary";
    case Country::Croatia:
        return "Croatia";
    case Country::Greece:
        return "Greece";
    case Country::Slovenia:
        return "Slovenia";
    case Country::Austria:
        return "Austria";
    case Country::Switzerland:
        return "Switzerland";
    case Country::Belgium:
        return "Belgium";
    case Country::Netherlands:
        return "Netherlands";
    case Country::China:
        return "China";
    case Country::Korea:
        return "Korea";
    case Country::Canada:
        return "Canada";
    case Country::Mexico:
        return "Mexico";
    case Country::Argentina:
        return "Argentina";
    case Country::Australia:
        return "Australia";
    case Country::Serbia:
        return "Serbia";
    case Country::Macedonia:
        return "Macedonia";
    case Country::Albania:
        return "Albania";
    case Country::Latvia:
        return "Latvia";
    case Country::Ireland:
        return "Ireland";
    case Country::Belarus:
        return "Belarus";
    case Country::Estonia:
        return "Estonia";
    case Country::Iran:
        return "Iran";
    case Country::Bulgaria:
        return "Bulgaria";
    case Country::Moldova:
        return "Moldova";
    case Country::Lithuania:
        return "Lithuania";
    case Country::Iceland:
        return "Iceland";
    case Country::Palestine:
        return "Palestine";
    case Country::Israel:
        return "Israel";
    case Country::Vietnam:
        return "Vietnam";
    case Country::Monaco:
        return "Monaco";
    case Country::Bosnia:
        return "Bosnia";
    case Country::Lebanon:
        return "Lebanon";
    case Country::Syria:
        return "Syria";
    case Country::Malta:
        return "Malta";
    case Country::SouthAfrica:
        return "South Africa";
    case Country::Azerbaijan:
        return "Azerbaijan";
    case Country::Ghana:
        return "Ghana";
    case Country::Kazakhstan:
        return "Kazakhstan";
    case Country::Maldives:
        return "Maldives";
    default:
        throw std::invalid_argument("Invalid country");
    }
}

}