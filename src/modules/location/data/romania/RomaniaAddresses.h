#pragma once

#include "../CountryAddresses.h"
#include "RomaniaCities.h"
#include "RomaniaStates.h"
#include "RomaniaStreetNames.h"
#include "RomaniaStreetPrefixes.h"

namespace faker
{
const std::string romaniaZipCodeFormat{"######"};

const std::vector<std::string> romaniaAddressFormats{"{street} {buildingNumber}",
                                                     "{street} {buildingNumber} {buildingBlock}",
                                                     "{street} {buildingNumber}/{apartmentNumber}"};

const std::vector<std::string> romaniaBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> romaniaStreetFormats{"{streetPrefix} {streetName}"};

const std::vector<std::string> romaniaCityFormats{"{cityName}"};

const std::vector<std::string> romaniaSecondaryAddressFormats{"Scara ###", "Apartament ###", "Etaj ###", "Bloc ###"};

const CountryAddresses romaniaAddresses{romaniaZipCodeFormat,
                                        romaniaAddressFormats,
                                        romaniaSecondaryAddressFormats,
                                        romaniaStreetFormats,
                                        romaniaStreetPrefixes,
                                        romaniaStreetNames,
                                        {},
                                        romaniaBuildingNumberFormats,
                                        romaniaCityFormats,
                                        {},
                                        romaniaCities,
                                        {},
                                        romaniaStates,
                                        {}};
}
