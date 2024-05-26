#include "faker-cxx/Phone.h"

#include "PhoneData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::unordered_map<PhoneNumberCountryFormat, std::string> Phone::phoneNumberFormatMap =
    Phone::createPhoneNumberFormatMap();

std::string Phone::number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty())
    {
        selectedFormat = Helper::arrayElement(phone::phoneNumbers);
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

std::string_view Phone::platform()
{
    return Helper::arrayElement(phone::PhonePlatforms);
}

std::string_view Phone::modelName()
{
    return Helper::arrayElement(phone::PhoneModelNames);
}

std::string_view Phone::manufacturer()
{
    return Helper::arrayElement(phone::PhoneManufacturers);
}

std::unordered_map<PhoneNumberCountryFormat, std::string> Phone::createPhoneNumberFormatMap()
{
    std::unordered_map<PhoneNumberCountryFormat, std::string> formatMap;

    // Loop through all the PhoneNumberCountryFormat enum values
    for (auto i = static_cast<unsigned long>(PhoneNumberCountryFormat::Default);
         i <= static_cast<unsigned long>(PhoneNumberCountryFormat::Zimbabwe); i++)
    {
        auto formatEnum = static_cast<PhoneNumberCountryFormat>(i);

        formatMap[formatEnum] = phone::phoneNumbers[i];
    }

    return formatMap;
}

std::string_view Phone::areaCode()
{
    return Helper::arrayElement(phone::areaCodes);
}
}
