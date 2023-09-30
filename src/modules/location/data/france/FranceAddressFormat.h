#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::string franceAddressFormat = "{buildingNumber} {street}";

const std::vector<std::string> franceBuildingNumberFormats = {"####", "###", "##", "#"};

const std::string franceZipCodeFormat = "#####";

const std::vector<std::string> franceSecondaryAddressFormats = {"Apt. ###", "Étage #"};

const std::vector<std::string> franceStreetFormats = {"{streetPrefix} {streetSuffix}"};

}
