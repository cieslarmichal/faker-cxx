#pragma once

#include <string>
#include <vector>

namespace faker
{
struct CountryAddresses
{
    std::vector<std::string> cities;
    std::string zipCodeFormat;
    std::vector<std::string> addressFormats;
    std::vector<std::string> secondaryAddressFormats;
    std::vector<std::string> streetFormats;
    std::vector<std::string> streetPrefixes;
    std::vector<std::string> streetNames;
    std::vector<std::string> streetSuffixes;
    std::vector<std::string> buildingNumberFormats;
    std::vector<std::string> states;
};
}
