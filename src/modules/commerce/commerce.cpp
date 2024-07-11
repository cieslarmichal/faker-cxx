#include "faker-cxx/commerce.h"

#include <string>
#include <string_view>

#include "common/format_helper.h"
#include "commerce_data.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/string.h"

namespace faker::commerce
{
std::string_view department()
{
    return helper::arrayElement(departments);
}

std::string sku(unsigned int length)
{
    return string::numeric(length, false);
}

std::string_view productAdjective()
{
    return helper::arrayElement(productAdjectives);
}

std::string_view productMaterial()
{
    return helper::arrayElement(productMaterials);
}

std::string_view productName()
{
    return helper::arrayElement(productNames);
}

std::string productFullName()
{
    return common::format("{} {} {}", productAdjective(), productMaterial(), productName());
}

std::string EAN13()
{
    const auto ean13 = string::numeric(12, false);

    int sum = 0;

    for (size_t i = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            sum += (ean13[i] - '0');
        }
        else
        {
            sum += 3 * (ean13[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0)
    {
        checkDigit = 10 - checkDigit;
    }

    return ean13 + std::to_string(checkDigit);
}

std::string EAN8()
{
    const auto ean8 = string::numeric(7, false);

    int sum = 0;

    for (size_t i = 0; i < 7; i++)
    {
        if (i % 2 == 0)
        {
            sum += 3 * (ean8[i] - '0');
        }
        else
        {
            sum += (ean8[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0)
    {
        checkDigit = 10 - checkDigit;
    }

    return ean8 + std::to_string(checkDigit);
}

std::string ISBN13()
{
    const auto isbn13 = string::numeric(12, true);

    int sum = 0;

    for (size_t i = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            sum += (isbn13[i] - '0');
        }
        else
        {
            sum += 3 * (isbn13[i] - '0');
        }
    }

    int checkDigit = sum % 10;

    if (checkDigit != 0)
    {
        checkDigit = 10 - checkDigit;
    }

    return isbn13 + std::to_string(checkDigit);
}

std::string ISBN10()
{
    const auto isbn10 = string::numeric(9, true);

    int sum = 0, weight = 10;

    for (size_t i = 0; i < 9; i++)
    {
        sum += (isbn10[i] - '0') * weight;
        weight--;
    }

    int checkDigit = sum % 11;

    if (checkDigit != 0)
    {
        checkDigit = 11 - checkDigit;
    }

    if (checkDigit == 10)
    {
        return isbn10 + "X";
    }

    return isbn10 + std::to_string(checkDigit);
}

std::string_view paymentType()
{
    return helper::arrayElement(paymentTypes);
}

std::string_view paymentProvider()
{
    return helper::arrayElement(paymentProviders);
}

std::string_view productDescription()
{
    return helper::arrayElement(productDescriptions);
}

std::string_view productCategory()
{
    return helper::arrayElement(productCategoryNames);
}

std::string_view productReview()
{
    return helper::arrayElement(productReviews);
}

std::string_view discountType()
{
    return helper::arrayElement(discountTypes);
}

std::string_view orderStatus()
{
    return helper::arrayElement(orderStatuses);
}

std::string_view shippingCarrier()
{
    return helper::arrayElement(shippingCarriers);
}

}
