#include "faker-cxx/Phone.h"

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "../../common/AlgoHelper.h"
#include "faker-cxx/Helper.h"
#include "PhoneData.h"

namespace faker::phone
{
std::unordered_map<PhoneNumberCountryFormat, std::string> phoneNumberFormatMap = createPhoneNumberFormatMap();

std::string number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty())
    {
        selectedFormat = helper::arrayElement(phone::phoneNumbers);
    }
    else
    {
        selectedFormat = format.value();
    }

    return helper::replaceSymbolWithNumber(selectedFormat);
}

std::string number(PhoneNumberCountryFormat format)
{
    std::string countryFormat = phoneNumberFormatMap.at(format);

    if (countryFormat.empty())
    {
        return phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);
    }

    return helper::replaceSymbolWithNumber(countryFormat);
}

std::string imei()
{
    return helper::replaceCreditCardSymbols("##-######-######-L", '#');
}

std::string_view platform()
{
    return helper::arrayElement(phone::PhonePlatforms);
}

std::string_view modelName()
{
    return helper::arrayElement(phone::PhoneModelNames);
}

std::string_view manufacturer()
{
    return helper::arrayElement(phone::PhoneManufacturers);
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
    return helper::arrayElement(phone::areaCodes);
}
}
