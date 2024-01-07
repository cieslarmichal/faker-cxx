#pragma once

#include "../CountryAddresses.h"
#include "AustraliaStates.h"
#include "AustraliaStreetSuffixes.h"
#include "AustraliaCities.h"

namespace faker
{
const std::string australiaZipCodeFormat{"####"};

const std::vector<std::string> australiaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> australiaBuildingNumberFormats{"####", "###", "##"};

const std::vector<std::string> australiaStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};



const CountryAddresses australiaAddresses{australiaCities,
                                     australiaZipCodeFormat,
                                     australiaAddressFormats,
                                     {},
                                     australiaStreetFormats,
                                     {},
                                     {},
                                     australiaStreetSuffixes,
                                     australiaBuildingNumberFormats,
                                     australiaStates };
}
