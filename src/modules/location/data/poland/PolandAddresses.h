#pragma once

#include "../CountryAddresses.h"
#include "PolandCities.h"
#include "PolandStreetNames.h"
#include "PolandStreetPrefixes.h"
#include "PolandStates.h"

namespace faker
{
const std::string polandZipCodeFormat{"##-###"};

const std::vector<std::string> polandAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}",
                                                    "{street} {buildingNumber}/{buildingNumber}"};

const std::vector<std::string> polandSecondaryAddressFormats{"m. ###", "m. ##", "m. #"};

const std::vector<std::string> polandBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> polandStreetFormats{"{streetPrefix} {streetName}"};

const std::vector<std::string> polandCityFormats{"{cityName}"};

const CountryAddresses polandAddresses{ polandZipCodeFormat,
                                        polandAddressFormats,
                                        polandSecondaryAddressFormats,
                                        polandStreetFormats,
                                        polandStreetPrefixes,
                                        polandStreetNames,
                                        {},
                                        polandBuildingNumberFormats,
                                        polandCityFormats,
                                        {},
                                        polandCities,
                                        {},
                                        polandStates,
                                        {}};
}
