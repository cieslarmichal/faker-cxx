#pragma once

#include "../CountryAddresses.h"
#include "UkraineCities.h"
#include "UkraineStreetNames.h"
#include "UkraineStreetPrefixes.h"
#include "UkraineStates.h"

namespace faker
{
const std::string ukraineZipCodeFormat{"#####"};

const std::vector<std::string> ukraineAddressFormats{"{street} {buildingNumber}",
                                                     "{street} {buildingNumber} {secondaryAddress}"};

const std::vector<std::string> ukraineSecondaryAddressFormats{"кв. ###", "кв. ##", "кв. #"};

const std::vector<std::string> ukraineBuildingNumberFormats{"#", "##", "###"};

const std::vector<std::string> ukraineStreetFormats{"{streetPrefix} {firstName}", "{streetPrefix} {lastName}",
                                                    "{streetPrefix} {streetName}"};

const std::vector<std::string> ukraineCityFormats{"{cityName}"};

const CountryAddresses ukraineAddresses{ukraineZipCodeFormat,
                                        ukraineAddressFormats,
                                        ukraineSecondaryAddressFormats,
                                        ukraineStreetFormats,
                                        ukraineStreetPrefixes,
                                        ukraineStreetNames,
                                        {},
                                        ukraineBuildingNumberFormats,
                                        ukraineCityFormats,
                                        {},
                                        ukraineCities,
                                        {},
                                        ukraineStates,
                                        {}};
}
