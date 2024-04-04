#pragma once

#include <vector>

namespace faker
{
enum class BicCountry
{
    Poland,
    United_States,
    United_Kingdom,
    Germany,
    Romania,
    France,
    Italy,
    Spain,
    Netherlands,
    India,
};

const std::vector<BicCountry> supportedBicCountries{
    BicCountry::Poland,      BicCountry::United_States, BicCountry::United_Kingdom, BicCountry::Germany,
    BicCountry::Romania,     BicCountry::France,        BicCountry::Italy,          BicCountry::Spain,
    BicCountry::Netherlands, BicCountry::India};

}
