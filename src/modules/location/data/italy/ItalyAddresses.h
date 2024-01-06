#pragma once

#include "../CountryAddresses.h"
#include "ItalyCities.h"
#include "ItalyStreetSuffixes.h"

namespace faker
{
const std::string italyZipCodeFormat{"#####"};

const std::vector<std::string> italyAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> italySecondaryAddressFormats{"Appartamento ##", "Piano #"};

const std::vector<std::string> italyBuildingNumberFormats{"###", "##", "#"};

const std::vector<std::string> italyStreetFormats{"{streetSuffix} {firstName}", "{streetSuffix} {lastName}"};

const CountryAddresses italyAddresses{italyCities,
                                        italyZipCodeFormat,
                                        italyAddressFormats,
                                        italySecondaryAddressFormats,
                                        italyStreetFormats,
                                        {},
                                        {},
                                        italyStreetSuffixes,
                                        italyBuildingNumberFormats};
}