#pragma once

#include "../CountryAddresses.h"
#include "IndiaCities.h"
#include "IndiaStates.h"
#include "IndiaStreetSuffixes.h"

namespace faker
{
const std::string indiaZipCodeFormat{"######"};

const std::vector<std::string> indiaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> indiaSecondaryAddressFormats{"Apt. ###", "Flat ###"};

const std::vector<std::string> indiaBuildingNumberFormats{"#####", "####", "###"};

const std::vector<std::string> indiaStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> indiaCityFormats{"{cityName}"};

const CountryAddresses indiaAddresses{indiaZipCodeFormat,
                                      indiaAddressFormats,
                                      indiaSecondaryAddressFormats,
                                      indiaStreetFormats,
                                      {},
                                      {},
                                      indiaStreetSuffixes,
                                      indiaBuildingNumberFormats,
                                      indiaCityFormats,
                                      {},
                                      indiaCities,
                                      {},
                                      indiaStates,
                                      {}};
}
