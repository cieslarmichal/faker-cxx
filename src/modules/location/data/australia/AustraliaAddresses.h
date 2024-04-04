#pragma once

#include "../CountryAddresses.h"
#include "AustraliaCities.h"
#include "AustraliaStates.h"
#include "AustraliaStreetSuffixes.h"

namespace faker
{
const std::string australiaZipCodeFormat{"####"};

const std::vector<std::string> australiaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> australiaBuildingNumberFormats{"####", "###", "##"};

const std::vector<std::string> australiaStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> australiaCityFormats{"{cityName}"};

const CountryAddresses australiaAddresses{australiaZipCodeFormat,
                                          australiaAddressFormats,
                                          {},
                                          australiaStreetFormats,
                                          {},
                                          {},
                                          australiaStreetSuffixes,
                                          australiaBuildingNumberFormats,
                                          australiaCityFormats,
                                          {},
                                          australiaCities,
                                          {},
                                          australiaStates,
                                          {}};
}
