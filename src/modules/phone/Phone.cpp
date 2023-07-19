#include "faker-cxx/Phone.h"

#include <string>
#include "faker-cxx/Helper.h"
#include "data/PhoneNumbers.h"

namespace faker
{
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

std::string Phone::imei()
{
    return Helper::replaceCreditCardSymbols("##-######-######-L", '#');
}
}
