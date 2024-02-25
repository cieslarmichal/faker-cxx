#include "phone_data.h"
#include <faker/helper.h>
#include <faker/phone.h>
#include <string>
#include <unordered_map>

namespace faker::phone {

std::string number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty()) {
        selectedFormat = Helper::arrayElement<std::string>(data::phoneNumbers);
    } else {
        selectedFormat = format.value();
    }

    return Helper::replaceSymbolWithNumber(selectedFormat);
}

std::unordered_map<PhoneNumberCountryFormat, std::string> createPhoneNumberFormatMap()
{
    std::unordered_map<PhoneNumberCountryFormat, std::string> formatMap;

    // Loop through all the PhoneNumberCountryFormat enum values
    for (auto i = static_cast<unsigned long>(PhoneNumberCountryFormat::Default);
         i <= static_cast<unsigned long>(PhoneNumberCountryFormat::Zimbabwe); i++) {
        auto formatEnum = static_cast<PhoneNumberCountryFormat>(i);

        formatMap[formatEnum] = data::phoneNumbers[i];
    }

    return formatMap;
}

std::string number(PhoneNumberCountryFormat format)
{
    static std::unordered_map<PhoneNumberCountryFormat, std::string> phoneNumberFormatMap
        = createPhoneNumberFormatMap();

    std::string countryFormat = phoneNumberFormatMap.at(format);

    if (countryFormat.empty()) {
        return phoneNumberFormatMap.at(PhoneNumberCountryFormat::Default);
    }

    return Helper::replaceSymbolWithNumber(countryFormat);
}

std::string imei() { return Helper::replaceCreditCardSymbols("##-######-######-L", '#'); }

std::string platform() { return Helper::arrayElement(faker::data::PhonePlatforms); }

std::string modelName() { return Helper::arrayElement(faker::data::PhoneModelNames); }

std::string manufacturer() { return Helper::arrayElement(faker::data::PhoneManufacturers); }

}
