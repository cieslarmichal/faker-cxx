#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

namespace faker
{
    const std::vector<std::string> turkiyeStreetNumberPrefix = {"A-", "B-", "C-", "D-"};

    std::string turkiyeStreetNumber()
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        int randomNumber = std::rand() % 998 + 1;

        std::string randomPrefix = turkiyeStreetNumberPrefix[std::rand() % turkiyeStreetNumberPrefix.size()];

        return randomPrefix + std::to_string(randomNumber);
    }
}