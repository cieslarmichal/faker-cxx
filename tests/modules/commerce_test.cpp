#include "../test_helpers.h"
#include <charconv>
#include <common/strings.h>
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

    auto generatedPriceElements = utils::split(generatedPrice, ".");

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
        return faker::testing::any_of(string::data::digits,
            [skuCharacter](auto numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    auto skuLength = 8;

    auto sku = commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(faker::testing::all_of(sku, [](char skuCharacter) {
        return faker::testing::any_of(string::data::digits,
            [skuCharacter](char numericCharacter) { return skuCharacter == numericCharacter; });
    }));
}

TEST(CommerceTest, shouldGenerateProductFullName)
{
    auto productFullName = commerce::product_full_name();

    auto productFullNameElements = utils::split(productFullName, " ");

    auto& generatedProductAdjective = productFullNameElements[0];
    auto& generatedProductMaterial = productFullNameElements[1];
    auto& generatedProductName = productFullNameElements[2];

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_adjectives, generatedProductAdjective);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_materials, generatedProductMaterial);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_names, generatedProductName);
}

TEST(CommerceTest, shouldGenerateProductAdjective)
{
    auto generatedProductAdjective = commerce::product_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_adjectives, generatedProductAdjective);
}

TEST(CommerceTest, shouldGenerateProductMaterial)
{
    auto generatedProductMaterial = commerce::product_material();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_materials, generatedProductMaterial);
}

TEST(CommerceTest, shouldGenerateProductName)
{
    auto generatedProductName = commerce::product_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_names, generatedProductName);
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

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::payment_types, generatedPaymentType);
}

TEST(CommerceTest, shouldGeneratePaymentProvider)
{
    auto generatedPaymentProvider = commerce::payment_provider();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::payment_providers, generatedPaymentProvider);
}

TEST(CommerceTest, shouldGenerateProductDescription)
{
    auto generatedProductDescription = commerce::product_description();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        commerce::data::product_descriptions, generatedProductDescription);
}

TEST(CommerceTest, shouldGenerateProductCategory)
{
    auto generatedProductCategory = commerce::product_category();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        commerce::data::product_category_names, generatedProductCategory);
}

TEST(CommerceTest, shouldGenerateProductReview)
{
    auto generatedProductReview = commerce::product_review();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_reviews, generatedProductReview);
}

TEST(CommerceTest, shouldGenerateProductRating)
{
    auto generatedProductRating = commerce::product_rating();

    ASSERT_TRUE(0. <= generatedProductRating && generatedProductRating <= 5.);
}

TEST(CommerceTest, shouldGenerateDiscountType)
{
    auto generatedDiscountType = commerce::discount_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::discount_types, generatedDiscountType);
}

TEST(CommerceTest, shouldGenerateDiscountCode)
{

    auto generatedDiscountCode = commerce::discount_code();

    ASSERT_TRUE(commerce::data::min_discount_code_length <= generatedDiscountCode.length()
        && generatedDiscountCode.length() <= commerce::data::max_discount_code_length);

    ASSERT_TRUE(
        faker::testing::all_of(generatedDiscountCode, [](char generatedDiscountCodeCharacter) {
            return faker::testing::any_of(string::data::ascii_upper_alphanum,
                [generatedDiscountCodeCharacter](char upperAlphanumericCharacter) {
                    return upperAlphanumericCharacter == generatedDiscountCodeCharacter;
                });
        }));
}

TEST(CommerceTest, shouldGenerateDiscountAmount)
{
    auto generatedDiscountAmount = commerce::discount_amount();

    ASSERT_TRUE(commerce::data::min_discount_amount <= generatedDiscountAmount
        && generatedDiscountAmount <= commerce::data::max_discount_amount);
}

TEST(CommerceTest, shouldGenerateDiscountPercentage)
{
    auto generatedDiscountPercentage = commerce::discount_percentage();

    ASSERT_TRUE(commerce::data::min_discount_percentage <= generatedDiscountPercentage
        && generatedDiscountPercentage <= commerce::data::max_discount_percentage);
}
