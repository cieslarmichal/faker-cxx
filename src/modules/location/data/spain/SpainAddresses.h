#pragma once

#include "../CountryAddresses.h"
#include "SpainCities.h"
#include "SpainStreetSuffixes.h"
#include "SpainStates.h"
#include "SpainCounties.h"

namespace faker
{
const std::string spainZipCodeFormat{"#####"};

const std::vector<std::string> spainAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> spainSecondaryAddressFormats{"Esc. ###", "Puerta ###"};

const std::vector<std::string> spainBuildingNumberFormats{"s/n.", "#", "##"};

const std::vector<std::string> spainStreetFormats{"{streetSuffix} {firstName}", "{streetSuffix} {firstName} {lastName}"};

const CountryAddresses spainAddresses{spainCities,
                                      spainZipCodeFormat,
                                      spainAddressFormats,
                                      spainSecondaryAddressFormats,
                                      spainStreetFormats,
                                      {},
                                      {},
                                      spainStreetSuffixes,
                                      spainBuildingNumberFormats,
                                      spainStates,
                                      spainCounties};
}