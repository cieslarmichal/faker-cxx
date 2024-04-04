#pragma once

#include "../CountryAddresses.h"
#include "UsaCities.h"
#include "UsaStates.h"
#include "UsaStreetSuffixes.h"

namespace faker
{
const std::string usaZipCodeFormat{"#####"};

const std::vector<std::string> usaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> usaSecondaryAddressFormats{"Apt. ###", "Suite ###"};

const std::vector<std::string> usaBuildingNumberFormats{"#####", "####", "###"};

const std::vector<std::string> usaStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> usaCityFormats{"{cityName}"};

const CountryAddresses usaAddresses{usaZipCodeFormat,
                                    usaAddressFormats,
                                    usaSecondaryAddressFormats,
                                    usaStreetFormats,
                                    {},
                                    {},
                                    usaStreetSuffixes,
                                    usaBuildingNumberFormats,
                                    usaCityFormats,
                                    {},
                                    usaCities,
                                    {},
                                    usaStates,
                                    {}};
}
