#pragma once

#include "../CountryAddresses.h"
#include "FinlandCities.h"
#include "FinlandStates.h"
#include "FinlandStreetSuffixes.h"

namespace faker {

const std::string finlandZipCodeFormat{"#####"};

const std::vector<std::string> finlandAddressFormats{"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> finlandSecondaryAddressFormats{"A", "B", "C", "A #", "A ##", "B #", "B ##", "C #", "C ##"};

const std::vector<std::string> finlandBuildingNumberFormats{"###", "##", "#"};

const std::vector<std::string> finlandStreetFormats{"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"};

const std::vector<std::string> finlandCityFormats{"{cityName}"};

const CountryAddresses finlandAddresses{finlandZipCodeFormat,
                                        finlandAddressFormats,
                                        finlandSecondaryAddressFormats,
                                        finlandStreetFormats,
                                        {},
                                        {},
                                        finlandStreetSuffixes,
                                        finlandBuildingNumberFormats,
                                        finlandCityFormats,
                                        {},
                                        finlandCities,
                                        {},
                                        finlandStates,
                                        {}};
}