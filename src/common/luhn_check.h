#ifndef FAKER_COMMON_LUHN_CHECK_H
#define FAKER_COMMON_LUHN_CHECK_H

#include <algorithm>
#include <string>

namespace faker {
class LuhnCheck {
public:
    /**
     * @brief Returns luhn checksum value for the given value.
     *
     * @param inputString The string to calculate the check value for.
     *
     * @return The luhn checksum value for the given value.
     *
     */
    static int luhnCheckSum(const std::string& inputString);

    /**
     * @brief Checks that the given string passes the luhn algorithm.
     *
     * @param inputString The string to validate.
     *
     * @return Is the string pass the check or not.
     *
     */
    static bool luhnCheck(const std::string& inputString);

    /**
     * @brief Returns the luhn check value for the given string.
     *
     * @param inputString The string to calculate the check value for.
     * Should contain the `L` placeholder at the end.
     *
     * @return the luhn check value for the given string.
     *
     */
    static int luhnCheckValue(const std::string& inputString);
};
}

#endif