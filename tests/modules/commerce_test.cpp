#include "../test_helpers.h"
#include <charconv>
#include <common/string_helper.h>
#include <faker/commerce.h>
#include <modules/commerce_data.h>
#include <modules/string_data.h>

using namespace faker;

TEST(CommerceTest, shouldGenerateCommerceDepartment)
{
    auto generatedDepartment = commerce::department();

    FAKER_EXPECT_CONTAINS(departments, generatedDepartment);
}

TEST(CommerceTest, shouldGeneratePrice)
{
    auto generatedPrice = commerce::price(100, 10000);

    auto offset = generatedPrice.size();
    auto priceAsFloat = std::stof(generatedPrice.data(), &offset);

    auto generatedPriceElements = StringHelper::split(generatedPrice, ".");

    ASSERT_EQ(generatedPriceElements.size(), 2);
    ASSERT_EQ(generatedPriceElements[1].size(), 2);
    ASSERT_GE(priceAsFloat, 100);
    ASSERT_LE(priceAsFloat, 10000);
}

TEST(CommerceTest, shouldGenerateSku)
{
    auto sku = commerce::sku();

    ASSERT_EQ(sku.size(), 4);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(numericCharacters,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    auto skuLength = 8;

    auto sku = commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(numericCharacters,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateProductFullName)
{
    auto productFullName = commerce::productFullName();

    auto productFullNameElements = StringHelper::split(productFullName, " ");

    auto& generatedProductAdjective = productFullNameElements[0];
    auto& generatedProductMaterial = productFullNameElements[1];
    auto& generatedProductName = productFullNameElements[2];

    FAKER_EXPECT_CONTAINS(productAdjectives, generatedProductAdjective);
    FAKER_EXPECT_CONTAINS(productMaterials, generatedProductMaterial);
    FAKER_EXPECT_CONTAINS(productNames, generatedProductName);
}

TEST(CommerceTest, shouldGenerateProductAdjective)
{
    auto generatedProductAdjective = commerce::productAdjective();

    FAKER_EXPECT_CONTAINS(productAdjectives, generatedProductAdjective);
}

TEST(CommerceTest, shouldGenerateProductMaterial)
{
    auto generatedProductMaterial = commerce::productMaterial();

    FAKER_EXPECT_CONTAINS(productMaterials, generatedProductMaterial);
}

TEST(CommerceTest, shouldGenerateProductName)
{
    auto generatedProductName = commerce::productName();

    FAKER_EXPECT_CONTAINS(productNames, generatedProductName);
}

TEST(CommerceTest, shouldGenerateEan13)
{
    auto generatedEan13 = commerce::EAN13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += (generatedEan13[i] - '0');
        } else {
            sum += 3 * (generatedEan13[i] - '0');
        }
    }

    ASSERT_EQ(generatedEan13.size(), 13);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, shouldGenerateEan8)
{
    auto generatedEan8 = commerce::EAN8();

    int sum = 0;
    for (size_t i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            sum += 3 * (generatedEan8[i] - '0');
        } else {
            sum += (generatedEan8[i] - '0');
        }
    }

    ASSERT_EQ(generatedEan8.size(), 8);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, shouldGenerateIsbn13)
{
    auto generatedIsbn13 = commerce::ISBN13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += (generatedIsbn13[i] - '0');
        } else {
            sum += 3 * (generatedIsbn13[i] - '0');
        }
    }

    ASSERT_EQ(generatedIsbn13.size(), 13);
    ASSERT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, shouldGenerateIsbn10)
{
    auto generatedIsbn10 = commerce::ISBN10();

    int sum = 0, weight = 10;
    if (generatedIsbn10[9] == 'X') {
        for (size_t i = 0; i < 9; i++) {
            sum += (generatedIsbn10[i] - '0') * weight;
            weight--;
        }
        sum += 10;
    } else {
        for (size_t i = 0; i < 10; i++) {
            sum += (generatedIsbn10[i] - '0') * weight;
            weight--;
        }
    }

    ASSERT_EQ(generatedIsbn10.size(), 10);
    ASSERT_TRUE(sum % 11 == 0);
}

TEST(CommerceTest, shouldGenerateProductId)
{
    auto generatedProductId = commerce::productId();

    ASSERT_EQ(generatedProductId.length(), 10);
    ASSERT_TRUE(
        faker::testing::all_of(generatedProductId, [](const char& c) { return std::isalnum(c); }));
}

TEST(CommerceTest, shouldGeneratePaymentType)
{
    auto generatedPaymentType = commerce::paymentType();

    FAKER_EXPECT_CONTAINS(paymentTypes, generatedPaymentType);
}

TEST(CommerceTest, shouldGeneratePaymentProvider)
{
    auto generatedPaymentProvider = commerce::paymentProvider();

    FAKER_EXPECT_CONTAINS(paymentProviders, generatedPaymentProvider);
}

TEST(CommerceTest, shouldGenerateProductDescription)
{
    auto generatedProductDescription = commerce::productDescription();

    FAKER_EXPECT_CONTAINS(productDescriptions, generatedProductDescription);
}

TEST(CommerceTest, shouldGenerateProductCategory)
{
    auto generatedProductCategory = commerce::productCategory();

    FAKER_EXPECT_CONTAINS(productCategoryNames, generatedProductCategory);
}

TEST(CommerceTest, shouldGenerateProductReview)
{
    auto generatedProductReview = commerce::productReview();

    FAKER_EXPECT_CONTAINS(productReviews, generatedProductReview);
}

TEST(CommerceTest, shouldGenerateProductRating)
{
    auto generatedProductRating = commerce::productRating();

    ASSERT_TRUE(0. <= generatedProductRating && generatedProductRating <= 5.);
}

TEST(CommerceTest, shouldGenerateDiscountType)
{
    auto generatedDiscountType = commerce::discountType();

    FAKER_EXPECT_CONTAINS(discountTypes, generatedDiscountType);
}

TEST(CommerceTest, shouldGenerateDiscountCode)
{

    auto generatedDiscountCode = commerce::discountCode();

    ASSERT_TRUE(kMinDiscountCodeLength <= generatedDiscountCode.length()
        && generatedDiscountCode.length() <= kMaxDiscountCodeLength);

    ASSERT_TRUE(
        faker::testing::all_of(generatedDiscountCode, [](char generatedDiscountCodeCharacter) {
            return faker::testing::any_of(upperAlphanumericCharacters,
                [generatedDiscountCodeCharacter](char upperAlphanumericCharacter) {
                    return upperAlphanumericCharacter == generatedDiscountCodeCharacter;
                });
        }));
}

TEST(CommerceTest, shouldGenerateDiscountAmount)
{
    auto generatedDiscountAmount = commerce::discountAmount();

    ASSERT_TRUE(kMinDiscountAmountValue <= generatedDiscountAmount
        && generatedDiscountAmount <= kMaxDiscountAmountValue);
}

TEST(CommerceTest, shouldGenerateDiscountPercentage)
{
    auto generatedDiscountPercentage = commerce::discountPercentage();

    ASSERT_TRUE(kMinDiscountPercentageValue <= generatedDiscountPercentage
        && generatedDiscountPercentage <= kMaxDiscountPercentageValue);
}
