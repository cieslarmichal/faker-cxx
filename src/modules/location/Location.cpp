#include "faker-cxx/Location.h"

#include <map>
#include <sstream>

#include "../../common/FormatHelper.h"
#include "../../common/PrecisionMapper.h"
#include "data/argentina/ArgentinaAddresses.h"
#include "data/australia/AustraliaAddresses.h"
#include "data/belgium/BelgiumAddresses.h"
#include "data/brazil/BrazilAddresses.h"
#include "data/Countries.h"
#include "data/czech/CzechAddresses.h"
#include "data/denmark/DenmarkAddresses.h"
#include "data/Directions.h"
#include "data/estonia/EstoniaAddresses.h"
#include "data/finland/FinlandAddresses.h"
#include "data/france/FranceAddresses.h"
#include "data/germany/GermanyAddresses.h"
#include "data/india/IndiaAddresses.h"
#include "data/italy/ItalyAddresses.h"
#include "data/latvia/LatviaAddresses.h"
#include "data/nepal/NepalAddresses.h"
#include "data/poland/PolandAddresses.h"
#include "data/romania/RomaniaAddresses.h"
#include "data/russia/RussiaAddresses.h"
#include "data/serbia/SerbiaAddresses.h"
#include "data/spain/SpainAddresses.h"
#include "data/TimeZones.h"
#include "data/ukraine/UkraineAddresses.h"
#include "data/usa/UsaAddresses.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"

namespace faker
{
namespace
{
const std::map<AddressCountry, CountryAddresses> countryToCountryAddressesMapping{
    {AddressCountry::Argentina, argentinaAddresses}, {AddressCountry::Usa, usaAddresses},
    {AddressCountry::Poland, polandAddresses},       {AddressCountry::Russia, russiaAddresses},
    {AddressCountry::France, franceAddresses},       {AddressCountry::Ukraine, ukraineAddresses},
    {AddressCountry::Italy, italyAddresses},         {AddressCountry::Germany, germanyAddresses},
    {AddressCountry::Czech, czechAddresses},         {AddressCountry::Australia, australiaAddresses},
    {AddressCountry::India, indiaAddresses},         {AddressCountry::Denmark, denmarkAddresses},
    {AddressCountry::Spain, spainAddresses},         {AddressCountry::Brazil, brazilAddresses},
    {AddressCountry::Finland, finlandAddresses},     {AddressCountry::Estonia, estoniaAddresses},
    {AddressCountry::Romania, romaniaAddresses},     {AddressCountry::Latvia, latviaAddresses},
    {AddressCountry::Nepal, nepalAddresses},         {AddressCountry::Belgium, belgiumAddresses},
    {AddressCountry::Serbia, serbiaAddresses},
};

const std::map<AddressCountry, Country> countryAddressToCountryMapping{
    {AddressCountry::Argentina, Country::Argentina}, {AddressCountry::Usa, Country::Usa},
    {AddressCountry::Poland, Country::Poland},       {AddressCountry::Russia, Country::Russia},
    {AddressCountry::France, Country::France},       {AddressCountry::Ukraine, Country::Ukraine},
    {AddressCountry::Italy, Country::Italy},         {AddressCountry::Germany, Country::Germany},
    {AddressCountry::Czech, Country::Czech},         {AddressCountry::Australia, Country::Australia},
    {AddressCountry::India, Country::India},         {AddressCountry::Denmark, Country::Denmark},
    {AddressCountry::Spain, Country::Spain},         {AddressCountry::Brazil, Country::Brazil},
    {AddressCountry::Finland, Country::Finland},     {AddressCountry::Estonia, Country::Estonia},
    {AddressCountry::Romania, Country::Romania},     {AddressCountry::Latvia, Country::Latvia},
    {AddressCountry::Nepal, Country::Nepal},         {AddressCountry::Belgium, Country::Belgium},
    {AddressCountry::Serbia, Country::Serbia},
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

std::string Location::county(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    if (countryAddresses.counties.empty())
    {
        return "";
    }

    return Helper::arrayElement<std::string>(countryAddresses.counties);
}

std::string Location::state(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::arrayElement<std::string>(countryAddresses.states);
}

std::string Location::city(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto cityFormat = Helper::arrayElement<std::string>(countryAddresses.cityFormats);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return Person::firstName(countryAddressToCountryMapping.at(country)); }},
        {"lastName", [&country]() { return Person::lastName(countryAddressToCountryMapping.at(country)); }},
        {"cityName", [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.cities); }},
        {"cityPrefix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.cityPrefixes); }},
        {"citySuffix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.citySuffixes); }}};

    return FormatHelper::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string Location::zipCode(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::replaceSymbolWithNumber(countryAddresses.zipCodeFormat);
}

std::string Location::streetAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&country]() { return buildingNumber(country); }},
        {"street", [&country]() { return street(country); }},
        {"secondaryAddress", [&country]() { return secondaryAddress(country); }}};

    const auto addressFormat = Helper::arrayElement<std::string>(countryAddresses.addressFormats);

    return FormatHelper::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string Location::street(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto streetFormat = Helper::arrayElement<std::string>(countryAddresses.streetFormats);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return Person::firstName(countryAddressToCountryMapping.at(country)); }},
        {"lastName", [&country]() { return Person::lastName(countryAddressToCountryMapping.at(country)); }},
        {"streetName",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetNames); }},
        {"streetPrefix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetPrefixes); }},
        {"streetSuffix",
         [&countryAddresses]() { return Helper::arrayElement<std::string>(countryAddresses.streetSuffixes); }}};

    return FormatHelper::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string Location::buildingNumber(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto buildingNumberFormat = Helper::arrayElement<std::string>(countryAddresses.buildingNumberFormats);

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string Location::secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    if (countryAddresses.secondaryAddressFormats.empty())
    {
        return "";
    }

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
