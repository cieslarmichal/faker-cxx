#include "faker-cxx/Phone.h"

#include <string>
#include "faker-cxx/Helper.h"
#include "data/PhoneNumbers.h"

namespace faker
{
std::map<PhoneNumberCountryFormat, std::string> Phone::phoneNumberFormatMap = Phone::createPhoneNumberFormatMap();

std::string Phone::number(std::optional<std::string> format)
{
    std::string selected_format;
    if(!format.has_value() || format->empty())
    {
        selected_format = Helper::arrayElement(std::span<const std::string>(phoneNumbers));
    }
    else
    {
        selected_format = format.value();
    }
    return Helper::replaceSymbolWithNumber(selected_format);
}

std::string Phone::number(PhoneNumberCountryFormat format)
{
    std::string countryFormat = phoneNumberFormatMap.at(format);

    if(countryFormat.empty())
    {
        return phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);
    }
    return Helper::replaceSymbolWithNumber(countryFormat);


}

std::string Phone::imei()
{
    return Helper::replaceCreditCardSymbols("##-######-######-L", '#');
}

std::map<PhoneNumberCountryFormat, std::string> Phone::createPhoneNumberFormatMap() {
    std::map<PhoneNumberCountryFormat, std::string> formatMap;

    // Loop through all the PhoneNumberCountryFormat enum values
    for (auto i = static_cast<unsigned long>(PhoneNumberCountryFormat::Default); i <= static_cast<unsigned long>(PhoneNumberCountryFormat::Zimbabwe); i++) {
        auto formatEnum = static_cast<PhoneNumberCountryFormat>(i);
        formatMap[formatEnum] = phoneNumbers[i];
    }

    return formatMap;
}
}
