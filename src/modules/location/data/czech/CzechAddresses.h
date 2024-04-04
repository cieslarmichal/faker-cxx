#pragma once

#include "../CountryAddresses.h"
#include "CzechCities.h"
#include "CzechStates.h"
#include "CzechStreetNames.h"

namespace faker
{
const std::string czechZipCodeFormat{"#####"};

const std::vector<std::string> czechAddressFormats{"{street} {buildingNumber}",
                                                   "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> czechSecondaryAddressFormats{"Apt. ###", "Suite ###"};

const std::vector<std::string> czechBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> czechStreetFormats{"{streetName}"};

const std::vector<std::string> czechCityFormats{"{cityName}"};

const CountryAddresses czechAddresses{czechZipCodeFormat,
                                      czechAddressFormats,
                                      czechSecondaryAddressFormats,
                                      czechStreetFormats,
                                      {},
                                      czechStreetNames,
                                      {},
                                      czechBuildingNumberFormats,
                                      czechCityFormats,
                                      {},
                                      czechCities,
                                      {},
                                      czechStates,
                                      {}};
}
