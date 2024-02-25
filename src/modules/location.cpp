#include "../common/format_helper.h"
#include "../common/mappers/precision_mapper/precision_mapper.h"
#include "location_data.h"
#include <faker/helper.h>
#include <faker/location.h>
#include <faker/person.h>
#include <faker/string.h>

namespace faker::location {
namespace {
    const data::CountryAddresses& countryToCountryAddressesMapping(AddressCountry country)
    {
        switch (country) {
        case AddressCountry::Usa:
            return data::usaAddresses;
        case AddressCountry::Poland:
            return data::polandAddresses;
        case AddressCountry::Russia:
            return data::russiaAddresses;
        case AddressCountry::France:
            return data::franceAddresses;
        case AddressCountry::Ukraine:
            return data::ukraineAddresses;
        case AddressCountry::Italy:
            return data::italyAddresses;
        case AddressCountry::Germany:
            return data::germanyAddresses;
        case AddressCountry::Czech:
            return data::czechAddresses;
        case AddressCountry::Australia:
            return data::australiaAddresses;
        case AddressCountry::India:
            return data::indiaAddresses;
        case AddressCountry::Denmark:
            return data::denmarkAddresses;
        case AddressCountry::Spain:
            return data::spainAddresses;
        case AddressCountry::Brazil:
            return data::brazilAddresses;
        case AddressCountry::Finland:
            return data::finlandAddresses;
        case AddressCountry::Estonia:
            return data::estoniaAddresses;
        default:
            throw std::invalid_argument("Invalid country");
        }
    }

    Country countryAddressToCountryMapping(AddressCountry country)
    {
        switch (country) {
        case AddressCountry::Usa:
            return Country::Usa;
        case AddressCountry::Poland:
            return Country::Poland;
        case AddressCountry::Russia:
            return Country::Russia;
        case AddressCountry::France:
            return Country::France;
        case AddressCountry::Ukraine:
            return Country::Ukraine;
        case AddressCountry::Italy:
            return Country::Italy;
        case AddressCountry::Germany:
            return Country::Germany;
        case AddressCountry::Czech:
            return Country::Czech;
        case AddressCountry::Australia:
            return Country::Australia;
        case AddressCountry::India:
            return Country::India;
        case AddressCountry::Denmark:
            return Country::Denmark;
        case AddressCountry::Spain:
            return Country::Spain;
        case AddressCountry::Brazil:
            return Country::Brazil;
        case AddressCountry::Finland:
            return Country::Finland;
        case AddressCountry::Estonia:
            return Country::Estonia;
        default:
            throw std::invalid_argument("Invalid country");
        }
    }
}

std::string_view country() { return Helper::arrayElement(data::allCountries); }

std::string_view countryCode() { return Helper::arrayElement(data::countryCodes); }

std::string_view county(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    if (countryAddresses.counties.empty()) {
        return "";
    }
    return Helper::arrayElement(countryAddresses.counties);
}

std::string_view state(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    return Helper::arrayElement(countryAddresses.states);
}

std::string city(AddressCountry country)
{
    auto& countryAddresses = countryToCountryAddressesMapping(country);
    auto cityFormat = Helper::arrayElement(countryAddresses.cityFormats);

    return FormatHelper::fillTokenValues(
        cityFormat, [country, countryAddresses](std::string_view token) {
            if (token == "firstName") {
                return person::firstName(countryAddressToCountryMapping(country));
            } else if (token == "lastName") {
                return person::lastName(countryAddressToCountryMapping(country));
            } else if (token == "cityName") {
                return std::string(Helper::arrayElement(countryAddresses.cities));
            } else if (token == "cityPrefix") {
                return std::string(Helper::arrayElement(countryAddresses.cityPrefixes));
            } else if (token == "citySuffix") {
                return std::string(Helper::arrayElement(countryAddresses.citySuffixes));
            } else {
                return std::string();
            }
        });
}

std::string zipCode(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    return Helper::replaceSymbolWithNumber(countryAddresses.zipCodeFormat);
}

std::string streetAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    const auto addressFormat = Helper::arrayElement(countryAddresses.addressFormats);

    return FormatHelper::fillTokenValues(addressFormat, [country](std::string_view token) {
        if (token == "buildingNumber") {
            return buildingNumber(country);
        } else if (token == "street") {
            return street(country);
        } else if (token == "secondaryAddress") {
            return secondaryAddress(country);
        } else {
            return std::string();
        }
    });
}

std::string street(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    const auto streetFormat = Helper::arrayElement(countryAddresses.streetFormats);

    return FormatHelper::fillTokenValues(
        streetFormat, [country, countryAddresses](std::string_view token) {
            if (token == "firstName") {
                return person::firstName(countryAddressToCountryMapping(country));
            } else if (token == "lastName") {
                return person::lastName(countryAddressToCountryMapping(country));
            } else if (token == "streetName") {
                return std::string(Helper::arrayElement(countryAddresses.streetNames));
            } else if (token == "streetPrefix") {
                return std::string(Helper::arrayElement(countryAddresses.streetPrefixes));
            } else if (token == "streetSuffix") {
                return std::string(Helper::arrayElement(countryAddresses.streetSuffixes));
            } else {
                return std::string();
            }
        });
}

std::string buildingNumber(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto buildingNumberFormat = Helper::arrayElement(countryAddresses.buildingNumberFormats);

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    if (countryAddresses.secondaryAddressFormats.empty()) {
        return "";
    }

    const auto secondaryAddressFormat
        = Helper::arrayElement(countryAddresses.secondaryAddressFormats);

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

std::string_view direction() { return Helper::arrayElement(data::directions); }

std::string_view timeZone() { return Helper::arrayElement(data::timeZones); }

}
