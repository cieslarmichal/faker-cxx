#pragma once

#include <map>
#include <string>
#include <vector>

namespace faker
{
enum class Country
{
    Usa,
    Poland,
    France,
    Germany,
    Italy,
    Russia,
    England,
    Romania,
    India,
    Finland,
    Nepal,
    Spain,
    Turkey,
    Czech,
    Slovakia,
    Ukraine,
    Denmark,
    Sweden,
    Brazil,
    Norway,
    Japan,
    Portugal,
    Hungary,
    Croatia,
    Greece,
    Slovenia,
    Austria,
    Switzerland,
    Belgium,
    Netherlands,
    China,
    Korea,
    Canada,
    Mexico,
    Argentina,
    Australia,
    Serbia,
    Macedonia,
    Albania,
    Latvia,
    Ireland,
    Belarus,
    Estonia,
    Iran,
    Bulgaria,
    Moldova,
    Lithuania,
    Iceland,
    Palestine,
    Israel,
    Monaco
};

const std::vector<Country> countries{
    Country::Usa,       Country::England,   Country::Poland,      Country::Italy,     Country::France,
    Country::Germany,   Country::Russia,    Country::Romania,     Country::India,     Country::Finland,
    Country::Nepal,     Country::Spain,     Country::Turkey,      Country::Czech,     Country::Slovakia,
    Country::Ukraine,   Country::Denmark,   Country::Sweden,      Country::Brazil,    Country::Norway,
    Country::Japan,     Country::Portugal,  Country::Hungary,     Country::Croatia,   Country::Greece,
    Country::Slovenia,  Country::Austria,   Country::Switzerland, Country::Belgium,   Country::Netherlands,
    Country::China,     Country::Korea,     Country::Canada,      Country::Mexico,    Country::Argentina,
    Country::Australia, Country::Serbia,    Country::Macedonia,   Country::Albania,   Country::Latvia,
    Country::Ireland,   Country::Belarus,   Country::Estonia,     Country::Iran,      Country::Bulgaria,
    Country::Moldova,   Country::Lithuania, Country::Iceland,     Country::Palestine, Country::Israel,
    Country::Monaco,
};

inline std::string toString(Country country)
{
    std::map<Country, std::string> countryToStringMapping{
        {Country::Usa, "Usa"},
        {Country::England, "England"},
        {Country::Poland, "Poland"},
        {Country::Italy, "Italy"},
        {Country::France, "France"},
        {Country::Germany, "Germany"},
        {Country::Russia, "Russia"},
        {Country::Romania, "Romania"},
        {Country::India, "India"},
        {Country::Finland, "Finland"},
        {Country::Nepal, "Nepal"},
        {Country::Spain, "Spain"},
        {Country::Turkey, "Turkey"},
        {Country::Czech, "Czech"},
        {Country::Slovakia, "Slovakia"},
        {Country::Ukraine, "Ukraine"},
        {Country::Denmark, "Denmark"},
        {Country::Sweden, "Sweden"},
        {Country::Brazil, "Brazil"},
        {Country::Norway, "Norway"},
        {Country::Japan, "Japan"},
        {Country::Portugal, "Portugal"},
        {Country::Hungary, "Hungary"},
        {Country::Croatia, "Croatia"},
        {Country::Greece, "Greece"},
        {Country::Slovenia, "Slovenia"},
        {Country::Austria, "Austria"},
        {Country::Switzerland, "Switzerland"},
        {Country::Belgium, "Belgium"},
        {Country::Netherlands, "Netherlands"},
        {Country::China, "China"},
        {Country::Korea, "Korea"},
        {Country::Canada, "Canada"},
        {Country::Mexico, "Mexico"},
        {Country::Argentina, "Argentina"},
        {Country::Australia, "Australia"},
        {Country::Serbia, "Serbia"},
        {Country::Macedonia, "Macedonia"},
        {Country::Albania, "Albania"},
        {Country::Latvia, "Latvia"},
        {Country::Ireland, "Ireland"},
        {Country::Belarus, "Belarus"},
        {Country::Estonia, "Estonia"},
        {Country::Iran, "Iran"},
        {Country::Bulgaria, "Bulgaria"},
        {Country::Moldova, "Moldova"},
        {Country::Lithuania, "Lithuania"},
        {Country::Iceland, "Iceland"},
        {Country::Palestine, "Palestine"},
        {Country::Israel, "Israel"},
        {Country::Monaco, "Monaco"},
    };

    return countryToStringMapping.at(country);
}

inline std::ostream& operator<<(std::ostream& os, Country country)
{
    return os << toString(country);
}
}
