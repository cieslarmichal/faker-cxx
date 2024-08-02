#include "faker-cxx/phone.h"

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "common/algo_helper.h"
#include "faker-cxx/helper.h"
#include "phone_data.h"

namespace faker::phone
{
std::unordered_map<PhoneNumberCountryFormat, std::string> phoneNumberFormatMap = createPhoneNumberFormatMap();

std::string phoneNumberByFormat(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty())
    {
        selectedFormat = helper::randomElement(phone::phoneNumbers);
    }
    else
    {
        selectedFormat = format.value();
    }

    return helper::replaceSymbolWithNumber(selectedFormat);
}

std::string phoneNumberByCountry(std::optional<PhoneNumberCountryFormat> format)
{
    std::string countryFormat = (format)? phoneNumberFormatMap.at(*format) : 
    phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);

    return helper::replaceSymbolWithNumber(countryFormat);
}

std::string imei()
{
    return helper::replaceCreditCardSymbols("##-######-######-L", '#');
}

std::string_view platform()
{
    return helper::randomElement(phone::PhonePlatforms);
}

std::string_view modelName()
{
    return helper::randomElement(phone::PhoneModelNames);
}

std::string_view manufacturer()
{
    return helper::randomElement(phone::PhoneManufacturers);
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
    return helper::randomElement(phone::areaCodes);
}
}
