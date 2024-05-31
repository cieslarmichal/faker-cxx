#include "faker-cxx/Location.h"

#include <sstream>
#include <unordered_map>

#include "../../common/FormatHelper.h"
#include "../../common/PrecisionMapper.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "LocationData.h"

namespace faker
{
namespace
{
const std::unordered_map<AddressCountry, CountryAddressesInfo> countryToCountryAddressesMapping{
    {AddressCountry::Usa, usaAddresses},
    {AddressCountry::Poland, polandAddresses},
    {AddressCountry::Russia, russiaAddresses},
    {AddressCountry::France, franceAddresses},
    {AddressCountry::Ukraine, ukraineAddresses},
    {AddressCountry::Italy, italyAddresses},
    {AddressCountry::Germany, germanyAddresses},
    {AddressCountry::Czech, czechAddresses},
    {AddressCountry::Australia, australiaAddresses},
    {AddressCountry::India, indiaAddresses},
    {AddressCountry::Denmark, denmarkAddresses},
    {AddressCountry::Spain, spainAddresses},
    {AddressCountry::Brazil, brazilAddresses},
    {AddressCountry::Finland, finlandAddresses},
    {AddressCountry::Estonia, estoniaAddresses},
};

const std::unordered_map<AddressCountry, Country> countryAddressToCountryMapping{
    {AddressCountry::Usa, Country::Usa},
    {AddressCountry::Poland, Country::Poland},
    {AddressCountry::Russia, Country::Russia},
    {AddressCountry::France, Country::France},
    {AddressCountry::Ukraine, Country::Ukraine},
    {AddressCountry::Italy, Country::Italy},
    {AddressCountry::Germany, Country::Germany},
    {AddressCountry::Czech, Country::Czech},
    {AddressCountry::Australia, Country::Australia},
    {AddressCountry::India, Country::India},
    {AddressCountry::Denmark, Country::Denmark},
    {AddressCountry::Spain, Country::Spain},
    {AddressCountry::Brazil, Country::Brazil},
    {AddressCountry::Finland, Country::Finland},
    {AddressCountry::Estonia, Country::Estonia},

};
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
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    if (countryAddresses.counties.empty())
    {
        return "";
    }

    return Helper::arrayElement(countryAddresses.counties);
}

std::string_view Location::state(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::arrayElement(countryAddresses.states);
}

std::string Location::city(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto cityFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.cityFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]()
         { return static_cast<std::string>(Person::firstName(countryAddressToCountryMapping.at(country))); }},
        {"lastName", [&country]()
         { return static_cast<std::string>(Person::lastName(countryAddressToCountryMapping.at(country))); }},
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
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    return Helper::replaceSymbolWithNumber(static_cast<std::string>(countryAddresses.zipCodeFormat));
}

std::string Location::streetAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&country]() { return buildingNumber(country); }},
        {"street", [&country]() { return street(country); }},
        {"secondaryAddress", [&country]() { return secondaryAddress(country); }}};

    const auto addressFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.addressFormats));

    return FormatHelper::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string Location::street(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto streetFormat = static_cast<std::string>(Helper::arrayElement(countryAddresses.streetFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country]()
         { return static_cast<std::string>(Person::firstName(countryAddressToCountryMapping.at(country))); }},
        {"lastName", [&country]()
         { return static_cast<std::string>(Person::lastName(countryAddressToCountryMapping.at(country))); }},
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
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto buildingNumberFormat =
        static_cast<std::string>(Helper::arrayElement(countryAddresses.buildingNumberFormats));

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string Location::secondaryAddress(AddressCountry country)
{
    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

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

std::string_view Location::direction()
{
    return Helper::arrayElement(directions);
}

std::string_view Location::timeZone()
{
    return Helper::arrayElement(timeZones);
}

}
