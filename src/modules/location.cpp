#include "../common/formatter.h"
#include "../common/random.h"
#include "location_data.h"
#include <faker/location.h>
#include <faker/number.h>
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

std::string_view country_name() { return random::element(data::allCountries); }

std::string_view country_code() { return random::element(data::countryCodes); }

std::string_view county(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    if (countryAddresses.counties.empty()) {
        return "";
    }
    return random::element(countryAddresses.counties);
}

std::string_view state(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    return random::element(countryAddresses.states);
}

std::string city(AddressCountry country)
{
    auto& countryAddresses = countryToCountryAddressesMapping(country);
    auto cityFormat = random::element(countryAddresses.cityFormats);

    return utils::fill_token_values(
        cityFormat, [country, countryAddresses](std::string_view token) {
            if (token == "firstName") {
                return person::first_name(countryAddressToCountryMapping(country));
            } else if (token == "lastName") {
                return person::last_name(countryAddressToCountryMapping(country));
            } else if (token == "cityName") {
                return std::string(random::element(countryAddresses.cities));
            } else if (token == "cityPrefix") {
                return std::string(random::element(countryAddresses.cityPrefixes));
            } else if (token == "citySuffix") {
                return std::string(random::element(countryAddresses.citySuffixes));
            } else {
                return std::string();
            }
        });
}

std::string zip_code(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    return random::replace_symbol_with_number(countryAddresses.zipCodeFormat);
}

std::string street_address(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    const auto addressFormat = random::element(countryAddresses.addressFormats);

    return utils::fill_token_values(addressFormat, [country](std::string_view token) {
        if (token == "buildingNumber") {
            return building_number(country);
        } else if (token == "street") {
            return street(country);
        } else if (token == "secondaryAddress") {
            return secondary_address(country);
        } else {
            return std::string();
        }
    });
}

std::string street(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);
    const auto streetFormat = random::element(countryAddresses.streetFormats);

    return utils::fill_token_values(
        streetFormat, [country, countryAddresses](std::string_view token) {
            if (token == "firstName") {
                return person::first_name(countryAddressToCountryMapping(country));
            } else if (token == "lastName") {
                return person::last_name(countryAddressToCountryMapping(country));
            } else if (token == "streetName") {
                return std::string(random::element(countryAddresses.streetNames));
            } else if (token == "streetPrefix") {
                return std::string(random::element(countryAddresses.streetPrefixes));
            } else if (token == "streetSuffix") {
                return std::string(random::element(countryAddresses.streetSuffixes));
            } else {
                return std::string();
            }
        });
}

std::string building_number(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto buildingNumberFormat = random::element(countryAddresses.buildingNumberFormats);

    return random::replace_symbol_with_number(buildingNumberFormat);
}

std::string secondary_address(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    if (countryAddresses.secondaryAddressFormats.empty()) {
        return "";
    }

    const auto secondaryAddressFormat = random::element(countryAddresses.secondaryAddressFormats);

    return random::replace_symbol_with_number(secondaryAddressFormat);
}

std::string latitude(Precision precision)
{
    const auto latitude = number::decimal(-90.0, 90.0);
    return utils::format(utils::precision_format_str(precision), latitude);
}

std::string longitude(Precision precision)
{
    const auto longitude = number::decimal(-180.0, 180.0);
    return utils::format(utils::precision_format_str(precision), longitude);
}

std::string_view direction() { return random::element(data::directions); }

std::string_view time_zone() { return random::element(data::timeZones); }

}
