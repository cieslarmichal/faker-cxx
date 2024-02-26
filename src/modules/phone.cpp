#include "../common/helper.h"
#include "phone_data.h"
#include <faker/phone.h>
#include <string>
#include <unordered_map>

namespace faker::phone {

std::string number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty()) {
        selectedFormat = Helper::arrayElement(data::number_formats);
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

        formatMap[formatEnum] = data::number_formats[i];
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

std::string_view platform() { return Helper::arrayElement(data::platforms); }

std::string_view model_name() { return Helper::arrayElement(data::model_names); }

std::string_view manufacturer() { return Helper::arrayElement(data::manufacturers); }

}
