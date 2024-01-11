#include "faker-cxx/Location.h"

#include <map>

#include "../../common/FormatHelper.h"
#include "../../common/mappers/precisionMapper/PrecisionMapper.h"
#include "data/Countries.h"
#include "data/Directions.h"
#include "data/australia/AustraliaAddresses.h"
#include "data/czech/CzechAddresses.h"
#include "data/france/FranceAddresses.h"
#include "data/poland/PolandAddresses.h"
#include "data/italy/ItalyAddresses.h"
#include "data/russia/RussiaAddresses.h"
#include "data/States.h"
#include "data/TimeZones.h"
#include "data/ukraine/UkraineAddresses.h"
#include "data/germany/GermanyAddresses.h"
#include "data/usa/UsaAddresses.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "data/india/IndiaAddresses.h"
#include "data/denmark/DenmarkAddresses.h"

namespace faker
{
    namespace
    {
        const std::map<AddressCountry, CountryAddresses> countryToCountryAddressesMapping{
                {AddressCountry::Usa, usaAddresses},         {AddressCountry::Poland, polandAddresses},
                {AddressCountry::Russia, russiaAddresses},   {AddressCountry::France, franceAddresses},
                {AddressCountry::Ukraine, ukraineAddresses}, {AddressCountry::Italy, italyAddresses},
                {AddressCountry::Germany, germanyAddresses}, {AddressCountry::Czech, czechAddresses},
                {AddressCountry::Australia, australiaAddresses}, {AddressCountry::India, indiaAddresses},
                {AddressCountry::Denmark, denmarkAddresses}
        };

        const std::map<AddressCountry, Country> countryAddressToCountryMapping{
                {AddressCountry::Usa, Country::Usa},         {AddressCountry::Poland, Country::Poland},
                {AddressCountry::Russia, Country::Russia},   {AddressCountry::France, Country::France},
                {AddressCountry::Ukraine, Country::Ukraine}, {AddressCountry::Italy, Country::Italy},
                {AddressCountry::Germany, Country::Germany}, {AddressCountry::Czech, Country::Czech},
                {AddressCountry::Australia, Country::Australia}, {AddressCountry::India, Country::India},
                {AddressCountry::Denmark, Country::Denmark},
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

    std::string Location::state(AddressCountry country)
    {
        const auto& countryAddresses = countryToCountryAddressesMapping.at(country);
        return Helper::arrayElement<std::string>(countryAddresses.states);
    }

    std::string Location::city(AddressCountry country)
    {
        const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

        return Helper::arrayElement<std::string>(countryAddresses.cities);
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
