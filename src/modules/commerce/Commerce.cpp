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
    std::string barcode = String::numeric(12, false);

    int sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        sum += (i % 2 == 0) ? (barcode[i] - '0') : 3 * (barcode[i] - '0');
    }
    int checkDigit = (10 - (sum % 10)) % 10;

    return barcode + std::to_string(checkDigit);
}
}
