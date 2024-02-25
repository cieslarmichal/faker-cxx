#include <faker/types/country.h>

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
    static std::unordered_map<Country, std::string_view> countryToStringMapping {
        { Country::Usa, "Usa" },
        { Country::England, "England" },
        { Country::Poland, "Poland" },
        { Country::Italy, "Italy" },
        { Country::France, "France" },
        { Country::Germany, "Germany" },
        { Country::Russia, "Russia" },
        { Country::Romania, "Romania" },
        { Country::India, "India" },
        { Country::Finland, "Finland" },
        { Country::Nepal, "Nepal" },
        { Country::Spain, "Spain" },
        { Country::Turkey, "Turkey" },
        { Country::Czech, "Czech" },
        { Country::Slovakia, "Slovakia" },
        { Country::Ukraine, "Ukraine" },
        { Country::Denmark, "Denmark" },
        { Country::Sweden, "Sweden" },
        { Country::Brazil, "Brazil" },
        { Country::Norway, "Norway" },
        { Country::Japan, "Japan" },
        { Country::Portugal, "Portugal" },
        { Country::Hungary, "Hungary" },
        { Country::Croatia, "Croatia" },
        { Country::Greece, "Greece" },
        { Country::Slovenia, "Slovenia" },
        { Country::Austria, "Austria" },
        { Country::Switzerland, "Switzerland" },
        { Country::Belgium, "Belgium" },
        { Country::Netherlands, "Netherlands" },
        { Country::China, "China" },
        { Country::Korea, "Korea" },
        { Country::Canada, "Canada" },
        { Country::Mexico, "Mexico" },
        { Country::Argentina, "Argentina" },
        { Country::Australia, "Australia" },
        { Country::Serbia, "Serbia" },
        { Country::Macedonia, "Macedonia" },
        { Country::Albania, "Albania" },
        { Country::Latvia, "Latvia" },
        { Country::Ireland, "Ireland" },
        { Country::Belarus, "Belarus" },
        { Country::Estonia, "Estonia" },
        { Country::Iran, "Iran" },
        { Country::Bulgaria, "Bulgaria" },
        { Country::Moldova, "Moldova" },
        { Country::Lithuania, "Lithuania" },
        { Country::Iceland, "Iceland" },
        { Country::Palestine, "Palestine" },
        { Country::Israel, "Israel" },
        { Country::Vietnam, "Vietnam" },
        { Country::Monaco, "Monaco" },
        { Country::Bosnia, "Bosnia" },
        { Country::Lebanon, "Lebanon" },
        { Country::Syria, "Syria" },
        { Country::Malta, "Malta" },
        { Country::SouthAfrica, "South Africa" },
        { Country::Azerbaijan, "Azerbaijan" },
        { Country::Ghana, "Ghana" },
        { Country::Kazakhstan, "Kazakhstan" },
        { Country::Maldives, "Maldives" },
    };

    return countryToStringMapping.at(country);
}

}