#pragma once

#include <optional>
#include <string>

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
     static std::string number(std::optional<std::string>  = std::nullopt);

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
};
}
