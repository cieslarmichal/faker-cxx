#include "faker-cxx/location.h"

#include <string>
#include <string_view>
#include <unordered_map>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/locale.h"
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

Locale getLocale(const AddressCountry& addressCountry)
{
    switch (addressCountry)
    {
    case AddressCountry::Usa:
        return Locale::en_US;
    case AddressCountry::Poland:
        return Locale::pl_PL;
    case AddressCountry::Russia:
        return Locale::ru_RU;
    case AddressCountry::France:
        return Locale::fr_FR;
    case AddressCountry::Ukraine:
        return Locale::uk_UA;
    case AddressCountry::Italy:
        return Locale::it_IT;
    case AddressCountry::Germany:
        return Locale::de_DE;
    case AddressCountry::Czech:
        return Locale::cs_CZ;
    case AddressCountry::Australia:
        return Locale::en_AU;
    case AddressCountry::India:
        return Locale::hi_IN;
    case AddressCountry::Denmark:
        return Locale::da_DK;
    case AddressCountry::Spain:
        return Locale::es_ES;
    case AddressCountry::Brazil:
        return Locale::pt_BR;
    case AddressCountry::Finland:
        return Locale::fi_FI;
    case AddressCountry::Estonia:
        return Locale::et_EE;
    default:
        return Locale::en_US;
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
        {"firstName", [&country]() { return static_cast<std::string>(person::firstName(getLocale(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(person::lastName(getLocale(country))); }},
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
        {"firstName", [&country]() { return static_cast<std::string>(person::firstName(getLocale(country))); }},
        {"lastName", [&country]() { return static_cast<std::string>(person::lastName(getLocale(country))); }},
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
