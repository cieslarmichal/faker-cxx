#pragma once

#include "../CountryAddresses.h"
#include "RussiaCities.h"
#include "RussiaStates.h"
#include "RussiaStreetNames.h"
#include "RussiaStreetPrefixes.h"

namespace faker
{
const std::string russiaZipCodeFormat{"######"};

const std::vector<std::string> russiaAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> russiaSecondaryAddressFormats{"кв. ###", "кв. ##", "кв. #"};

const std::vector<std::string> russiaBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> russiaStreetFormats{"{streetPrefix} {firstName}", "{streetPrefix} {lastName}",
                                                   "{streetPrefix} {streetName}"};

const std::vector<std::string> russiaCityFormats{"{cityName}"};

const CountryAddresses russiaAddresses{russiaZipCodeFormat,
                                       russiaAddressFormats,
                                       russiaSecondaryAddressFormats,
                                       russiaStreetFormats,
                                       russiaStreetPrefixes,
                                       russiaStreetNames,
                                       {},
                                       russiaBuildingNumberFormats,
                                       russiaCityFormats,
                                       {},
                                       russiaCities,
                                       {},
                                       russiaStates,
                                       {}};
}
