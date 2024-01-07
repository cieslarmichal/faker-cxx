#pragma once

#include "../CountryAddresses.h"
#include "FranceCities.h"
#include "FranceStreetPrefixes.h"
#include "FranceStreetSuffixes.h"
#include "FranceStates.h"

namespace faker
{
const std::string franceZipCodeFormat{"#####"};

const std::vector<std::string> franceAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> franceBuildingNumberFormats{"####", "###", "##", "#"};

const std::vector<std::string> franceSecondaryAddressFormats{"Apt. ###", "Étage #"};

const std::vector<std::string> franceStreetFormats{"{streetPrefix} {streetSuffix}"};

const CountryAddresses franceAddresses{franceCities,
                                       franceZipCodeFormat,
                                       franceAddressFormats,
                                       franceSecondaryAddressFormats,
                                       franceStreetFormats,
                                       franceStreetPrefixes,
                                       {},
                                       franceStreetSuffixes,
                                       franceBuildingNumberFormats,
                                       franceStates };
}
