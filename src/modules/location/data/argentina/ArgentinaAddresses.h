#pragma once

#include "../CountryAddresses.h"
#include "ArgentinaCities.h"
#include "ArgentinaStates.h"
#include "ArgentinaStreetPrefixes.h"

namespace faker
{
const std::string argentinaZipCodeFormat{"####"};

const std::vector<std::string> argentinaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> argentinaBuildingNumberFormats{"####", "###", "##"};

const std::vector<std::string> argentinaStreetFormats{"{streetPrefix} {firstName}", "{streetPrefix} {lastName}"};

const std::vector<std::string> argentinaCityFormats{"{cityName}"};

const CountryAddresses argentinaAddresses{argentinaZipCodeFormat,
                                          argentinaAddressFormats,
                                          {},
                                          argentinaStreetFormats,
                                          argentinaStreetPrefixes,
                                          {},
                                          {},
                                          argentinaBuildingNumberFormats,
                                          argentinaCityFormats,
                                          {},
                                          argentinaCities,
                                          {},
                                          argentinaStates,
                                          {}};
}
