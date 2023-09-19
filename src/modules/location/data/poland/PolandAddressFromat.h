#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::string polandAddressFormat = "{street} {buildingNumber}";

const std::vector<std::string> polandBuildingNumberFormats = {"#", "##", "###"};

const std::string polandZipCodeFormat = "##-###";

const std::vector<std::string> polandStreetFormats = {"{streetPrefix} {streetName}"};

}