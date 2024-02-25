#include "../common/format_helper.h"
#include "../common/mappers/precision_mapper/precision_mapper.h"
#include "location_data.h"
#include <faker/helper.h>
#include <faker/location.h>
#include <faker/person.h>
#include <faker/string.h>
#include <unordered_map>

namespace faker::location {
namespace {
    const CountryAddresses& countryToCountryAddressesMapping(AddressCountry country)
    {
        static const std::unordered_map<AddressCountry, CountryAddresses> items {
            { AddressCountry::Usa, usaAddresses },
            { AddressCountry::Poland, polandAddresses },
            { AddressCountry::Russia, russiaAddresses },
            { AddressCountry::France, franceAddresses },
            { AddressCountry::Ukraine, ukraineAddresses },
            { AddressCountry::Italy, italyAddresses },
            { AddressCountry::Germany, germanyAddresses },
            { AddressCountry::Czech, czechAddresses },
            { AddressCountry::Australia, australiaAddresses },
            { AddressCountry::India, indiaAddresses },
            { AddressCountry::Denmark, denmarkAddresses },
            { AddressCountry::Spain, spainAddresses },
            { AddressCountry::Brazil, brazilAddresses },
            { AddressCountry::Finland, finlandAddresses },
            { AddressCountry::Estonia, estoniaAddresses },
        };

        return items.at(country);
    }

    Country countryAddressToCountryMapping(AddressCountry country)
    {
        static const std::unordered_map<AddressCountry, Country> countryAddressToCountryMapping {
            { AddressCountry::Usa, Country::Usa },
            { AddressCountry::Poland, Country::Poland },
            { AddressCountry::Russia, Country::Russia },
            { AddressCountry::France, Country::France },
            { AddressCountry::Ukraine, Country::Ukraine },
            { AddressCountry::Italy, Country::Italy },
            { AddressCountry::Germany, Country::Germany },
            { AddressCountry::Czech, Country::Czech },
            { AddressCountry::Australia, Country::Australia },
            { AddressCountry::India, Country::India },
            { AddressCountry::Denmark, Country::Denmark },
            { AddressCountry::Spain, Country::Spain },
            { AddressCountry::Brazil, Country::Brazil },
            { AddressCountry::Finland, Country::Finland },
            { AddressCountry::Estonia, Country::Estonia },
        };

        return countryAddressToCountryMapping.at(country);
    }
}

std::string_view country() { return Helper::arrayElement(allCountries); }

std::string_view countryCode() { return Helper::arrayElement(countryCodes); }

std::string county(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    if (countryAddresses.counties.empty()) {
        return "";
    }
    return Helper::arrayElement<std::string>(countryAddresses.counties);
}

std::string state(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    return Helper::arrayElement<std::string>(countryAddresses.states);
}

std::string city(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto cityFormat = Helper::arrayElement(countryAddresses.cityFormats);

    const auto dataGeneratorsMapping
        = std::unordered_map<std::string, std::function<std::string()>> {
              { "firstName",
                  [&country]() {
                      return person::firstName(countryAddressToCountryMapping(country));
                  } },
              { "lastName",
                  [&country]() {
                      return person::lastName(countryAddressToCountryMapping(country));
                  } },
              { "cityName",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.cities);
                  } },
              { "cityPrefix",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.cityPrefixes);
                  } },
              { "citySuffix",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.citySuffixes);
                  } }
          };

    return FormatHelper::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string zipCode(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    return Helper::replaceSymbolWithNumber(countryAddresses.zipCodeFormat);
}

std::string streetAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto dataGeneratorsMapping
        = std::unordered_map<std::string, std::function<std::string()>> {
              { "buildingNumber", [&country]() { return buildingNumber(country); } },
              { "street", [&country]() { return street(country); } },
              { "secondaryAddress", [&country]() { return secondaryAddress(country); } }
          };

    const auto addressFormat = Helper::arrayElement<std::string>(countryAddresses.addressFormats);

    return FormatHelper::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string street(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto streetFormat = Helper::arrayElement<std::string>(countryAddresses.streetFormats);

    const auto dataGeneratorsMapping
        = std::unordered_map<std::string, std::function<std::string()>> {
              { "firstName",
                  [&country]() {
                      return person::firstName(countryAddressToCountryMapping(country));
                  } },
              { "lastName",
                  [&country]() {
                      return person::lastName(countryAddressToCountryMapping(country));
                  } },
              { "streetName",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.streetNames);
                  } },
              { "streetPrefix",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.streetPrefixes);
                  } },
              { "streetSuffix",
                  [&countryAddresses]() {
                      return Helper::arrayElement<std::string>(countryAddresses.streetSuffixes);
                  } }
          };

    return FormatHelper::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string buildingNumber(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto buildingNumberFormat
        = Helper::arrayElement<std::string>(countryAddresses.buildingNumberFormats);

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    if (countryAddresses.secondaryAddressFormats.empty()) {
        return "";
    }

    const auto secondaryAddressFormat
        = Helper::arrayElement<std::string>(countryAddresses.secondaryAddressFormats);

    return Helper::replaceSymbolWithNumber(secondaryAddressFormat);
}

std::string latitude(Precision precision)
{
    const auto latitude = number::decimal(-90.0, 90.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << latitude;

    return ss.str();
}

std::string longitude(Precision precision)
{
    const auto longitude = number::decimal(-180.0, 180.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << longitude;

    return ss.str();
}

std::string_view direction() { return Helper::arrayElement(directions); }

std::string_view timeZone() { return Helper::arrayElement(timeZones); }

}
