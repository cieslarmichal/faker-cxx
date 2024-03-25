#include "faker-cxx/Commerce.h"

#include "../../common/FormatHelper.h"
#include "data/Commerce.h"
#include "faker-cxx/Finance.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"

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
    return FormatHelper::format("{} {} {}", productAdjective(), productMaterial(), productName());
}

std::string Commerce::EAN13()
{
    std::string ean13 = String::numeric(12, false);

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
    std::string ean8 = String::numeric(7, false);

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
    std::string isbn13 = String::numeric(12, true);

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
    std::string isbn10 = String::numeric(9, true);

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

std::string Commerce::paymentType()
{
    return Helper::arrayElement<std::string>(paymentTypes);
}

std::string Commerce::paymentProvider()
{
    return Helper::arrayElement<std::string>(paymentProviders);
}

std::string Commerce::productDescription()
{
    return Helper::arrayElement<std::string>(productDescriptions);
}

std::string Commerce::productCategory()
{
    return Helper::arrayElement<std::string>(productCategoryNames);
}

std::string Commerce::productReview()
{
    return Helper::arrayElement<std::string>(productReviews);
}

double Commerce::productRating()
{
    const auto ratingValue = Number::decimal<double>(5.);
    return std::ceil(ratingValue * 100) / 100;
}

std::string Commerce::discountType()
{
    return Helper::arrayElement<std::string>(discountTypes);
}

std::string Commerce::discountCode()
{
    const auto codeLength = Number::integer<unsigned int>(kMinDiscountCodeLength, kMaxDiscountCodeLength);
    return String::alphanumeric(codeLength, StringCasing::Upper);
}

double Commerce::discountAmount()
{
    const auto amountValue = Number::decimal<double>(kMinDiscountAmountValue, kMaxDiscountAmountValue);
    return std::ceil(amountValue * 100) / 100;
}

double Commerce::discountPercentage()
{
    const auto percentageValue = Number::decimal<double>(kMinDiscountPercentageValue, kMaxDiscountPercentageValue);
    return std::ceil(percentageValue * 100) / 100;
}

}
