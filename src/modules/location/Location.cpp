#include "faker-cxx/Location.h"

#include <map>

#include "../../common/mappers/PrecisionMapper.h"
#include "../../common/StringHelper.h"
#include "data/Countries.h"
#include "data/States.h"
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
const std::map<Country, std::vector<std::string>> countryToCitiesMapping{
    {Country::Usa, usaCities},
};

const std::map<Country, std::string> countryToZipCodeFormatMapping{
    {Country::Usa, usaZipCodeFormat},
};

const std::map<Country, std::vector<std::string>> countryToBuildingNumberFormatsMapping{
    {Country::Usa, usaBuildingNumberFormats},
};

const std::map<Country, std::vector<std::string>> countryToStreetFormatsMapping{
    {Country::Usa, usaStreetFormats},
};

const std::map<Country, std::string> countryToAddressFormatMapping{
    {Country::Usa, usaAddressFormat},
};

const std::map<Country, std::vector<std::string>> countryToStreetSuffixesMapping{
    {Country::Usa, usaStreetSuffixes},
};
}

std::string Location::country()
{
    return Helper::arrayElement<std::string>(countries);
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

    std::string zipCode;

    for (const auto& zipCodeFormatCharacter : zipCodeFormat)
    {
        if (zipCodeFormatCharacter == '#')
        {
            zipCode += String::numeric(1);
        }
        else
        {
            zipCode += zipCodeFormatCharacter;
        }
    }

    return zipCode;
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
    }

    return StringHelper::join(streetNameElements, " ");
}

std::string Location::buildingNumber(Country country)
{
    const auto& buildingNumberFormats = countryToBuildingNumberFormatsMapping.at(country);

    const auto buildingNumberFormat = Helper::arrayElement<std::string>(buildingNumberFormats);

    std::string buildingNumber;

    for (const auto& buildingNumberFormatCharacter : buildingNumberFormat)
    {
        if (buildingNumberFormatCharacter == '#')
        {
            buildingNumber += String::numeric(1);
        }
        else
        {
            buildingNumber += buildingNumberFormatCharacter;
        }
    }

    return buildingNumber;
}

std::string Location::latitude(Precision precision)
{
    const std::floating_point auto latitude = Number::decimal<double>(-90.0, 90.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::toDecimalPlaces(precision));

    ss << latitude;

    return ss.str();
}

std::string Location::longitude(Precision precision)
{
    const std::floating_point auto longitude = Number::decimal<double>(-180.0, 180.0);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::toDecimalPlaces(precision));

    ss << longitude;

    return ss.str();
}

}
