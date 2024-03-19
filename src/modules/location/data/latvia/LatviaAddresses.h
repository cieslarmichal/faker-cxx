#pragma once

#include "../CountryAddresses.h"
#include "LatviaCities.h"
#include "LatviaStates.h"
#include "LatviaStreetNames.h"

namespace faker
{
const std::string latviaZipCodeFormat{"LV####"};

const std::vector<std::string> latviaAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> latviaSecondaryAddressFormats{"dz. ##", "- ##"};

const std::vector<std::string> latviaBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> latviaStreetSuffixes{"iela",  "ceļš", "prospekts", "bulvāris",
                                                    "gatve", "gāte", "laukums",   "dambis"};

const std::vector<std::string> latviaStreetFormats{"{streetName} {streetSuffix}"};

//
const std::vector<std::string> latviaCityFormats{"{cityName}"};

const CountryAddresses latviaAddresses{latviaZipCodeFormat,
                                       latviaAddressFormats,
                                       latviaSecondaryAddressFormats,
                                       latviaStreetFormats,
                                       {},
                                       latviaStreetNames,
                                       latviaStreetSuffixes,
                                       latviaBuildingNumberFormats,
                                       latviaCityFormats,
                                       {},
                                       latviaCities,
                                       {},
                                       latviaStates,
                                       {}};
}
