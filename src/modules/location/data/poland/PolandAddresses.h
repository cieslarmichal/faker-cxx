#pragma once

#include "../CountryAddresses.h"
#include "PolandCities.h"
#include "PolandStreetNames.h"
#include "PolandStreetPrefixes.h"

namespace faker
{
const std::string polandZipCodeFormat{"##-###"};

const std::vector<std::string> polandAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}",
                                                    "{street} {buildingNumber}/{buildingNumber}"};

const std::vector<std::string> polandSecondaryAddressFormats{"m. ###", "m. ##", "m. #"};

const std::vector<std::string> polandBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> polandStreetFormats{"{streetPrefix} {streetName}"};

const CountryAddresses polandAddresses{polandCities,
                                       polandZipCodeFormat,
                                       polandAddressFormats,
                                       polandSecondaryAddressFormats,
                                       polandStreetFormats,
                                       polandStreetPrefixes,
                                       polandStreetNames,
                                       {},
                                       polandBuildingNumberFormats};
}
