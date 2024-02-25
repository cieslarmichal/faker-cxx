#ifndef FAKER_MODULES_LOCATION_DATA_H
#define FAKER_MODULES_LOCATION_DATA_H

#include <array>
#include <string>
#include <vector>

namespace faker::location::data {
struct CountryAddresses {
    std::string_view zipCodeFormat;
    std::vector<std::string_view> addressFormats;
    std::vector<std::string_view> secondaryAddressFormats;
    std::vector<std::string_view> streetFormats;
    std::vector<std::string_view> streetPrefixes;
    std::vector<std::string_view> streetNames;
    std::vector<std::string_view> streetSuffixes;
    std::vector<std::string_view> buildingNumberFormats;
    std::vector<std::string_view> cityFormats;
    std::vector<std::string_view> cityPrefixes;
    std::vector<std::string_view> cities;
    std::vector<std::string_view> citySuffixes;
    std::vector<std::string_view> states;
    std::vector<std::string_view> counties;
};

extern const std::array<std::string_view, 246> allCountries;
extern const std::array<std::string_view, 249> countryCodes;
extern const std::array<std::string_view, 8> directions;
extern const std::array<std::string_view, 418> timeZones;

// Australia

extern const std::vector<std::string_view> australiaCities;
extern const std::vector<std::string_view> australiaStates;
extern const std::vector<std::string_view> australiaStreetSuffixes;
extern const std::string_view australiaZipCodeFormat;
extern const std::vector<std::string_view> australiaAddressFormats;
extern const std::vector<std::string_view> australiaBuildingNumberFormats;
extern const std::vector<std::string_view> australiaStreetFormats;
extern const std::vector<std::string_view> australiaCityFormats;
extern const CountryAddresses australiaAddresses;

// Brazil

extern const std::vector<std::string_view> brazilCitySuffixes;
extern const std::vector<std::string_view> brazilStates;
extern const std::vector<std::string_view> brazilStreetSuffixes;
extern const std::string_view brazilZipCodeFormat;
extern const std::vector<std::string_view> brazilAddressFormats;
extern const std::vector<std::string_view> brazilSecondaryAddressFormats;
extern const std::vector<std::string_view> brazilBuildingNumberFormats;
extern const std::vector<std::string_view> brazilStreetFormats;
extern const std::vector<std::string_view> brazilCityFormats;
extern const CountryAddresses brazilAddresses;

// Czech Republic

extern const std::vector<std::string_view> czechCities;
extern const std::vector<std::string_view> czechStates;
extern const std::vector<std::string_view> czechStreetNames;
extern const std::string_view czechZipCodeFormat;
extern const std::vector<std::string_view> czechAddressFormats;
extern const std::vector<std::string_view> czechSecondaryAddressFormats;
extern const std::vector<std::string_view> czechBuildingNumberFormats;
extern const std::vector<std::string_view> czechStreetFormats;
extern const std::vector<std::string_view> czechCityFormats;
extern const CountryAddresses czechAddresses;

// Denmark

extern const std::vector<std::string_view> denmarkCities;
extern const std::vector<std::string_view> denmarkStates;
extern const std::vector<std::string_view> denmarkStreetNames;
extern const std::string_view denmarkZipCodeFormat;
extern const std::vector<std::string_view> denmarkAddressFormats;
extern const std::vector<std::string_view> denmarkSecondaryAddressFormats;
extern const std::vector<std::string_view> denmarkBuildingNumberFormats;
extern const std::vector<std::string_view> denmarkStreetFormats;
extern const std::vector<std::string_view> denmarkCityFormats;
extern const CountryAddresses denmarkAddresses;

// Estonia

extern const std::vector<std::string_view> estoniaCities;
extern const std::vector<std::string_view> estoniaCounties;
extern const std::vector<std::string_view> estoniaStreetNames;
extern const std::vector<std::string_view> estoniaStreetSuffixes;
extern const std::string_view estoniaZipCodeFormat;
extern const std::vector<std::string_view> estoniaAddressFormats;
extern const std::vector<std::string_view> estoniaBuildingNumberFormats;
extern const std::vector<std::string_view> estoniaStreetFormats;
extern const std::vector<std::string_view> estoniaCityFormats;
extern const CountryAddresses estoniaAddresses;

// Finland

extern const std::vector<std::string_view> finlandCities;
extern const std::vector<std::string_view> finlandStates;
extern const std::vector<std::string_view> finlandStreetSuffixes;
extern const std::string_view finlandZipCodeFormat;
extern const std::vector<std::string_view> finlandAddressFormats;
extern const std::vector<std::string_view> finlandSecondaryAddressFormats;
extern const std::vector<std::string_view> finlandBuildingNumberFormats;
extern const std::vector<std::string_view> finlandStreetFormats;
extern const std::vector<std::string_view> finlandCityFormats;
extern const CountryAddresses finlandAddresses;

// France

extern const std::vector<std::string_view> franceCities;
extern const std::vector<std::string_view> franceStates;
extern const std::vector<std::string_view> franceStreetPrefixes;
extern const std::vector<std::string_view> franceStreetSuffixes;
extern const std::string_view franceZipCodeFormat;
extern const std::vector<std::string_view> franceAddressFormats;
extern const std::vector<std::string_view> franceBuildingNumberFormats;
extern const std::vector<std::string_view> franceSecondaryAddressFormats;
extern const std::vector<std::string_view> franceStreetFormats;
extern const std::vector<std::string_view> franceCityFormats;
extern const CountryAddresses franceAddresses;

// Germany

extern const std::vector<std::string_view> germanyCities;
extern const std::vector<std::string_view> germanyStates;
extern const std::vector<std::string_view> germanyStreetNames;
extern const std::string_view germanyZipCodeFormat;
extern const std::vector<std::string_view> germanyAddressFormats;
extern const std::vector<std::string_view> germanySecondaryAddressFormats;
extern const std::vector<std::string_view> germanyBuildingNumberFormats;
extern const std::vector<std::string_view> germanyStreetFormats;
extern const std::vector<std::string_view> germanyCityFormats;
extern const CountryAddresses germanyAddresses;

// India

extern const std::vector<std::string_view> indiaCities;
extern const std::vector<std::string_view> indiaStates;
extern const std::vector<std::string_view> indiaStreetSuffixes;
extern const std::string_view indiaZipCodeFormat;
extern const std::vector<std::string_view> indiaAddressFormats;
extern const std::vector<std::string_view> indiaSecondaryAddressFormats;
extern const std::vector<std::string_view> indiaBuildingNumberFormats;
extern const std::vector<std::string_view> indiaStreetFormats;
extern const std::vector<std::string_view> indiaCityFormats;
extern const CountryAddresses indiaAddresses;

// Italy

extern const std::vector<std::string_view> italyCities;
extern const std::vector<std::string_view> italyStates;
extern const std::vector<std::string_view> italyStreetPrefixes;
extern const std::string_view italyZipCodeFormat;
extern const std::vector<std::string_view> italyAddressFormats;
extern const std::vector<std::string_view> italySecondaryAddressFormats;
extern const std::vector<std::string_view> italyBuildingNumberFormats;
extern const std::vector<std::string_view> italyStreetFormats;
extern const std::vector<std::string_view> italyCityFormats;
extern const CountryAddresses italyAddresses;

// Poland

extern const std::vector<std::string_view> polandCities;
extern const std::vector<std::string_view> polandStates;
extern const std::vector<std::string_view> polandStreetNames;
extern const std::vector<std::string_view> polandStreetPrefixes;
extern const std::string_view polandZipCodeFormat;
extern const std::vector<std::string_view> polandAddressFormats;
extern const std::vector<std::string_view> polandSecondaryAddressFormats;
extern const std::vector<std::string_view> polandBuildingNumberFormats;
extern const std::vector<std::string_view> polandStreetFormats;
extern const std::vector<std::string_view> polandCityFormats;
extern const CountryAddresses polandAddresses;

// Russia

extern const std::vector<std::string_view> russiaCities;
extern const std::vector<std::string_view> russiaStates;
extern const std::vector<std::string_view> russiaStreetNames;
extern const std::vector<std::string_view> russiaStreetPrefixes;
extern const std::string_view russiaZipCodeFormat;
extern const std::vector<std::string_view> russiaAddressFormats;
extern const std::vector<std::string_view> russiaSecondaryAddressFormats;
extern const std::vector<std::string_view> russiaBuildingNumberFormats;
extern const std::vector<std::string_view> russiaStreetFormats;
extern const std::vector<std::string_view> russiaCityFormats;
extern const CountryAddresses russiaAddresses;

// Spain

extern const std::vector<std::string_view> spainCities;
extern const std::vector<std::string_view> spainCounties;
extern const std::vector<std::string_view> spainStates;
extern const std::vector<std::string_view> spainStreetSuffixes;
extern const std::string_view spainZipCodeFormat;
extern const std::vector<std::string_view> spainAddressFormats;
extern const std::vector<std::string_view> spainSecondaryAddressFormats;
extern const std::vector<std::string_view> spainBuildingNumberFormats;
extern const std::vector<std::string_view> spainStreetFormats;
extern const std::vector<std::string_view> spainCityFormats;
extern const CountryAddresses spainAddresses;

// Ukraine

extern const std::vector<std::string_view> ukraineCities;
extern const std::vector<std::string_view> ukraineStates;
extern const std::vector<std::string_view> ukraineStreetNames;
extern const std::vector<std::string_view> ukraineStreetPrefixes;
extern const std::string_view ukraineZipCodeFormat;
extern const std::vector<std::string_view> ukraineAddressFormats;
extern const std::vector<std::string_view> ukraineSecondaryAddressFormats;
extern const std::vector<std::string_view> ukraineBuildingNumberFormats;
extern const std::vector<std::string_view> ukraineStreetFormats;
extern const std::vector<std::string_view> ukraineCityFormats;
extern const CountryAddresses ukraineAddresses;

// USA

extern const std::vector<std::string_view> usaCities;
extern const std::vector<std::string_view> usaCounties;
extern const std::vector<std::string_view> usaStates;
extern const std::vector<std::string_view> usaStreetSuffixes;
extern const std::string_view usaZipCodeFormat;
extern const std::vector<std::string_view> usaAddressFormats;
extern const std::vector<std::string_view> usaSecondaryAddressFormats;
extern const std::vector<std::string_view> usaBuildingNumberFormats;
extern const std::vector<std::string_view> usaStreetFormats;
extern const std::vector<std::string_view> usaCityFormats;
extern const CountryAddresses usaAddresses;

}

#endif