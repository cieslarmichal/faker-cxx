#pragma once

#include <map>
#include <optional>
#include <string>

#include "types/PhoneNumberCountryFormat.h"

namespace faker
{
class Phone
{
public:
    /**
     * @brief Returns a random phone number.
     *
     * @param string The optional string to use.
     *
     * @returns Random phone number.
     *
     * @code
     * Phone::number() // "961-770-7727"
     * Phone::number("501-###-###") // "501-039-841"
     * Phone::number("+48 91 ### ## ##") // "+48 91 463 61 70"
     * @endcode
     */
    static std::string number(std::optional<std::string> = std::nullopt);
    static std::string platform();
    static std::string modelName();
    static std::string manufacturer();

    /**
     * @brief Returns a random phone number based on country phone number template.
     *
     * @param format Enum country format, more details in PhoneNumberCountryFormat.h.
     *
     * @returns Random phone number based on country phone number template.
     *
     * @code
     * Phone::number(PhoneNumberCountryFormat::Usa) // "+1 (395) 714-1494"
     * @endcode
     */
    static std::string number(PhoneNumberCountryFormat format);

    /**
     * @brief Returns IMEI number.
     *
     * @returns IMEI number.
     *
     * @code
     * Phone::imei() // "13-850175-913761-7"
     * @endcode
     */
    static std::string imei();

private:
    static std::map<PhoneNumberCountryFormat, std::string> createPhoneNumberFormatMap();
    static std::map<PhoneNumberCountryFormat, std::string> phoneNumberFormatMap;
};
}
