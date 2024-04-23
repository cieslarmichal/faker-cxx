#pragma once

#include "../CountryAddresses.h"
#include "BelgiumCities.h"
#include "BelgiumStates.h"
#include "BelgiumStreetSuffixes.h"
#include "BelgiumStreetPrefixes.h"

namespace faker
{
const std::string belgiumZipCodeFormat{"####"};

const std::vector<std::string> belgiumAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> belgiumSecondaryAddressFormats{"Apt. ###", "Étage #"};

const std::vector<std::string> belgiumBuildingNumberFormats{ "#", "##", "###", "###a", "###b", "###c", "###/2",};

const std::vector<std::string> belgiumStreetFormats{"{streetPrefix} {streetSuffix}"};

const std::vector<std::string> belgiumCityFormats{"{cityName}"};

const CountryAddresses belgiumAddresses{belgiumZipCodeFormat,
                                    belgiumAddressFormats,
                                    belgiumSecondaryAddressFormats,
                                    belgiumStreetFormats,
                                    belgiumStreetPrefixes,
                                    {},
                                    belgiumStreetSuffixes,
                                    belgiumBuildingNumberFormats,
                                    belgiumCityFormats,
                                    {},
                                    belgiumCities,
                                    {},
                                    belgiumStates,
                                    {}};
}
