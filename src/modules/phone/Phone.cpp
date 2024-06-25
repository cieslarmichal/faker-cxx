#include "faker-cxx/Phone.h"

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "faker-cxx/Helper.h"
#include "PhoneData.h"

namespace faker::phone
{
std::unordered_map<PhoneNumberCountryFormat, std::string> phoneNumberFormatMap =
    createPhoneNumberFormatMap();

std::string number(std::optional<std::string> format)
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

std::string number(PhoneNumberCountryFormat format)
{
    std::string countryFormat = phoneNumberFormatMap.at(format);

    if (countryFormat.empty())
    {
        return phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);
    }

    return Helper::replaceSymbolWithNumber(countryFormat);
}

std::string imei()
{
    return Helper::replaceCreditCardSymbols("##-######-######-L", '#');
}

std::string_view platform()
{
    return Helper::arrayElement(phone::PhonePlatforms);
}

std::string_view modelName()
{
    return Helper::arrayElement(phone::PhoneModelNames);
}

std::string_view manufacturer()
{
    return Helper::arrayElement(phone::PhoneManufacturers);
}

std::unordered_map<PhoneNumberCountryFormat, std::string> createPhoneNumberFormatMap()
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

std::string_view areaCode()
{
    return Helper::arrayElement(phone::areaCodes);
}
}
