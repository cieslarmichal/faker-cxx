#pragma once

#include <faker/types/phone_number_country_format.h>
#include <optional>
#include <string>

namespace faker::phone {
/**
 * @brief Returns a random phone number.
 *
 * @param string The optional string to use.
 *
 * @returns Random phone number.
 *
 * @code
 * phone::number() // "961-770-7727"
 * phone::number("501-###-###") // "501-039-841"
 * phone::number("+48 91 ### ## ##") // "+48 91 463 61 70"
 * @endcode
 */
std::string number(std::optional<std::string> = std::nullopt);

/**
 * @brief Returns a random phone platform.
 *
 * @returns Random phone platform.
 *
 * @code
 * phone::platform() // "iOS"
 * @endcode
 */
std::string platform();

/**
 * @brief Returns a random phone model.
 *
 * @returns Random phone model.
 *
 * @code
 * phone::modelName() // "Samsung Galaxy S22"
 * @endcode
 */
std::string modelName();

/**
 * @brief Returns a random phone manufacturer.
 *
 * @returns Random phone manufacturer.
 *
 * @code
 * phone::manufacturer() // "Sony"
 * @endcode
 */
std::string manufacturer();

/**
 * @brief Returns a random phone number based on country phone number template.
 *
 * @param format Enum country format, more details in PhoneNumberCountryFormat.h.
 *
 * @returns Random phone number based on country phone number template.
 *
 * @code
 * phone::number(PhoneNumberCountryFormat::Usa) // "+1 (395) 714-1494"
 * @endcode
 */
std::string number(PhoneNumberCountryFormat format);

/**
 * @brief Returns IMEI number.
 *
 * @returns IMEI number.
 *
 * @code
 * phone::imei() // "13-850175-913761-7"
 * @endcode
 */
std::string imei();
}
