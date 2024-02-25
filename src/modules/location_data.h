#ifndef FAKER_MODULES_LOCATION_DATA_H
#define FAKER_MODULES_LOCATION_DATA_H

#include <array>
#include <string>
#include <vector>

namespace faker {
struct CountryAddresses {
    std::string_view zipCodeFormat;
    std::vector<std::string> addressFormats;
    std::vector<std::string> secondaryAddressFormats;
    std::vector<std::string> streetFormats;
    std::vector<std::string> streetPrefixes;
    std::vector<std::string> streetNames;
    std::vector<std::string> streetSuffixes;
    std::vector<std::string> buildingNumberFormats;
    std::vector<std::string> cityFormats;
    std::vector<std::string> cityPrefixes;
    std::vector<std::string> cities;
    std::vector<std::string> citySuffixes;
    std::vector<std::string> states;
    std::vector<std::string> counties;
};

extern const std::array<std::string_view, 246> allCountries;
extern const std::array<std::string_view, 249> countryCodes;
extern const std::array<std::string_view, 8> directions;
extern const std::array<std::string_view, 418> timeZones;

// Australia

extern const std::vector<std::string> australiaCities;
extern const std::vector<std::string> australiaStates;
extern const std::vector<std::string> australiaStreetSuffixes;
extern const std::string_view australiaZipCodeFormat;
extern const std::vector<std::string> australiaAddressFormats;
extern const std::vector<std::string> australiaBuildingNumberFormats;
extern const std::vector<std::string> australiaStreetFormats;
extern const std::vector<std::string> australiaCityFormats;
extern const CountryAddresses australiaAddresses;

// Brazil

extern const std::vector<std::string> brazilCitySuffixes;
extern const std::vector<std::string> brazilStates;
extern const std::vector<std::string> brazilStreetSuffixes;
extern const std::string_view brazilZipCodeFormat;
extern const std::vector<std::string> brazilAddressFormats;
extern const std::vector<std::string> brazilSecondaryAddressFormats;
extern const std::vector<std::string> brazilBuildingNumberFormats;
extern const std::vector<std::string> brazilStreetFormats;
extern const std::vector<std::string> brazilCityFormats;
extern const CountryAddresses brazilAddresses;

// Czech Republic

extern const std::vector<std::string> czechCities;
extern const std::vector<std::string> czechStates;
extern const std::vector<std::string> czechStreetNames;
extern const std::string_view czechZipCodeFormat;
extern const std::vector<std::string> czechAddressFormats;
extern const std::vector<std::string> czechSecondaryAddressFormats;
extern const std::vector<std::string> czechBuildingNumberFormats;
extern const std::vector<std::string> czechStreetFormats;
extern const std::vector<std::string> czechCityFormats;
extern const CountryAddresses czechAddresses;

// Denmark

extern const std::vector<std::string> denmarkCities;
extern const std::vector<std::string> denmarkStates;
extern const std::vector<std::string> denmarkStreetNames;
extern const std::string_view denmarkZipCodeFormat;
extern const std::vector<std::string> denmarkAddressFormats;
extern const std::vector<std::string> denmarkSecondaryAddressFormats;
extern const std::vector<std::string> denmarkBuildingNumberFormats;
extern const std::vector<std::string> denmarkStreetFormats;
extern const std::vector<std::string> denmarkCityFormats;
extern const CountryAddresses denmarkAddresses;

// Estonia

extern const std::vector<std::string> estoniaCities;
extern const std::vector<std::string> estoniaCounties;
extern const std::vector<std::string> estoniaStreetNames;
extern const std::vector<std::string> estoniaStreetSuffixes;
extern const std::string_view estoniaZipCodeFormat;
extern const std::vector<std::string> estoniaAddressFormats;
extern const std::vector<std::string> estoniaBuildingNumberFormats;
extern const std::vector<std::string> estoniaStreetFormats;
extern const std::vector<std::string> estoniaCityFormats;
extern const CountryAddresses estoniaAddresses;

// Finland

extern const std::vector<std::string> finlandCities;
extern const std::vector<std::string> finlandStates;
extern const std::vector<std::string> finlandStreetSuffixes;
extern const std::string_view finlandZipCodeFormat;
extern const std::vector<std::string> finlandAddressFormats;
extern const std::vector<std::string> finlandSecondaryAddressFormats;
extern const std::vector<std::string> finlandBuildingNumberFormats;
extern const std::vector<std::string> finlandStreetFormats;
extern const std::vector<std::string> finlandCityFormats;
extern const CountryAddresses finlandAddresses;

// France

extern const std::vector<std::string> franceCities;
extern const std::vector<std::string> franceStates;
extern const std::vector<std::string> franceStreetPrefixes;
extern const std::vector<std::string> franceStreetSuffixes;
extern const std::string_view franceZipCodeFormat;
extern const std::vector<std::string> franceAddressFormats;
extern const std::vector<std::string> franceBuildingNumberFormats;
extern const std::vector<std::string> franceSecondaryAddressFormats;
extern const std::vector<std::string> franceStreetFormats;
extern const std::vector<std::string> franceCityFormats;
extern const CountryAddresses franceAddresses;

// Germany

extern const std::vector<std::string> germanyCities;
extern const std::vector<std::string> germanyStates;
extern const std::vector<std::string> germanyStreetNames;
extern const std::string_view germanyZipCodeFormat;
extern const std::vector<std::string> germanyAddressFormats;
extern const std::vector<std::string> germanySecondaryAddressFormats;
extern const std::vector<std::string> germanyBuildingNumberFormats;
extern const std::vector<std::string> germanyStreetFormats;
extern const std::vector<std::string> germanyCityFormats;
extern const CountryAddresses germanyAddresses;

// India

extern const std::vector<std::string> indiaCities;
extern const std::vector<std::string> indiaStates;
extern const std::vector<std::string> indiaStreetSuffixes;
extern const std::string_view indiaZipCodeFormat;
extern const std::vector<std::string> indiaAddressFormats;
extern const std::vector<std::string> indiaSecondaryAddressFormats;
extern const std::vector<std::string> indiaBuildingNumberFormats;
extern const std::vector<std::string> indiaStreetFormats;
extern const std::vector<std::string> indiaCityFormats;
extern const CountryAddresses indiaAddresses;

// Italy

extern const std::vector<std::string> italyCities;
extern const std::vector<std::string> italyStates;
extern const std::vector<std::string> italyStreetPrefixes;
extern const std::string_view italyZipCodeFormat;
extern const std::vector<std::string> italyAddressFormats;
extern const std::vector<std::string> italySecondaryAddressFormats;
extern const std::vector<std::string> italyBuildingNumberFormats;
extern const std::vector<std::string> italyStreetFormats;
extern const std::vector<std::string> italyCityFormats;
extern const CountryAddresses italyAddresses;

// Poland

extern const std::vector<std::string> polandCities;
extern const std::vector<std::string> polandStates;
extern const std::vector<std::string> polandStreetNames;
extern const std::vector<std::string> polandStreetPrefixes;
extern const std::string_view polandZipCodeFormat;
extern const std::vector<std::string> polandAddressFormats;
extern const std::vector<std::string> polandSecondaryAddressFormats;
extern const std::vector<std::string> polandBuildingNumberFormats;
extern const std::vector<std::string> polandStreetFormats;
extern const std::vector<std::string> polandCityFormats;
extern const CountryAddresses polandAddresses;

// Russia

extern const std::vector<std::string> russiaCities;
extern const std::vector<std::string> russiaStates;
extern const std::vector<std::string> russiaStreetNames;
extern const std::vector<std::string> russiaStreetPrefixes;
extern const std::string_view russiaZipCodeFormat;
extern const std::vector<std::string> russiaAddressFormats;
extern const std::vector<std::string> russiaSecondaryAddressFormats;
extern const std::vector<std::string> russiaBuildingNumberFormats;
extern const std::vector<std::string> russiaStreetFormats;
extern const std::vector<std::string> russiaCityFormats;
extern const CountryAddresses russiaAddresses;

// Spain

extern const std::vector<std::string> spainCities;
extern const std::vector<std::string> spainCounties;
extern const std::vector<std::string> spainStates;
extern const std::vector<std::string> spainStreetSuffixes;
extern const std::string_view spainZipCodeFormat;
extern const std::vector<std::string> spainAddressFormats;
extern const std::vector<std::string> spainSecondaryAddressFormats;
extern const std::vector<std::string> spainBuildingNumberFormats;
extern const std::vector<std::string> spainStreetFormats;
extern const std::vector<std::string> spainCityFormats;
extern const CountryAddresses spainAddresses;

// Ukraine

extern const std::vector<std::string> ukraineCities;
extern const std::vector<std::string> ukraineStates;
extern const std::vector<std::string> ukraineStreetNames;
extern const std::vector<std::string> ukraineStreetPrefixes;
extern const std::string_view ukraineZipCodeFormat;
extern const std::vector<std::string> ukraineAddressFormats;
extern const std::vector<std::string> ukraineSecondaryAddressFormats;
extern const std::vector<std::string> ukraineBuildingNumberFormats;
extern const std::vector<std::string> ukraineStreetFormats;
extern const std::vector<std::string> ukraineCityFormats;
extern const CountryAddresses ukraineAddresses;

// USA

extern const std::vector<std::string> usaCities;
extern const std::vector<std::string> usaCounties;
extern const std::vector<std::string> usaStates;
extern const std::vector<std::string> usaStreetSuffixes;
extern const std::string_view usaZipCodeFormat;
extern const std::vector<std::string> usaAddressFormats;
extern const std::vector<std::string> usaSecondaryAddressFormats;
extern const std::vector<std::string> usaBuildingNumberFormats;
extern const std::vector<std::string> usaStreetFormats;
extern const std::vector<std::string> usaCityFormats;
extern const CountryAddresses usaAddresses;

}

#endif