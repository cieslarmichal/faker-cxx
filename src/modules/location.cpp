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
CountryAddressesInfo getAddresses(const Locale& locale)
{
    switch (locale)
    {
    case Locale::en_US:
    case Locale::es_US:
        return usaAddresses;
    case Locale::pl_PL:
        return polandAddresses;
    case Locale::ru_RU:
        return russiaAddresses;
    case Locale::fr_FR:
        return franceAddresses;
    case Locale::uk_UA:
        return ukraineAddresses;
    case Locale::it_IT:
        return italyAddresses;
    case Locale::de_DE:
        return germanyAddresses;
    case Locale::cs_CZ:
        return czechAddresses;
    case Locale::en_AU:
        return australiaAddresses;
    case Locale::as_IN:
    case Locale::bn_IN:
    case Locale::en_IN:
    case Locale::gu_IN:
    case Locale::hi_IN:
    case Locale::kn_IN:
    case Locale::ks_IN:
    case Locale::ml_IN:
    case Locale::mr_IN:
    case Locale::or_IN:
    case Locale::pa_IN:
    case Locale::sa_IN:
    case Locale::ta_IN:
    case Locale::te_IN:
        return indiaAddresses;
    case Locale::da_DK:
        return denmarkAddresses;
    case Locale::ca_ES:
    case Locale::es_ES:
        return spainAddresses;
    case Locale::pt_BR:
        return brazilAddresses;
    case Locale::fi_FI:
        return finlandAddresses;
    case Locale::et_EE:
        return estoniaAddresses;
    default:
        return usaAddresses;
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

std::string_view state(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    if (localeAddresses.states.empty())
    {
        return {};
    }

    return helper::randomElement(localeAddresses.states);
}

std::string city(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto cityFormat = static_cast<std::string>(helper::randomElement(localeAddresses.cityFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&locale]() { return static_cast<std::string>(person::firstName(locale)); }},
        {"lastName", [&locale]() { return static_cast<std::string>(person::lastName(locale)); }},
        {"cityName",
         [&localeAddresses]() { return static_cast<std::string>(helper::randomElement(localeAddresses.cities)); }},
        {"cityPrefix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.cityPrefixes)); }},
        {"citySuffix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.citySuffixes)); }}};

    return common::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string zipCode(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    return helper::replaceSymbolWithNumber(static_cast<std::string>(localeAddresses.zipCodeFormat));
}

std::string streetAddress(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&locale]() { return buildingNumber(locale); }},
        {"street", [&locale]() { return street(locale); }},
        {"secondaryAddress", [&locale]() { return secondaryAddress(locale); }}};

    const auto addressFormat = static_cast<std::string>(helper::randomElement(localeAddresses.addressFormats));

    return common::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string street(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto streetFormat = static_cast<std::string>(helper::randomElement(localeAddresses.streetFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&locale]() { return static_cast<std::string>(person::firstName(locale)); }},
        {"lastName", [&locale]() { return static_cast<std::string>(person::lastName(locale)); }},
        {"streetName",
         [&localeAddresses]() { return static_cast<std::string>(helper::randomElement(localeAddresses.streetNames)); }},
        {"streetPrefix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.streetPrefixes)); }},
        {"streetSuffix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.streetSuffixes)); }}};

    return common::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string buildingNumber(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto buildingNumberFormat =
        static_cast<std::string>(helper::randomElement(localeAddresses.buildingNumberFormats));

    return helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string secondaryAddress(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    if (localeAddresses.secondaryAddressFormats.empty())
    {
        return "";
    }

    const auto secondaryAddressFormat =
        static_cast<std::string>(helper::randomElement(localeAddresses.secondaryAddressFormats));

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
