#include "LuhnCheck.h"

namespace faker
{
int LuhnCheck::luhnCheckSum(const std::string& inputString)
{
    std::string modifiedStr = inputString;
    modifiedStr.erase(
        std::remove_if(modifiedStr.begin(), modifiedStr.end(), [](char c) { return std::isspace(c) || c == '-'; }),
        modifiedStr.end());

    int sum = 0;
    bool alternate = false;

    for (std::string::size_type i = modifiedStr.length() - 1; i != std::string::size_type(-1); i--)
    {
        int n = modifiedStr[i] - '0';

        if (alternate)
        {
            n *= 2;
            if (n > 9)
            {
                n = (n % 10) + 1;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    return sum % 10;
}

bool LuhnCheck::luhnCheck(const std::string& inputString)
{
    return luhnCheckSum(inputString) == 0;
}

int LuhnCheck::luhnCheckValue(const std::string& inputString)
{
    int checksum = luhnCheckSum(inputString.substr(0, inputString.length() - 1) + '0');

    return checksum == 0 ? 0 : 10 - checksum;
}
}
