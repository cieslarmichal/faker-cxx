#include "../test_helpers.h"
#include <algorithm>
#include <charconv>
#include <common/string_helper.h>
#include <faker/commerce.h>
#include <modules/commerce_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

class CommerceTest : public Test {
public:
};

TEST_F(CommerceTest, shouldGenerateCommerceDepartment)
{
    const auto generatedDepartment = commerce::department();

    ASSERT_TRUE(faker::testing::contains(departments, generatedDepartment));
}

TEST_F(CommerceTest, shouldGeneratePrice)
{
    const auto generatedPrice = commerce::price(100, 10000);

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
    const auto sku = commerce::sku();

    ASSERT_EQ(sku.size(), 4);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(numericCharacters,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST_F(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    const auto skuLength = 8;

    const auto sku = commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(numericCharacters,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST_F(CommerceTest, shouldGenerateProductFullName)
{
    const auto productFullName = commerce::productFullName();

    const auto productFullNameElements = StringHelper::split(productFullName, " ");

    const auto& generatedProductAdjective = productFullNameElements[0];
    const auto& generatedProductMaterial = productFullNameElements[1];
    const auto& generatedProductName = productFullNameElements[2];

    ASSERT_TRUE(faker::testing::contains(productAdjectives, generatedProductAdjective));
    ASSERT_TRUE(faker::testing::contains(productMaterials, generatedProductMaterial));
    ASSERT_TRUE(faker::testing::contains(productNames, generatedProductName));
}

TEST_F(CommerceTest, shouldGenerateProductAdjective)
{
    const auto generatedProductAdjective = commerce::productAdjective();

    ASSERT_TRUE(faker::testing::contains(productAdjectives, generatedProductAdjective));
}

TEST_F(CommerceTest, shouldGenerateProductMaterial)
{
    const auto generatedProductMaterial = commerce::productMaterial();

    ASSERT_TRUE(faker::testing::contains(productMaterials, generatedProductMaterial));
}

TEST_F(CommerceTest, shouldGenerateProductName)
{
    const auto generatedProductName = commerce::productName();

    ASSERT_TRUE(faker::testing::contains(productNames, generatedProductName));
}

TEST_F(CommerceTest, shouldGenerateEan13)
{
    const auto generatedEan13 = commerce::EAN13();

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

TEST_F(CommerceTest, shouldGenerateEan8)
{
    const auto generatedEan8 = commerce::EAN8();

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

TEST_F(CommerceTest, shouldGenerateIsbn13)
{
    const auto generatedIsbn13 = commerce::ISBN13();

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

TEST_F(CommerceTest, shouldGenerateIsbn10)
{
    const auto generatedIsbn10 = commerce::ISBN10();

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

TEST_F(CommerceTest, shouldGenerateProductId)
{
    const auto generatedProductId = commerce::productId();

    ASSERT_EQ(generatedProductId.length(), 10);
    ASSERT_TRUE(
        faker::testing::all_of(generatedProductId, [](const char& c) { return std::isalnum(c); }));
}

TEST_F(CommerceTest, shouldGeneratePaymentType)
{
    const auto generatedPaymentType = commerce::paymentType();

    ASSERT_TRUE(faker::testing::contains(paymentTypes, generatedPaymentType));
}

TEST_F(CommerceTest, shouldGeneratePaymentProvider)
{
    const auto generatedPaymentProvider = commerce::paymentProvider();

    ASSERT_TRUE(faker::testing::contains(paymentProviders, generatedPaymentProvider));
}

TEST_F(CommerceTest, shouldGenerateProductDescription)
{
    const auto generatedProductDescription = commerce::productDescription();

    ASSERT_TRUE(faker::testing::contains(productDescriptions, generatedProductDescription));
}

TEST_F(CommerceTest, shouldGenerateProductCategory)
{
    const auto generatedProductCategory = commerce::productCategory();

    ASSERT_TRUE(faker::testing::contains(productCategoryNames, generatedProductCategory));
}

TEST_F(CommerceTest, shouldGenerateProductReview)
{
    const auto generatedProductReview = commerce::productReview();

    ASSERT_TRUE(faker::testing::contains(productReviews, generatedProductReview));
}

TEST_F(CommerceTest, shouldGenerateProductRating)
{
    const auto generatedProductRating = commerce::productRating();

    ASSERT_TRUE(0. <= generatedProductRating && generatedProductRating <= 5.);
}

TEST_F(CommerceTest, shouldGenerateDiscountType)
{
    const auto generatedDiscountType = commerce::discountType();

    ASSERT_TRUE(faker::testing::contains(discountTypes, generatedDiscountType));
}

TEST_F(CommerceTest, shouldGenerateDiscountCode)
{

    const auto generatedDiscountCode = commerce::discountCode();

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

TEST_F(CommerceTest, shouldGenerateDiscountAmount)
{
    const auto generatedDiscountAmount = commerce::discountAmount();

    ASSERT_TRUE(kMinDiscountAmountValue <= generatedDiscountAmount
        && generatedDiscountAmount <= kMaxDiscountAmountValue);
}

TEST_F(CommerceTest, shouldGenerateDiscountPercentage)
{
    const auto generatedDiscountPercentage = commerce::discountPercentage();

    ASSERT_TRUE(kMinDiscountPercentageValue <= generatedDiscountPercentage
        && generatedDiscountPercentage <= kMaxDiscountPercentageValue);
}
