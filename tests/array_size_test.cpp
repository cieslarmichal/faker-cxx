#include "test_helpers.h"
#include <iostream>
#include <modules/location_data.h>

using namespace faker::location::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(australiaCities);
    PRINT_ARRAY_SIZE(australiaStates);
    PRINT_ARRAY_SIZE(australiaStreetSuffixes);
    PRINT_ARRAY_SIZE(australiaAddressFormats);
    PRINT_ARRAY_SIZE(australiaBuildingNumberFormats);
    PRINT_ARRAY_SIZE(australiaStreetFormats);
    PRINT_ARRAY_SIZE(australiaCityFormats);

    PRINT_ARRAY_SIZE(brazilCitySuffixes);
    PRINT_ARRAY_SIZE(brazilStates);
    PRINT_ARRAY_SIZE(brazilStreetSuffixes);
    PRINT_ARRAY_SIZE(brazilAddressFormats);
    PRINT_ARRAY_SIZE(brazilSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(brazilBuildingNumberFormats);
    PRINT_ARRAY_SIZE(brazilStreetFormats);
    PRINT_ARRAY_SIZE(brazilCityFormats);

    PRINT_ARRAY_SIZE(czechCities);
    PRINT_ARRAY_SIZE(czechStates);
    PRINT_ARRAY_SIZE(czechStreetNames);
    PRINT_ARRAY_SIZE(czechAddressFormats);
    PRINT_ARRAY_SIZE(czechSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(czechBuildingNumberFormats);
    PRINT_ARRAY_SIZE(czechStreetFormats);
    PRINT_ARRAY_SIZE(czechCityFormats);

    PRINT_ARRAY_SIZE(denmarkCities);
    PRINT_ARRAY_SIZE(denmarkStates);
    PRINT_ARRAY_SIZE(denmarkStreetNames);
    PRINT_ARRAY_SIZE(denmarkAddressFormats);
    PRINT_ARRAY_SIZE(denmarkSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(denmarkBuildingNumberFormats);
    PRINT_ARRAY_SIZE(denmarkStreetFormats);
    PRINT_ARRAY_SIZE(denmarkCityFormats);

    PRINT_ARRAY_SIZE(estoniaCities);
    PRINT_ARRAY_SIZE(estoniaCounties);
    PRINT_ARRAY_SIZE(estoniaStreetNames);
    PRINT_ARRAY_SIZE(estoniaStreetSuffixes);
    PRINT_ARRAY_SIZE(estoniaAddressFormats);
    PRINT_ARRAY_SIZE(estoniaBuildingNumberFormats);
    PRINT_ARRAY_SIZE(estoniaStreetFormats);
    PRINT_ARRAY_SIZE(estoniaCityFormats);

    PRINT_ARRAY_SIZE(finlandCities);
    PRINT_ARRAY_SIZE(finlandStates);
    PRINT_ARRAY_SIZE(finlandStreetSuffixes);
    PRINT_ARRAY_SIZE(finlandAddressFormats);
    PRINT_ARRAY_SIZE(finlandSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(finlandBuildingNumberFormats);
    PRINT_ARRAY_SIZE(finlandStreetFormats);
    PRINT_ARRAY_SIZE(finlandCityFormats);

    PRINT_ARRAY_SIZE(franceCities);
    PRINT_ARRAY_SIZE(franceStates);
    PRINT_ARRAY_SIZE(franceStreetPrefixes);
    PRINT_ARRAY_SIZE(franceStreetSuffixes);
    PRINT_ARRAY_SIZE(franceAddressFormats);
    PRINT_ARRAY_SIZE(franceBuildingNumberFormats);
    PRINT_ARRAY_SIZE(franceSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(franceStreetFormats);
    PRINT_ARRAY_SIZE(franceCityFormats);

    PRINT_ARRAY_SIZE(germanyCities);
    PRINT_ARRAY_SIZE(germanyStates);
    PRINT_ARRAY_SIZE(germanyStreetNames);
    PRINT_ARRAY_SIZE(germanyAddressFormats);
    PRINT_ARRAY_SIZE(germanySecondaryAddressFormats);
    PRINT_ARRAY_SIZE(germanyBuildingNumberFormats);
    PRINT_ARRAY_SIZE(germanyStreetFormats);
    PRINT_ARRAY_SIZE(germanyCityFormats);

    PRINT_ARRAY_SIZE(indiaCities);
    PRINT_ARRAY_SIZE(indiaStates);
    PRINT_ARRAY_SIZE(indiaStreetSuffixes);
    PRINT_ARRAY_SIZE(indiaAddressFormats);
    PRINT_ARRAY_SIZE(indiaSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(indiaBuildingNumberFormats);
    PRINT_ARRAY_SIZE(indiaStreetFormats);
    PRINT_ARRAY_SIZE(indiaCityFormats);

    PRINT_ARRAY_SIZE(italyCities);
    PRINT_ARRAY_SIZE(italyStates);
    PRINT_ARRAY_SIZE(italyStreetPrefixes);
    PRINT_ARRAY_SIZE(italyAddressFormats);
    PRINT_ARRAY_SIZE(italySecondaryAddressFormats);
    PRINT_ARRAY_SIZE(italyBuildingNumberFormats);
    PRINT_ARRAY_SIZE(italyStreetFormats);
    PRINT_ARRAY_SIZE(italyCityFormats);

    PRINT_ARRAY_SIZE(polandCities);
    PRINT_ARRAY_SIZE(polandStates);
    PRINT_ARRAY_SIZE(polandStreetNames);
    PRINT_ARRAY_SIZE(polandStreetPrefixes);
    PRINT_ARRAY_SIZE(polandAddressFormats);
    PRINT_ARRAY_SIZE(polandSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(polandBuildingNumberFormats);
    PRINT_ARRAY_SIZE(polandStreetFormats);
    PRINT_ARRAY_SIZE(polandCityFormats);

    PRINT_ARRAY_SIZE(russiaCities);
    PRINT_ARRAY_SIZE(russiaStates);
    PRINT_ARRAY_SIZE(russiaStreetNames);
    PRINT_ARRAY_SIZE(russiaStreetPrefixes);
    PRINT_ARRAY_SIZE(russiaAddressFormats);
    PRINT_ARRAY_SIZE(russiaSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(russiaBuildingNumberFormats);
    PRINT_ARRAY_SIZE(russiaStreetFormats);
    PRINT_ARRAY_SIZE(russiaCityFormats);

    PRINT_ARRAY_SIZE(spainCities);
    PRINT_ARRAY_SIZE(spainCounties);
    PRINT_ARRAY_SIZE(spainStates);
    PRINT_ARRAY_SIZE(spainStreetSuffixes);
    PRINT_ARRAY_SIZE(spainAddressFormats);
    PRINT_ARRAY_SIZE(spainSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(spainBuildingNumberFormats);
    PRINT_ARRAY_SIZE(spainStreetFormats);
    PRINT_ARRAY_SIZE(spainCityFormats);

    PRINT_ARRAY_SIZE(ukraineCities);
    PRINT_ARRAY_SIZE(ukraineStates);
    PRINT_ARRAY_SIZE(ukraineStreetNames);
    PRINT_ARRAY_SIZE(ukraineStreetPrefixes);
    PRINT_ARRAY_SIZE(ukraineAddressFormats);
    PRINT_ARRAY_SIZE(ukraineSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(ukraineBuildingNumberFormats);
    PRINT_ARRAY_SIZE(ukraineStreetFormats);
    PRINT_ARRAY_SIZE(ukraineCityFormats);

    PRINT_ARRAY_SIZE(usaCities);
    PRINT_ARRAY_SIZE(usaCounties);
    PRINT_ARRAY_SIZE(usaStates);
    PRINT_ARRAY_SIZE(usaStreetSuffixes);
    PRINT_ARRAY_SIZE(usaAddressFormats);
    PRINT_ARRAY_SIZE(usaSecondaryAddressFormats);
    PRINT_ARRAY_SIZE(usaBuildingNumberFormats);
    PRINT_ARRAY_SIZE(usaStreetFormats);
    PRINT_ARRAY_SIZE(usaCityFormats);
}
