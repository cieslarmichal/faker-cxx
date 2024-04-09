#pragma once

#include "../CountryAddresses.h"
#include "NepalCities.h"
#include "NepalStates.h"
#include "NepalStreetSuffixes.h"

namespace faker
{
const std::string nepalZipCodeFormat{"######"};

const std::vector<std::string> nepalAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> nepalSecondaryAddressFormats{"Apt. ###", "Flat ###"};

const std::vector<std::string> nepalBuildingNumberFormats{"#####", "####", "###"};

const std::vector<std::string> nepalStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> nepalCityFormats{"{cityName}"};

const CountryAddresses nepalAddresses{nepalZipCodeFormat,
                                      nepalAddressFormats,
                                      nepalSecondaryAddressFormats,
                                      nepalStreetFormats,
                                      {},
                                      {},
                                      nepalStreetSuffixes,
                                      nepalBuildingNumberFormats,
                                      nepalCityFormats,
                                      {},
                                      nepalCities,
                                      {},
                                      nepalStates,
                                      {}};
}
