#pragma once

#include <string>
#include "faker-cxx/Export.h"

namespace faker
{
class LuhnCheck
{
public:
    /**
     * @brief Returns luhn checksum value for the given value.
     *
     * @param inputString The string to calculate the check value for.
     *
     * @return The luhn checksum value for the given value.
     *
     */
    FAKER_CXX_EXPORT static int luhnCheckSum(const std::string& inputString);

    /**
     * @brief Checks that the given string passes the luhn algorithm.
     *
     * @param inputString The string to validate.
     *
     * @return Is the string pass the check or not.
     *
     */
    FAKER_CXX_EXPORT static bool luhnCheck(const std::string& inputString);

    /**
     * @brief Returns the luhn check value for the given string.
     *
     * @param inputString The string to calculate the check value for.
     * Should contain the `L` placeholder at the end.
     *
     * @return the luhn check value for the given string.
     *
     */
    FAKER_CXX_EXPORT static int luhnCheckValue(const std::string& inputString);
};
}
