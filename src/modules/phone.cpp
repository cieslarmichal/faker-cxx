#include "../common/random.h"
#include "phone_data.h"
#include <faker/phone.h>
#include <string>
#include <unordered_map>

namespace faker::phone {

std::string number(std::optional<std::string> format)
{
    std::string selectedFormat;

    if (!format.has_value() || format->empty()) {
        selectedFormat = random::element(data::number_formats);
    } else {
        selectedFormat = format.value();
    }

    return random::replace_symbol_with_number(selectedFormat);
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

    return random::replace_symbol_with_number(countryFormat);
}

std::string imei() { return random::replace_credit_card_symbols("##-######-######-L", '#'); }

std::string_view platform() { return random::element(data::platforms); }

std::string_view model_name() { return random::element(data::model_names); }

std::string_view manufacturer() { return random::element(data::manufacturers); }

}
