#include "faker-cxx/Phone.h"

#include <string>

#include "data/PhoneNumbers.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::map<PhoneNumberCountryFormat, std::string> Phone::phoneNumberFormatMap = Phone::createPhoneNumberFormatMap();

std::string Phone::number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty())
    {
        selectedFormat = Helper::arrayElement<std::string>(phoneNumbers);
    }
    else
    {
        selectedFormat = format.value();
    }

    return Helper::replaceSymbolWithNumber(selectedFormat);
}

std::string Phone::number(PhoneNumberCountryFormat format)
{
    std::string countryFormat = phoneNumberFormatMap.at(format);

    if (countryFormat.empty())
    {
        return phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);
    }

    return Helper::replaceSymbolWithNumber(countryFormat);
}

std::string Phone::imei()
{
    return Helper::replaceCreditCardSymbols("##-######-######-L", '#');
}

std::string Phone::platform()
{
    std::vector<std::string> platforms = {"Android OS", "iOS", "Windows Phone"};
    return Helper::arrayElement(platforms);
}

std::string Phone::modelName()
{
    std::vector<std::string> modelNames = {"Samsung Galaxy S9", "iPhone X", "Google Pixel 4"};
    return Helper::arrayElement(modelNames);
}

std::string Phone::manufacturer()
{
    std::vector<std::string> manufacturers = {"Samsung", "Apple", "Google"};
    return Helper::arrayElement(manufacturers);
}

std::map<PhoneNumberCountryFormat, std::string> Phone::createPhoneNumberFormatMap()
{
    std::map<PhoneNumberCountryFormat, std::string> formatMap;

    // Loop through all the PhoneNumberCountryFormat enum values
    for (auto i = static_cast<unsigned long>(PhoneNumberCountryFormat::Default);
         i <= static_cast<unsigned long>(PhoneNumberCountryFormat::Zimbabwe); i++)
    {
        auto formatEnum = static_cast<PhoneNumberCountryFormat>(i);

        formatMap[formatEnum] = phoneNumbers[i];
    }

    return formatMap;
}
}
