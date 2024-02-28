#ifndef FAKER_MODULES_LOCATION_DATA_H
#define FAKER_MODULES_LOCATION_DATA_H

#include <array>
#include <string_view>
#include <tcb/span.hpp>

namespace faker::location::data {
struct CountryAddresses {
    std::string_view zipCodeFormat;
    tcb::span<const std::string_view> addressFormats;
    tcb::span<const std::string_view> secondaryAddressFormats;
    tcb::span<const std::string_view> streetFormats;
    tcb::span<const std::string_view> streetPrefixes;
    tcb::span<const std::string_view> streetNames;
    tcb::span<const std::string_view> streetSuffixes;
    tcb::span<const std::string_view> buildingNumberFormats;
    tcb::span<const std::string_view> cityFormats;
    tcb::span<const std::string_view> cityPrefixes;
    tcb::span<const std::string_view> cities;
    tcb::span<const std::string_view> citySuffixes;
    tcb::span<const std::string_view> states;
    tcb::span<const std::string_view> counties;
};

extern const std::array<std::string_view, 246> allCountries;
extern const std::array<std::string_view, 249> countryCodes;
extern const std::array<std::string_view, 8> directions;
extern const std::array<std::string_view, 418> timeZones;

// Australia

extern const std::array<std::string_view, 323> australiaCities;
extern const std::array<std::string_view, 8> australiaStates;
extern const std::array<std::string_view, 37> australiaStreetSuffixes;
extern const std::array<std::string_view, 1> australiaAddressFormats;
extern const std::array<std::string_view, 3> australiaBuildingNumberFormats;
extern const std::array<std::string_view, 2> australiaStreetFormats;
extern const std::array<std::string_view, 1> australiaCityFormats;
extern const std::string_view australiaZipCodeFormat;
extern const CountryAddresses australiaAddresses;

// Brazil

extern const std::array<std::string_view, 4> brazilCitySuffixes;
extern const std::array<std::string_view, 27> brazilStates;
extern const std::array<std::string_view, 6> brazilStreetSuffixes;
extern const std::array<std::string_view, 2> brazilAddressFormats;
extern const std::array<std::string_view, 5> brazilSecondaryAddressFormats;
extern const std::array<std::string_view, 3> brazilBuildingNumberFormats;
extern const std::array<std::string_view, 2> brazilStreetFormats;
extern const std::array<std::string_view, 2> brazilCityFormats;
extern const std::string_view brazilZipCodeFormat;
extern const CountryAddresses brazilAddresses;

// Czech Republic

extern const std::array<std::string_view, 602> czechCities;
extern const std::array<std::string_view, 14> czechStates;
extern const std::array<std::string_view, 7526> czechStreetNames;
extern const std::array<std::string_view, 2> czechAddressFormats;
extern const std::array<std::string_view, 2> czechSecondaryAddressFormats;
extern const std::array<std::string_view, 3> czechBuildingNumberFormats;
extern const std::array<std::string_view, 1> czechStreetFormats;
extern const std::array<std::string_view, 1> czechCityFormats;
extern const std::string_view czechZipCodeFormat;
extern const CountryAddresses czechAddresses;

// Denmark

extern const std::array<std::string_view, 221> denmarkCities;
extern const std::array<std::string_view, 5> denmarkStates;
extern const std::array<std::string_view, 158> denmarkStreetNames;
extern const std::array<std::string_view, 2> denmarkAddressFormats;
extern const std::array<std::string_view, 2> denmarkSecondaryAddressFormats;
extern const std::array<std::string_view, 5> denmarkBuildingNumberFormats;
extern const std::array<std::string_view, 1> denmarkStreetFormats;
extern const std::array<std::string_view, 1> denmarkCityFormats;
extern const std::string_view denmarkZipCodeFormat;
extern const CountryAddresses denmarkAddresses;

// Estonia

extern const std::array<std::string_view, 5> estoniaCities;
extern const std::array<std::string_view, 15> estoniaCounties;
extern const std::array<std::string_view, 31> estoniaStreetNames;
extern const std::array<std::string_view, 7> estoniaStreetSuffixes;
extern const std::array<std::string_view, 1> estoniaAddressFormats;
extern const std::array<std::string_view, 3> estoniaBuildingNumberFormats;
extern const std::array<std::string_view, 1> estoniaStreetFormats;
extern const std::array<std::string_view, 1> estoniaCityFormats;
extern const std::string_view estoniaZipCodeFormat;
extern const CountryAddresses estoniaAddresses;

// Finland

extern const std::array<std::string_view, 20> finlandCities;
extern const std::array<std::string_view, 19> finlandStates;
extern const std::array<std::string_view, 11> finlandStreetSuffixes;
extern const std::array<std::string_view, 2> finlandAddressFormats;
extern const std::array<std::string_view, 9> finlandSecondaryAddressFormats;
extern const std::array<std::string_view, 3> finlandBuildingNumberFormats;
extern const std::array<std::string_view, 2> finlandStreetFormats;
extern const std::array<std::string_view, 1> finlandCityFormats;
extern const std::string_view finlandZipCodeFormat;
extern const CountryAddresses finlandAddresses;

// France

extern const std::array<std::string_view, 1000> franceCities;
extern const std::array<std::string_view, 22> franceStates;
extern const std::array<std::string_view, 11> franceStreetPrefixes;
extern const std::array<std::string_view, 66> franceStreetSuffixes;
extern const std::array<std::string_view, 1> franceAddressFormats;
extern const std::array<std::string_view, 4> franceBuildingNumberFormats;
extern const std::array<std::string_view, 2> franceSecondaryAddressFormats;
extern const std::array<std::string_view, 1> franceStreetFormats;
extern const std::array<std::string_view, 1> franceCityFormats;
extern const std::string_view franceZipCodeFormat;
extern const CountryAddresses franceAddresses;

// Germany

extern const std::array<std::string_view, 200> germanyCities;
extern const std::array<std::string_view, 16> germanyStates;
extern const std::array<std::string_view, 1031> germanyStreetNames;
extern const std::array<std::string_view, 2> germanyAddressFormats;
extern const std::array<std::string_view, 3> germanySecondaryAddressFormats;
extern const std::array<std::string_view, 6> germanyBuildingNumberFormats;
extern const std::array<std::string_view, 1> germanyStreetFormats;
extern const std::array<std::string_view, 1> germanyCityFormats;
extern const std::string_view germanyZipCodeFormat;
extern const CountryAddresses germanyAddresses;

// India

extern const std::array<std::string_view, 1198> indiaCities;
extern const std::array<std::string_view, 36> indiaStates;
extern const std::array<std::string_view, 35> indiaStreetSuffixes;
extern const std::array<std::string_view, 1> indiaAddressFormats;
extern const std::array<std::string_view, 2> indiaSecondaryAddressFormats;
extern const std::array<std::string_view, 3> indiaBuildingNumberFormats;
extern const std::array<std::string_view, 2> indiaStreetFormats;
extern const std::array<std::string_view, 1> indiaCityFormats;
extern const std::string_view indiaZipCodeFormat;
extern const CountryAddresses indiaAddresses;

// Italy

extern const std::array<std::string_view, 979> italyCities;
extern const std::array<std::string_view, 110> italyStates;
extern const std::array<std::string_view, 7> italyStreetPrefixes;
extern const std::array<std::string_view, 2> italyAddressFormats;
extern const std::array<std::string_view, 2> italySecondaryAddressFormats;
extern const std::array<std::string_view, 3> italyBuildingNumberFormats;
extern const std::array<std::string_view, 2> italyStreetFormats;
extern const std::array<std::string_view, 1> italyCityFormats;
extern const std::string_view italyZipCodeFormat;
extern const CountryAddresses italyAddresses;

// Poland

extern const std::array<std::string_view, 978> polandCities;
extern const std::array<std::string_view, 16> polandStates;
extern const std::array<std::string_view, 5355> polandStreetNames;
extern const std::array<std::string_view, 6> polandStreetPrefixes;
extern const std::array<std::string_view, 3> polandAddressFormats;
extern const std::array<std::string_view, 3> polandSecondaryAddressFormats;
extern const std::array<std::string_view, 3> polandBuildingNumberFormats;
extern const std::array<std::string_view, 1> polandStreetFormats;
extern const std::array<std::string_view, 1> polandCityFormats;
extern const std::string_view polandZipCodeFormat;
extern const CountryAddresses polandAddresses;

// Russia

extern const std::array<std::string_view, 322> russiaCities;
extern const std::array<std::string_view, 84> russiaStates;
extern const std::array<std::string_view, 297> russiaStreetNames;
extern const std::array<std::string_view, 12> russiaStreetPrefixes;
extern const std::array<std::string_view, 2> russiaAddressFormats;
extern const std::array<std::string_view, 3> russiaSecondaryAddressFormats;
extern const std::array<std::string_view, 3> russiaBuildingNumberFormats;
extern const std::array<std::string_view, 3> russiaStreetFormats;
extern const std::array<std::string_view, 1> russiaCityFormats;
extern const std::string_view russiaZipCodeFormat;
extern const CountryAddresses russiaAddresses;

// Spain

extern const std::array<std::string_view, 130> spainCities;
extern const std::array<std::string_view, 50> spainCounties;
extern const std::array<std::string_view, 17> spainStates;
extern const std::array<std::string_view, 70> spainStreetSuffixes;
extern const std::array<std::string_view, 2> spainAddressFormats;
extern const std::array<std::string_view, 2> spainSecondaryAddressFormats;
extern const std::array<std::string_view, 3> spainBuildingNumberFormats;
extern const std::array<std::string_view, 2> spainStreetFormats;
extern const std::array<std::string_view, 1> spainCityFormats;
extern const std::string_view spainZipCodeFormat;
extern const CountryAddresses spainAddresses;

// Ukraine

extern const std::array<std::string_view, 480> ukraineCities;
extern const std::array<std::string_view, 27> ukraineStates;
extern const std::array<std::string_view, 61> ukraineStreetNames;
extern const std::array<std::string_view, 10> ukraineStreetPrefixes;
extern const std::array<std::string_view, 2> ukraineAddressFormats;
extern const std::array<std::string_view, 3> ukraineSecondaryAddressFormats;
extern const std::array<std::string_view, 3> ukraineBuildingNumberFormats;
extern const std::array<std::string_view, 3> ukraineStreetFormats;
extern const std::array<std::string_view, 1> ukraineCityFormats;
extern const std::string_view ukraineZipCodeFormat;
extern const CountryAddresses ukraineAddresses;

// USA

extern const std::array<std::string_view, 923> usaCities;
extern const std::array<std::string_view, 36> usaCounties;
extern const std::array<std::string_view, 50> usaStates;
extern const std::array<std::string_view, 195> usaStreetSuffixes;
extern const std::array<std::string_view, 1> usaAddressFormats;
extern const std::array<std::string_view, 2> usaSecondaryAddressFormats;
extern const std::array<std::string_view, 3> usaBuildingNumberFormats;
extern const std::array<std::string_view, 2> usaStreetFormats;
extern const std::array<std::string_view, 1> usaCityFormats;
extern const std::string_view usaZipCodeFormat;
extern const CountryAddresses usaAddresses;

}

#endif