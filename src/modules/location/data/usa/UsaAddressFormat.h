#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::string usaAddressFormat = "{buildingNumber} {street}";

const std::vector<std::string> usaBuildingNumberFormats = {"#####", "####", "###"};

const std::string usaZipCodeFormat = "#####";

const std::vector<std::string> usaSecondaryAddressFormats = {"Apt. ###", "Suite ###"};

const std::vector<std::string> usaStreetFormats = {"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

}
