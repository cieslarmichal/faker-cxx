#pragma once

#include "../CountryAddresses.h"
#include "GermanyCities.h"
#include "GermanyStreetNames.h"
#include "GermanyStates.h"

namespace faker
{
const std::string germanyZipCodeFormat{"#####"};

const std::vector<std::string> germanyAddressFormats{"{street} {buildingNumber}",
                                                    "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> germanySecondaryAddressFormats{"Apt. ###", "Zimmer ###", "# OG"};

const std::vector<std::string> germanyBuildingNumberFormats{"###", "##", "#", "##a", "##b", "##c"};

const std::vector<std::string> germanyStreetFormats{"{streetName}"};

const CountryAddresses germanyAddresses{germanyCities,
                                        germanyZipCodeFormat,
                                        germanyAddressFormats,
                                        germanySecondaryAddressFormats,
                                        germanyStreetFormats,
                                        {},
                                        germanyStreetNames,
                                        {},
                                        germanyBuildingNumberFormats,
                                        germanyStates,
                                        {}};
}