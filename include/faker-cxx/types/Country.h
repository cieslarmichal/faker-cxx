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
};

const std::vector<Country> countries{
    Country::Usa,    Country::England, Country::Poland,   Country::Italy,    Country::France,  Country::Germany,
    Country::Russia, Country::Romania, Country::India,    Country::Finland,  Country::Nepal,   Country::Spain,
    Country::Turkey, Country::Czech,   Country::Slovakia, Country::Ukraine,  Country::Denmark, Country::Sweden,
    Country::Brazil, Country::Norway,  Country::Japan,    Country::Portugal, Country::Hungary, Country::Croatia};

inline std::string toString(Country country)
{
    std::map<Country, std::string> countryToStringMapping{
        {Country::Usa, "Usa"},           {Country::England, "England"}, {Country::Poland, "Poland"},
        {Country::Italy, "Italy"},       {Country::France, "France"},   {Country::Germany, "Germany"},
        {Country::Russia, "Russia"},     {Country::Romania, "Romania"}, {Country::India, "India"},
        {Country::Finland, "Finland"},   {Country::Nepal, "Nepal"},     {Country::Spain, "Spain"},
        {Country::Turkey, "Turkey"},     {Country::Czech, "Czech"},     {Country::Slovakia, "Slovakia"},
        {Country::Ukraine, "Ukraine"},   {Country::Denmark, "Denmark"}, {Country::Sweden, "Sweden"},
        {Country::Brazil, "Brazil"},     {Country::Norway, "Norway"},   {Country::Japan, "Japan"},
        {Country::Portugal, "Portugal"}, {Country::Hungary, "Hungary"}, {Country::Croatia, "Croatia"},
    };

    return countryToStringMapping.at(country);
}

inline std::ostream& operator<<(std::ostream& os, Country country)
{
    return os << toString(country);
}
}
