#include "faker-cxx/Location.h"

#include <map>

#include "../../common/FormatHelper.h"
#include "../../common/mappers/precisionMapper/PrecisionMapper.h"
#include "data/Countries.h"
#include "data/Directions.h"
#include "data/france/FranceAddresses.h"
#include "data/poland/PolandAddresses.h"
#include "data/russia/RussiaAddresses.h"
#include "data/States.h"
#include "data/TimeZones.h"
#include "data/usa/UsaAddresses.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"

namespace faker
{
namespace
{
const std::map<Country, CountryAddresses> countryToCountryAddressesMapping{
    {Country::Usa, usaAddresses},
    {Country::Poland, polandAddresses},
    {Country::Russia, russiaAddresses},
    {Country::France, franceAddresses},
};
}

std::string Location::country()
{
    return Helper::arrayElement<std::string>(allCountries);
}

std::string Location::countryCode()
{
    return Helper::arrayElement<std::string>(countryCodes);
}

std::string Location::state()
{
    return Helper::arrayElement<std::string>(states);
}

std::string Location::city(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::arrayElement<std::string>(countryAddresses.cities);
}

std::string Location::zipCode(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::replaceSymbolWithNumber(countryAddresses.zipCodeFormat);
}

std::string Location::streetAddress(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&country]() { return buildingNumber(country); }},
        {"street", [&country]() { return street(country); }},
        {"secondaryAddress", [&country]() { return secondaryAddress(country); }}};

    const auto addressFormat = Helper::arrayElement<std::string>(countryAddresses.addressFormats);

    return FormatHelper::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string Location::street(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto streetFormat = Helper::arrayElement<std::string>(countryAddresses.streetFormats);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return Person::firstName(country); }},
        {"lastName", [&country]() { return Person::lastName(country); }},
        {"streetName",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetNames); }},
        {"streetPrefix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetPrefixes); }},
        {"streetSuffix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetSuffixes); }}};

    return FormatHelper::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string Location::buildingNumber(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto buildingNumberFormat = Helper::arrayElement<std::string>(countryAddresses.buildingNumberFormats);

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string Location::secondaryAddress(Country country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto secondaryAddressFormat = Helper::arrayElement<std::string>(countryAddresses.secondaryAddressFormats);

    return Helper::replaceSymbolWithNumber(secondaryAddressFormat);
}

std::string Location::latitude(Precision precision)
{
    const std::floating_point auto latitude = Number::decimal<double>(-90.0, 90.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << latitude;

    return ss.str();
}

std::string Location::longitude(Precision precision)
{
    const std::floating_point auto longitude = Number::decimal<double>(-180.0, 180.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << longitude;

    return ss.str();
}

std::string Location::direction()
{
    return Helper::arrayElement<std::string>(directions);
}

std::string Location::timeZone()
{
    return Helper::arrayElement<std::string>(timeZones);
}

}
