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

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::departments, generatedDepartment);
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
        return faker::testing::any_of(string::data::numericCharacters,
            [skuCharacter](auto numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    auto skuLength = 8;

    auto sku = commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(string::data::numericCharacters,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateProductFullName)
{
    auto productFullName = commerce::product_full_name();

    auto productFullNameElements = StringHelper::split(productFullName, " ");

    auto& generatedProductAdjective = productFullNameElements[0];
    auto& generatedProductMaterial = productFullNameElements[1];
    auto& generatedProductName = productFullNameElements[2];

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productAdjectives, generatedProductAdjective);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productMaterials, generatedProductMaterial);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productNames, generatedProductName);
}

TEST(CommerceTest, shouldGenerateProductAdjective)
{
    auto generatedProductAdjective = commerce::product_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productAdjectives, generatedProductAdjective);
}

TEST(CommerceTest, shouldGenerateProductMaterial)
{
    auto generatedProductMaterial = commerce::product_material();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productMaterials, generatedProductMaterial);
}

TEST(CommerceTest, shouldGenerateProductName)
{
    auto generatedProductName = commerce::product_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productNames, generatedProductName);
}

TEST(CommerceTest, shouldGenerateEan13)
{
    auto generatedEan13 = commerce::ean13();

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
    auto generatedEan8 = commerce::ean8();

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
    auto generatedIsbn13 = commerce::isbn13();

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
    auto generatedIsbn10 = commerce::isbn10();

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
    auto generatedProductId = commerce::product_id();

    ASSERT_EQ(generatedProductId.length(), 10);
    ASSERT_TRUE(faker::testing::all_of(generatedProductId, [](auto c) { return std::isalnum(c); }));
}

TEST(CommerceTest, shouldGeneratePaymentType)
{
    auto generatedPaymentType = commerce::payment_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::paymentTypes, generatedPaymentType);
}

TEST(CommerceTest, shouldGeneratePaymentProvider)
{
    auto generatedPaymentProvider = commerce::payment_provider();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::paymentProviders, generatedPaymentProvider);
}

TEST(CommerceTest, shouldGenerateProductDescription)
{
    auto generatedProductDescription = commerce::product_description();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        commerce::data::productDescriptions, generatedProductDescription);
}

TEST(CommerceTest, shouldGenerateProductCategory)
{
    auto generatedProductCategory = commerce::product_category();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productCategoryNames, generatedProductCategory);
}

TEST(CommerceTest, shouldGenerateProductReview)
{
    auto generatedProductReview = commerce::product_review();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::productReviews, generatedProductReview);
}

TEST(CommerceTest, shouldGenerateProductRating)
{
    auto generatedProductRating = commerce::product_rating();

    ASSERT_TRUE(0. <= generatedProductRating && generatedProductRating <= 5.);
}

TEST(CommerceTest, shouldGenerateDiscountType)
{
    auto generatedDiscountType = commerce::discount_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::discountTypes, generatedDiscountType);
}

TEST(CommerceTest, shouldGenerateDiscountCode)
{

    auto generatedDiscountCode = commerce::discount_code();

    ASSERT_TRUE(commerce::data::kMinDiscountCodeLength <= generatedDiscountCode.length()
        && generatedDiscountCode.length() <= commerce::data::kMaxDiscountCodeLength);

    ASSERT_TRUE(
        faker::testing::all_of(generatedDiscountCode, [](char generatedDiscountCodeCharacter) {
            return faker::testing::any_of(string::data::upperAlphanumericCharacters,
                [generatedDiscountCodeCharacter](char upperAlphanumericCharacter) {
                    return upperAlphanumericCharacter == generatedDiscountCodeCharacter;
                });
        }));
}

TEST(CommerceTest, shouldGenerateDiscountAmount)
{
    auto generatedDiscountAmount = commerce::discount_amount();

    ASSERT_TRUE(commerce::data::kMinDiscountAmountValue <= generatedDiscountAmount
        && generatedDiscountAmount <= commerce::data::kMaxDiscountAmountValue);
}

TEST(CommerceTest, shouldGenerateDiscountPercentage)
{
    auto generatedDiscountPercentage = commerce::discount_percentage();

    ASSERT_TRUE(commerce::data::kMinDiscountPercentageValue <= generatedDiscountPercentage
        && generatedDiscountPercentage <= commerce::data::kMaxDiscountPercentageValue);
}
