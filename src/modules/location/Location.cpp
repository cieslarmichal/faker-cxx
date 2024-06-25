#include "faker-cxx/Location.h"

#include <string>
#include <string_view>
#include <unordered_map>

#include "../../common/FormatHelper.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Precision.h"
#include "LocationData.h"

namespace faker
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

std::string_view Location::country()
{
    return Helper::arrayElement(allCountries);
}

std::string_view Location::countryCode()
{
    return Helper::arrayElement(countryCodes);
}

std::string_view Location::county(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    if (countryAddresses.counties.empty())
    {
        return "";
    }

    return Helper::arrayElement(countryAddresses.counties);
}

std::string_view Location::state(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    return Helper::arrayElement(countryAddresses.states);
}

std::string Location::city(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto cityFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.cityFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return static_cast<std::string>(Person::firstName(getCountry(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(Person::lastName(getCountry(country))); }},
        {"cityName",
         [&countryAddresses]() { return static_cast<std::string>(Helper::arrayElement(countryAddresses.cities)); }},
        {"cityPrefix", [&countryAddresses]()
         { return static_cast<std::string>(Helper::arrayElement(countryAddresses.cityPrefixes)); }},
        {"citySuffix", [&countryAddresses]()
         { return static_cast<std::string>(Helper::arrayElement(countryAddresses.citySuffixes)); }}};

    return FormatHelper::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string Location::zipCode(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    return Helper::replaceSymbolWithNumber(static_cast<std::string>(countryAddresses.zipCodeFormat));
}

std::string Location::streetAddress(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&country]() { return buildingNumber(country); }},
        {"street", [&country]() { return street(country); }},
        {"secondaryAddress", [&country]() { return secondaryAddress(country); }}};

    const auto addressFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.addressFormats));

    return FormatHelper::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string Location::street(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto streetFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.streetFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]() { return static_cast<std::string>(Person::firstName(getCountry(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(Person::lastName(getCountry(country))); }},
        {"streetName", [&countryAddresses]()
         { return static_cast<std::string>(Helper::arrayElement(countryAddresses.streetNames)); }},
        {"streetPrefix", [&countryAddresses]()
         { return static_cast<std::string>(Helper::arrayElement(countryAddresses.streetPrefixes)); }},
        {"streetSuffix", [&countryAddresses]()
         { return static_cast<std::string>(Helper::arrayElement(countryAddresses.streetSuffixes)); }}};

    return FormatHelper::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string Location::buildingNumber(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    const auto buildingNumberFormat =
        static_cast<std::string>(Helper::arrayElement(countryAddresses.buildingNumberFormats));

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string Location::secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = getAddresses(country);

    if (countryAddresses.secondaryAddressFormats.empty())
    {
        return "";
    }

    const auto secondaryAddressFormat =
        static_cast<std::string>(Helper::arrayElement(countryAddresses.secondaryAddressFormats));

    return Helper::replaceSymbolWithNumber(secondaryAddressFormat);
}

std::string Location::latitude(Precision precision)
{
    const std::floating_point auto latitude = faker::number::decimal<double>(-90.0, 90.0);

    return FormatHelper::precisionFormat(precision, latitude);
}

std::string Location::longitude(Precision precision)
{
    const std::floating_point auto longitude = faker::number::decimal<double>(-180.0, 180.0);

    return FormatHelper::precisionFormat(precision, longitude);
}

std::string_view Location::direction()
{
    return Helper::arrayElement(directions);
}

std::string_view Location::timeZone()
{
    return Helper::arrayElement(timeZones);
}

}
