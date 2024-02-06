#include "faker-cxx/Commerce.h"

#include <algorithm>
#include <charconv>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../string/data/Characters.h"
#include "data/Commerce.h"

using namespace ::testing;
using namespace faker;

class CommerceTest : public Test
{
public:
};

TEST_F(CommerceTest, shouldGenerateCommerceDepartment)
{
    const auto generatedDepartment = Commerce::department();

    ASSERT_TRUE(std::ranges::any_of(departments, [generatedDepartment](const std::string& department)
                                    { return department == generatedDepartment; }));
}

TEST_F(CommerceTest, shouldGeneratePrice)
{
    const auto generatedPrice = Commerce::price(100, 10000);

    auto offset = generatedPrice.size();
    const auto priceAsFloat = std::stof(generatedPrice.data(), &offset);

    const auto generatedPriceElements = StringHelper::split(generatedPrice, ".");

    ASSERT_EQ(generatedPriceElements.size(), 2);
    ASSERT_EQ(generatedPriceElements[1].size(), 2);
    ASSERT_GE(priceAsFloat, 100);
    ASSERT_LE(priceAsFloat, 10000);
}

TEST_F(CommerceTest, shouldGenerateSku)
{
    const auto sku = Commerce::sku();

    ASSERT_EQ(sku.size(), 4);
    ASSERT_TRUE(std::ranges::all_of(sku,
                                    [](char skuCharacter)
                                    {
                                        return std::ranges::any_of(numericCharacters,
                                                                   [skuCharacter](char numericCharacter)
                                                                   { return skuCharacter == numericCharacter; });
                                    }));
}

TEST_F(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    const auto skuLength = 8;

    const auto sku = Commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(std::ranges::all_of(sku,
                                    [](char skuCharacter)
                                    {
                                        return std::ranges::any_of(numericCharacters,
                                                                   [skuCharacter](char numericCharacter)
                                                                   { return skuCharacter == numericCharacter; });
                                    }));
}

TEST_F(CommerceTest, shouldGenerateProductFullName)
{
    const auto productFullName = Commerce::productFullName();

    const auto productFullNameElements = StringHelper::split(productFullName, " ");

    const auto& generatedProductAdjective = productFullNameElements[0];
    const auto& generatedProductMaterial = productFullNameElements[1];
    const auto& generatedProductName = productFullNameElements[2];

    ASSERT_TRUE(std::ranges::any_of(productAdjectives, [generatedProductAdjective](const std::string& adjective)
                                    { return adjective == generatedProductAdjective; }));
    ASSERT_TRUE(std::ranges::any_of(productMaterials, [generatedProductMaterial](const std::string& material)
                                    { return material == generatedProductMaterial; }));
    ASSERT_TRUE(std::ranges::any_of(productNames, [generatedProductName](const std::string& productName)
                                    { return productName == generatedProductName; }));
}

TEST_F(CommerceTest, shouldGenerateProductAdjective)
{
    const auto generatedProductAdjective = Commerce::productAdjective();

    ASSERT_TRUE(std::ranges::any_of(productAdjectives, [generatedProductAdjective](const std::string& adjective)
                                    { return adjective == generatedProductAdjective; }));
}

TEST_F(CommerceTest, shouldGenerateProductMaterial)
{
    const auto generatedProductMaterial = Commerce::productMaterial();

    ASSERT_TRUE(std::ranges::any_of(productMaterials, [generatedProductMaterial](const std::string& material)
                                    { return material == generatedProductMaterial; }));
}

TEST_F(CommerceTest, shouldGenerateProductName)
{
    const auto generatedProductName = Commerce::productName();

    ASSERT_TRUE(std::ranges::any_of(productNames, [generatedProductName](const std::string& productName)
                                    { return productName == generatedProductName; }));
}

