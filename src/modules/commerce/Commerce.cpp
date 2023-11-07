#include "faker-cxx/Commerce.h"

#include "data/Commerce.h"
#include "faker-cxx/Finance.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "fmt/format.h"

namespace faker
{
std::string Commerce::department()
{
    return Helper::arrayElement<std::string>(departments);
}

std::string Commerce::price(double min, double max)
{
    return Finance::amount(min, max);
}

std::string Commerce::sku(unsigned int length)
{
    return String::numeric(length, false);
}

std::string Commerce::productAdjective()
{
    return Helper::arrayElement<std::string>(productAdjectives);
}

std::string Commerce::productMaterial()
{
    return Helper::arrayElement<std::string>(productMaterials);
}

std::string Commerce::productName()
{
    return Helper::arrayElement<std::string>(productNames);
}

std::string Commerce::productFullName()
{
    return fmt::format("{} {} {}", productAdjective(), productMaterial(), productName());
}

std::string EAN13()
{
    std::string ean13 = String::numeric(12, false);

    int sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        sum += (i % 2 == 0) ? (ean13[i] - '0') : 3 * (ean13[i] - '0');
    }
    
    int checkDigit = 10 - (sum % 10);

    return ean13 + std::to_string(checkDigit);
}

std::string EAN8()
{
    std::string ean8 = String::numeric(7, false);

    int sum = 0;
    for (size_t i = 0; i < 7; i++)
    {
        sum += (i % 2 == 0) ? (ean8[i] - '0') : 3 * (ean8[i] - '0');
    }
    
    int checkDigit = 10 - (sum % 10);

    return ean8 + std::to_string(checkDigit);
}

std::string ISBN13()
{
    std::string isbn13 = String::numeric(12, true);

    int sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        sum += (i % 2 == 0) ? (isbn13[i] - '0') : 3 * (isbn13[i] - '0');
    }
    
    int checkDigit = 10 - (sum % 10);

    return isbn13 + std::to_string(checkDigit);
}

std::string ISBN10()
{
    std::string isbn10 = String::numeric(9, true);

    int sum = 0, weight = 10;
    for (size_t i = 0; i < 9; i++)
    {
        sum += isbn10[i] * weight;
        weight--;
    }
    
    int checkDigit = 10 - (sum % 10);

    return isbn10 + std::to_string(checkDigit);
}
}
