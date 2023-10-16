#include "faker-cxx/Location.h"

#include <map>

#include "../../common/mappers/precisionMapper/PrecisionMapper.h"
#include "../../common/StringHelper.h"
#include "data/Countries.h"
#include "data/Directions.h"
#include "data/france/FranceAddressFormat.h"
#include "data/france/FranceCities.h"
#include "data/france/FranceStreetPrefixes.h"
#include "data/france/FranceStreetSuffixes.h"
#include "data/poland/PolandAddressFromat.h"
#include "data/poland/PolandCities.h"
#include "data/poland/PolandStreetNames.h"
#include "data/poland/PolandStreetPrefixes.h"
#include "data/russia/RussiaAddressFormat.h"
#include "data/russia/RussiaCities.h"
#include "data/russia/RussiaStreetPrefixes.h"
#include "data/States.h"
#include "data/TimeZones.h"
#include "data/usa/UsaAddressFormat.h"
#include "data/usa/UsaCities.h"
#include "data/usa/UsaStreetSuffixes.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"

namespace faker
{
namespace
{
const std::map<Country, std::vector<std::string>> countryToCitiesMapping{{Country::Usa, usaCities},
                                                                         {Country::Russia, russiaCities},
                                                                         {Country::Poland, polandCities},
                                                                         {Country::France, franceCities}};

const std::map<Country, std::vector<std::string>> countryToStreetsMapping{{Country::Poland, polandStreets}};

const std::map<Country, std::string> countryToZipCodeFormatMapping{{Country::Usa, usaZipCodeFormat},
                                                                   {Country::Russia, russiaZipCodeFormat},
                                                                   {Country::Poland, polandZipCodeFormat},
                                                                   {Country::France, franceZipCodeFormat}};

const std::map<Country, std::vector<std::string>> countryToBuildingNumberFormatsMapping{
    {Country::Usa, usaBuildingNumberFormats},
    {Country::Russia, russiaBuildingNumberFormats},
    {Country::Poland, polandBuildingNumberFormats},
    {Country::France, franceBuildingNumberFormats}};

const std::map<Country, std::vector<std::string>> countryToStreetFormatsMapping{{Country::Usa, usaStreetFormats},
                                                                                {Country::Russia, russiaStreetFormats},
                                                                                {Country::Poland, polandStreetFormats},
                                                                                {Country::France, franceStreetFormats}};

const std::map<Country, std::vector<std::string>> countryToSecondaryAddressFormatsMapping{
    {Country::Usa, usaSecondaryAddressFormats}, {Country::France, franceSecondaryAddressFormats}};

const std::map<Country, std::string> countryToAddressFormatMapping{{Country::Usa, usaAddressFormat},
                                                                   {Country::Russia, russiaAddressFormat},
                                                                   {Country::Poland, polandAddressFormat},
                                                                   {Country::France, franceAddressFormat}};

const std::map<Country, std::vector<std::string>> countryToStreetSuffixesMapping{
    {Country::Usa, usaStreetSuffixes}, {Country::France, franceStreetSuffixes}};

const std::map<Country, std::vector<std::string>> countryToStreetPrefixesMapping{
    {Country::Russia, russiaStreetPrefixes},
    {Country::Poland, polandStreetPrefixes},
    {Country::France, franceStreetPrefixes}};
}

std::string Location::country()
{
    return Helper::arrayElement<std::string>(countries);
}

std::string Location::countryCode()
{
    return Helper::arrayElement<std::string>(countryCodes);
}

std::string Location::state()
{
    return Helper::arrayElement<std::string>(states);
}

std::string Location::city(Country country)
{
    const auto& cities = countryToCitiesMapping.at(country);

    return Helper::arrayElement<std::string>(cities);
}

std::string Location::zipCode(Country country)
{
    const auto& zipCodeFormat = countryToZipCodeFormatMapping.at(country);

    return Helper::replaceSymbolWithNumber(zipCodeFormat);
}

std::string Location::streetAddress(Country country)
{
    const auto& addressFormat = countryToAddressFormatMapping.at(country);

    const auto addressFormatElements = StringHelper::split(addressFormat, " ");

    std::vector<std::string> addressElements;

    for (const auto& addressFormatElement : addressFormatElements)
    {
        if (addressFormatElement == "{buildingNumber}")
        {
            addressElements.push_back(buildingNumber(country));
        }
        else if (addressFormatElement == "{street}")
        {
            addressElements.push_back(street(country));
        }
    }

    return StringHelper::join(addressElements, " ");
}

std::string Location::street(Country country)
{
    const auto& streetFormats = countryToStreetFormatsMapping.at(country);

    const auto streetFormat = Helper::arrayElement<std::string>(streetFormats);

    const auto streetFormatElements = StringHelper::split(streetFormat, " ");

    std::vector<std::string> streetNameElements;

    for (const auto& streetFormatElement : streetFormatElements)
    {
        if (streetFormatElement == "{firstName}")
        {
            streetNameElements.push_back(Person::firstName());
        }
        else if (streetFormatElement == "{lastName}")
        {
            streetNameElements.push_back(Person::lastName());
        }
        else if (streetFormatElement == "{streetSuffix}")
        {
            const auto& streetSuffixes = countryToStreetSuffixesMapping.at(country);

            const auto streetSuffix = Helper::arrayElement<std::string>(streetSuffixes);

            streetNameElements.push_back(streetSuffix);
        }
        else if (streetFormatElement == "{streetPrefix}")
        {
            const auto& streetPrefixes = countryToStreetPrefixesMapping.at(country);

            const auto streetPrefix = Helper::arrayElement<std::string>(streetPrefixes);

            streetNameElements.push_back(streetPrefix);
        }
        else if (streetFormatElement == "{streetName}")
        {
            const auto& streets = countryToStreetsMapping.at(country);
            streetNameElements.push_back(Helper::arrayElement<std::string>(streets));
        }
    }

    return StringHelper::join(streetNameElements, " ");
}

std::string Location::buildingNumber(Country country)
{
    const auto& buildingNumberFormats = countryToBuildingNumberFormatsMapping.at(country);

    const auto buildingNumberFormat = Helper::arrayElement<std::string>(buildingNumberFormats);

    return Helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string Location::secondaryAddress(Country country)
{
    const auto& secondaryAddressFormats = countryToSecondaryAddressFormatsMapping.at(country);

    const auto secondaryAddressFormat = Helper::arrayElement<std::string>(secondaryAddressFormats);

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
