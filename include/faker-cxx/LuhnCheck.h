#pragma once

#include <string>
#include <algorithm>

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
    static int luhnCheckSum(const std::string& inputString) {
        std::string modifiedStr = inputString;
        modifiedStr.erase(std::remove_if(modifiedStr.begin(), modifiedStr.end(),
                                         [](char c) { return std::isspace(c) || c == '-'; }), modifiedStr.end());

        int sum = 0;
        bool alternate = false;

        for (std::string::size_type i = modifiedStr.length() - 1; i != std::string::size_type(-1); i--) {
            int n = modifiedStr[i] - '0';

            if (alternate) {
                n *= 2;
                if (n > 9) {
                    n = (n % 10) + 1;
                }
            }

            sum += n;
            alternate = !alternate;
        }

        return sum % 10;
    }

    /**
     * @brief Checks that the given string passes the luhn algorithm.
     *
     * @param inputString The string to validate.
     *
     * @return Is the string pass the check or not.
     *
     */
    static bool luhnCheck(const std::string& inputString) {
        return luhnCheckSum(inputString) == 0;
    }

    /**
     * @brief Returns the luhn check value for the given string.
     *
     * @param inputString The string to calculate the check value for.
     * Should contain the `L` placeholder at the end.
     *
     * @return the luhn check value for the given string.
     *
     */
    static int luhnCheckValue(const std::string& inputString)
    {
        int checksum = luhnCheckSum(inputString.substr(0, inputString.length() - 1) + '0');
        return checksum == 0 ? 0 : 10 - checksum;
    }
};
}
