#pragma once

#include "../CountryAddresses.h"
#include "SerbiaCities.h"
#include "SerbiaStates.h"
#include "SerbiaStreetNames.h"

namespace faker
{
const std::string serbiaZipCodeFormat{"#####"};

const std::vector<std::string> serbiaAddressFormats{"{buildingNumber} {street}"};

const std::vector<std::string> serbiaSecondaryAddressFormats{"Sprat #", "Stan ##"};

const std::vector<std::string> serbiaBuildingNumberFormats{
    "#",
    "##",
    "###",
};

const std::vector<std::string> serbiaStreetFormats{"{streetName}"};

const std::vector<std::string> serbiaCityFormats{"{cityName}"};

const CountryAddresses serbiaAddresses{serbiaZipCodeFormat,
                                       serbiaAddressFormats,
                                       serbiaSecondaryAddressFormats,
                                       serbiaStreetFormats,
                                       {},
                                       serbiaStreetNames,
                                       {},
                                       serbiaBuildingNumberFormats,
                                       serbiaCityFormats,
                                       {},
                                       serbiaCities,
                                       {},
                                       serbiaStates,
                                       {}};
}
