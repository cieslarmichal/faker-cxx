#pragma once

#include "../CountryAddresses.h"
#include "BrazilCitySuffixes.h"
#include "BrazilStreetSuffixes.h"
#include "BrazilStates.h"

namespace faker
{
const std::string brazilZipCodeFormat{"#####-###"};

const std::vector<std::string> brazilAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> brazilSecondaryAddressFormats{"Apto. ###", "Sobrado ##", "Casa #", "Lote ##", "Quadra ##"};

const std::vector<std::string> brazilBuildingNumberFormats{"#####", "####", "###"};

const std::vector<std::string> brazilStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> brazilCityFormats{"{firstName} {citySuffix}", "{lastName} {citySuffix}"};

const CountryAddresses brazilAddresses{ brazilZipCodeFormat,
                                        brazilAddressFormats,
                                        brazilSecondaryAddressFormats,
                                        brazilStreetFormats,
                                        {},
                                        {},
                                        brazilStreetSuffixes,
                                        brazilBuildingNumberFormats,
                                        brazilCityFormats,
                                        {},
                                        {},
                                        brazilCitySuffixes,
                                        brazilStates,
                                        {}};
}