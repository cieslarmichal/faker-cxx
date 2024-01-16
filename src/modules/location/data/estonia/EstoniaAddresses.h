#pragma once

#include "../CountryAddresses.h"
#include "EstoniaCities.h"
#include "EstoniaCounties.h"
#include "EstoniaStreetNames.h"
#include "EstoniaStreetSuffixes.h"

namespace faker {

const std::string estoniaZipCodeFormat{"#####"};

const std::vector<std::string> estoniaAddressFormats{"{street} {buildingNumber}"};

const std::vector<std::string> estoniaBuildingNumberFormats{"###", "##", "#"};

const std::vector<std::string> estoniaStreetFormats{"{streetName} {streetSuffix}"};

const std::vector<std::string> estoniaCityFormats{"{cityName}"};

const CountryAddresses estoniaAddresses{estoniaZipCodeFormat,
                                        estoniaAddressFormats,
                                        {},
                                        estoniaStreetFormats,
                                        {},
                                        {},
                                        estoniaStreetSuffixes,
                                        estoniaBuildingNumberFormats,
                                        estoniaCityFormats,
                                        {},
                                        estoniaCities,
                                        {},
                                        {},
                                        estoniaCounties};
}