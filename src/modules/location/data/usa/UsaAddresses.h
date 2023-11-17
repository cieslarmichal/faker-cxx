#pragma once

#include "../CountryAddresses.h"
#include "UsaCities.h"
#include "UsaStreetSuffixes.h"

namespace faker
{
const std::string usaZipCodeFormat{"#####"};

const std::vector<std::string> usaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> usaSecondaryAddressFormats{"Apt. ###", "Suite ###"};

const std::vector<std::string> usaBuildingNumberFormats{"#####", "####", "###"};

const std::vector<std::string> usaStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const CountryAddresses usaAddresses{
    usaCities, usaZipCodeFormat,  usaAddressFormats,       usaSecondaryAddressFormats, usaStreetFormats, {},
    {},        usaStreetSuffixes, usaBuildingNumberFormats};
}
