#include "faker-cxx/Commerce.h"

#include <cmath>
#include <cstddef>
#include <string>
#include <string_view>

#include "../../common/FormatHelper.h"
#include "CommerceData.h"
#include "faker-cxx/Finance.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string_view Commerce::department()
{
    return Helper::arrayElement(departments);
}

std::string Commerce::price(double min, double max)
{
    return Finance::amount(min, max);
}

std::string Commerce::sku(unsigned int length)
{
    return String::numeric(length, false);
}

std::string_view Commerce::productAdjective()
{
    return Helper::arrayElement(productAdjectives);
}

std::string_view Commerce::productMaterial()
{
    return Helper::arrayElement(productMaterials);
}

std::string_view Commerce::productName()
{
    return Helper::arrayElement(productNames);
}

std::string Commerce::productFullName()
{
    return FormatHelper::format("{} {} {}", productAdjective(), productMaterial(), productName());
}

std::string Commerce::EAN13()
{
    const auto ean13 = String::numeric(12, false);

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

std::string Commerce::EAN8()
{
    const auto ean8 = String::numeric(7, false);

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

std::string Commerce::ISBN13()
{
    const auto isbn13 = String::numeric(12, true);

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

std::string Commerce::ISBN10()
{
    const auto isbn10 = String::numeric(9, true);

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

std::string Commerce::productId()
{
    return String::alphanumeric(10, StringCasing::Upper, "");
}

std::string_view Commerce::paymentType()
{
    return Helper::arrayElement(paymentTypes);
}

std::string_view Commerce::paymentProvider()
{
    return Helper::arrayElement(paymentProviders);
}

std::string_view Commerce::productDescription()
{
    return Helper::arrayElement(productDescriptions);
}

std::string_view Commerce::productCategory()
{
    return Helper::arrayElement(productCategoryNames);
}

std::string_view Commerce::productReview()
{
    return Helper::arrayElement(productReviews);
}

double Commerce::productRating()
{
    const std::floating_point auto ratingValue = Number::decimal<double>(5.);
    return std::ceil(ratingValue * 100) / 100;
}

std::string_view Commerce::discountType()
{
    return Helper::arrayElement(discountTypes);
}

std::string Commerce::discountCode()
{
    const std::integral auto codeLength = Number::integer<unsigned int>(minDiscountCodeLength, maxDiscountCodeLength);

    return String::alphanumeric(codeLength, StringCasing::Upper);
}

double Commerce::discountAmount()
{
    const std::floating_point auto amountValue = Number::decimal<double>(minDiscountAmount, maxDiscountAmount);

    return std::ceil(amountValue * 100) / 100;
}

double Commerce::discountPercentage()
{
    const std::floating_point auto percentageValue =
        Number::decimal<double>(minDiscountPercentage, maxDiscountPercentage);

    return std::ceil(percentageValue * 100) / 100;
}

std::string Commerce::orderNumber()
{
    return String::numeric(7, true);
}

std::string_view Commerce::orderStatus()
{
    return Helper::arrayElement(orderStatuses);
}

std::string_view Commerce::shippingCarrier()
{
    return Helper::arrayElement(shippingCarriers);
}

}