TEST_F(CommerceTest, shouldGenerateEan13)
{
    const auto generatedEan13 = Commerce::EAN13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++)
    {
        if (i % 2 == 0)
        {
            sum += (generatedEan13[i] - '0');
        }
        else
        {
            sum += 3 * (generatedEan13[i] - '0');
        }
    }

    ASSERT_EQ(generatedEan13.size(), 13);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST_F(CommerceTest, shouldGenerateEan8)
{
    const auto generatedEan8 = Commerce::EAN8();

    int sum = 0;
    for (size_t i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            sum += 3 * (generatedEan8[i] - '0');
        }
        else
        {
            sum += (generatedEan8[i] - '0');
        }
    }

    ASSERT_EQ(generatedEan8.size(), 8);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST_F(CommerceTest, shouldGenerateIsbn13)
{
    const auto generatedIsbn13 = Commerce::ISBN13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++)
    {
        if (i % 2 == 0)
        {
            sum += (generatedIsbn13[i] - '0');
        }
        else
        {
            sum += 3 * (generatedIsbn13[i] - '0');
        }
    }

    ASSERT_EQ(generatedIsbn13.size(), 13);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST_F(CommerceTest, shouldGenerateIsbn10)
{
    const auto generatedIsbn10 = Commerce::ISBN10();

    int sum = 0, weight = 10;
    if (generatedIsbn10[9] == 'X')
    {
        for (size_t i = 0; i < 9; i++)
        {
            sum += (generatedIsbn10[i] - '0') * weight;
            weight--;
        }
        sum += 10;
    }
    else
    {
        for (size_t i = 0; i < 10; i++)
        {
            sum += (generatedIsbn10[i] - '0') * weight;
            weight--;
        }
    }

    ASSERT_EQ(generatedIsbn10.size(), 10);
    ASSERT_TRUE(sum % 11 == 0);
}

TEST_F(CommerceTest, shouldGenerateProductId)
{
    const auto generatedProductId = Commerce::productId();  

    ASSERT_EQ(generatedProductId.length(), 10);
    ASSERT_TRUE(std::ranges::all_of(generatedProductId, [](const char& c) { return std::isalnum(c); }));
}

TEST_F(CommerceTest, shouldGeneratePaymentType)
{
    const auto generatedPaymentType = Commerce::paymentType();

    ASSERT_TRUE(std::ranges::any_of(paymentTypes, [generatedPaymentType](const std::string& paymentType)
                                    { return paymentType == generatedPaymentType; }));
}

TEST_F(CommerceTest, shouldGeneratePaymentProvider)
{
    const auto generatedPaymentProvider = Commerce::paymentProvider();

    ASSERT_TRUE(std::ranges::any_of(paymentProviders, [generatedPaymentProvider](const std::string& paymentProvider)
                                    { return paymentProvider == generatedPaymentProvider; }));
}

TEST_F(CommerceTest, shouldGenerateProductDescription)
{
    const auto generatedProductDescription = Commerce::productDescription();

    ASSERT_TRUE(std::ranges::any_of(productDescriptions, [generatedProductDescription](const std::string& productDescription)
                                    { return productDescription == generatedProductDescription; }));
}

TEST_F(CommerceTest, shouldGenerateProductCategory)
{
    const auto generatedProductCategory = Commerce::productCategory();

    ASSERT_TRUE(std::ranges::any_of(productCategoryNames, [generatedProductCategory](const std::string& productCategory)
                                    { return productCategory == generatedProductCategory; }));
}

TEST_F(CommerceTest, shouldGenerateProductReview)
{
    const auto generatedProductReview = Commerce::productReview();

    ASSERT_TRUE(std::ranges::any_of(productReviews, [generatedProductReview](const std::string& productReview)
                                    { return productReview == generatedProductReview; }));
}

TEST_F(CommerceTest, shouldGenerateProductRating)
{
    const auto generatedProductRating = Commerce::productRating();

    ASSERT_TRUE(0. <= generatedProductRating && generatedProductRating <= 5.);
}
