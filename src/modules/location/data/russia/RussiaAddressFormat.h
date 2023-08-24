#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::string russiaAddressFormat = "{street} {buildingNumber}";

const std::vector<std::string> russiaBuildingNumberFormats = {"#", "##", "###"};

const std::string russiaZipCodeFormat = "######";

const std::vector<std::string> russiaStreetFormats = {"{streetPrefix} {firstName}", "{streetPrefix} {lastName}", "{streetPrefix} {streetName}"};

}
