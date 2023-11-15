#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::string turkiyeAddressFormat = " {city} {district} {neighbourhood} {street} {buildingNumber}";

const std::vector<std::string> turkiyeBuildingNumberFormats = {"##","/","###"};

const std::string turkiyeZipCodeFormat = "#####";

const std::vector<std::string> turkiyeStreetFormats = {"{mainStreet} {streetName}" };

const std::vector<std::string> turkiyeStreetFormats = {"{streetNumber} {streetPrefix}" };

}