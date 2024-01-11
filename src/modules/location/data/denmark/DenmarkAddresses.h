#pragma once

#include "../CountryAddresses.h"
#include "DenmarkCities.h"
#include "DenmarkStates.h"
#include "DenmarkStreetNames.h"

namespace faker {
    const std::string denmarkZipCodeFormat{"####"};

    const std::vector<std::string> denmarkAddressFormats{"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"};

    const std::vector<std::string> denmarkSecondaryAddressFormats{"#. tv", "#. th"};

    const std::vector<std::string> denmarkBuildingNumberFormats{"#", "##", "###", "##A", "##B"};

    const std::vector<std::string> denmarkStreetFormats{"{streetName}"};

    const CountryAddresses denmarkAddresses{denmarkCities,
                                          denmarkZipCodeFormat,
                                          denmarkAddressFormats,
                                          denmarkSecondaryAddressFormats,
                                          denmarkStreetFormats,
                                          {},
                                          denmarkStreetNames,
                                          {},
                                          denmarkBuildingNumberFormats,
                                          denmarkStates};
}