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

    auto priceAsFloat{0.0f};
    std::from_chars(generatedPrice.data(), generatedPrice.data() + generatedPrice.size(), priceAsFloat);

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
