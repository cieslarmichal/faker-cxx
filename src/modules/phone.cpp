#include "../common/random.h"
#include "phone_data.h"
#include <faker/phone.h>
#include <string>
#include <unordered_map>

namespace faker::phone {

std::string number(std::optional<std::string> format)
{
    return random::replace_symbol_with_number(
        format.has_value() ? *format : random::element(data::number_formats).second);
}

std::string number(phone_number_format_t format)
{
    auto final_format = data::number_formats.at(static_cast<size_t>(format));
    if (final_format.first != format) {
        throw std::runtime_error("Invalid phone number format");
    }
    return random::replace_symbol_with_number(final_format.second);
}

std::string imei() { return random::replace_credit_card_symbols("##-######-######-L", '#'); }

std::string_view platform() { return random::element(data::platforms); }

std::string_view model_name() { return random::element(data::model_names); }

std::string_view manufacturer() { return random::element(data::manufacturers); }

}
