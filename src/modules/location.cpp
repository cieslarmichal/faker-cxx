#include "faker-cxx/location.h"

#include <string>
#include <string_view>
#include <unordered_map>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/country.h"
#include "faker-cxx/types/precision.h"
#include "location_data.h"

namespace faker::location
{
namespace
{
CountryAddressesInfo getAddresses(const AddressCountry& country)
{
    switch (country)
    {
    case AddressCountry::Usa:
        return usaAddresses;
    case AddressCountry::Poland:
        return polandAddresses;
    case AddressCountry::Russia:
        return russiaAddresses;
    case AddressCountry::France:
        return franceAddresses;
    case AddressCountry::Ukraine:
        return ukraineAddresses;
    case AddressCountry::Italy:
        return italyAddresses;
    case AddressCountry::Germany:
        return germanyAddresses;
    case AddressCountry::Czech:
        return czechAddresses;
    case AddressCountry::Australia:
        return australiaAddresses;
    case AddressCountry::India:
        return indiaAddresses;
    case AddressCountry::Denmark:
        return denmarkAddresses;
    case AddressCountry::Spain:
        return spainAddresses;
    case AddressCountry::Brazil:
        return brazilAddresses;
    case AddressCountry::Finland:
        return finlandAddresses;
    case AddressCountry::Estonia:
        return estoniaAddresses;
    default:
        return usaAddresses;
    }
}

Country getCountry(const AddressCountry& addressCountry)
{
    switch (addressCountry)
    {
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
        return Country::Usa;
    }
}
}

std::string_view country()
{
    return helper::randomElement(allCountries);
}

std::string_view countryCode()
{
    return helper::randomElement(countryCodes);
}

std::string_view state(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    return helper::randomElement(countryAddresses.states);
}

std::string city(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto cityFormat = static_cast<std::string>(helper::randomElement(countryAddresses.cityFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return static_cast<std::string>(person::firstName(getCountry(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(person::lastName(getCountry(country))); }},
        {"cityName",
         [&countryAddresses]() { return static_cast<std::string>(helper::randomElement(countryAddresses.cities)); }},
        {"cityPrefix", [&countryAddresses]()
         { return static_cast<std::string>(helper::randomElement(countryAddresses.cityPrefixes)); }},
        {"citySuffix", [&countryAddresses]()
         { return static_cast<std::string>(helper::randomElement(countryAddresses.citySuffixes)); }}};

    return common::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string zipCode(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    return helper::replaceSymbolWithNumber(static_cast<std::string>(countryAddresses.zipCodeFormat));
}

std::string streetAddress(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&country]() { return buildingNumber(country); }},
        {"street", [&country]() { return street(country); }},
        {"secondaryAddress", [&country]() { return secondaryAddress(country); }}};

    const auto addressFormat = static_cast<std::string>(helper::randomElement(countryAddresses.addressFormats));

    return common::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string street(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto streetFormat = static_cast<std::string>(helper::randomElement(countryAddresses.streetFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return static_cast<std::string>(person::firstName(getCountry(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(person::lastName(getCountry(country))); }},
        {"streetName", [&countryAddresses]()
         { return static_cast<std::string>(helper::randomElement(countryAddresses.streetNames)); }},
        {"streetPrefix", [&countryAddresses]()
         { return static_cast<std::string>(helper::randomElement(countryAddresses.streetPrefixes)); }},
        {"streetSuffix", [&countryAddresses]()
         { return static_cast<std::string>(helper::randomElement(countryAddresses.streetSuffixes)); }}};

    return common::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string buildingNumber(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto buildingNumberFormat =
        static_cast<std::string>(helper::randomElement(countryAddresses.buildingNumberFormats));

    return helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    if (countryAddresses.secondaryAddressFormats.empty())
    {
        return "";
    }

    const auto secondaryAddressFormat =
        static_cast<std::string>(helper::randomElement(countryAddresses.secondaryAddressFormats));

    return helper::replaceSymbolWithNumber(secondaryAddressFormat);
}

std::string latitude(Precision precision)
{
    const std::floating_point auto latitude = number::decimal<double>(-90.0, 90.0);

    return common::precisionFormat(precision, latitude);
}

std::string longitude(Precision precision)
{
    const std::floating_point auto longitude = number::decimal<double>(-180.0, 180.0);

    return common::precisionFormat(precision, longitude);
}

std::string_view direction()
{
    return helper::randomElement(directions);
}

std::string_view timeZone()
{
    return helper::randomElement(timeZones);
}

}
