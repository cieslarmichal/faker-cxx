#pragma once

#include "../CountryAddresses.h"
#include "SpainCities.h"
#include "SpainCounties.h"
#include "SpainStates.h"
#include "SpainStreetSuffixes.h"

namespace faker
{
const std::string spainZipCodeFormat{"#####"};

const std::vector<std::string> spainAddressFormats{"{street} {buildingNumber}",
                                                   "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> spainSecondaryAddressFormats{"Esc. ###", "Puerta ###"};

const std::vector<std::string> spainBuildingNumberFormats{"s/n.", "#", "##"};

const std::vector<std::string> spainStreetFormats{"{streetSuffix} {firstName}",
                                                  "{streetSuffix} {firstName} {lastName}"};

const std::vector<std::string> spainCityFormats{"{cityName}"};

const CountryAddresses spainAddresses{spainZipCodeFormat,
                                      spainAddressFormats,
                                      spainSecondaryAddressFormats,
                                      spainStreetFormats,
                                      {},
                                      {},
                                      spainStreetSuffixes,
                                      spainBuildingNumberFormats,
                                      spainCityFormats,
                                      {},
                                      spainCities,
                                      {},
                                      spainStates,
                                      spainCounties};
}