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
    Turkiye,
    England,
    Romania,
    India,
    Finland,
    Nepal,
    Spain,
    Czech,
    Slovakia,
    Ukraine,
    Denmark,
    Sweden,
};

const std::vector<Country> countries{
    Country::Usa,    Country::England, Country::Poland,   Country::Italy,   Country::France,  Country::Germany,
    Country::Russia, Country::Romania, Country::India,    Country::Finland, Country::Nepal,   Country::Spain,
    Country::Turkiye, Country::Czech,   Country::Slovakia, Country::Ukraine, Country::Denmark, Country::Sweden};

inline std::string toString(Country country)
{
    std::map<Country, std::string> countryToStringMapping{
        {Country::Usa, "Usa"},         {Country::England, "England"}, {Country::Poland, "Poland"},
        {Country::Italy, "Italy"},     {Country::France, "France"},   {Country::Germany, "Germany"},
        {Country::Russia, "Russia"},   {Country::Romania, "Romania"}, {Country::India, "India"},
        {Country::Finland, "Finland"}, {Country::Nepal, "Nepal"},     {Country::Spain, "Spain"},
        {Country::Turkiye, "Turkiye"},   {Country::Czech, "Czech"},     {Country::Slovakia, "Slovakia"},
        {Country::Ukraine, "Ukraine"}, {Country::Denmark, "Denmark"}, {Country::Sweden, "Sweden"}};

    return countryToStringMapping.at(country);
}

inline std::ostream& operator<<(std::ostream& os, Country country)
{
    return os << toString(country);
}
}
