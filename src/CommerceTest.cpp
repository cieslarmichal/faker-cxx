#include "Commerce.h"

#include "gtest/gtest.h"

#include "data/Characters.h"
#include "data/Commerce.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

class CommerceTest : public Test
{
public:
};

TEST_F(CommerceTest, shouldGenerateCommerceDepartment)
{
    const auto generatedDepartment = Commerce::department();

    ASSERT_TRUE(std::any_of(departments.begin(), departments.end(),
                            [generatedDepartment](const std::string& department)
                            { return department == generatedDepartment; }));
}

TEST_F(CommerceTest, shouldGeneratePrice)
{
    const auto generatedPrice = Commerce::price(100, 10000);

    const auto priceAsFloat = std::stof(generatedPrice);

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
    ASSERT_TRUE(std::all_of(sku.begin(), sku.end(),
                            [](char skuCharacter)
                            {
                                return std::any_of(numericCharacters.begin(), numericCharacters.end(),
                                                   [skuCharacter](char numericCharacter)
                                                   { return skuCharacter == numericCharacter; });
                            }));
}

TEST_F(CommerceTest, shouldGenerateSkuWithSpecifiedLength)
{
    const auto skuLength = 8;

    const auto sku = Commerce::sku(skuLength);

    ASSERT_EQ(sku.size(), skuLength);
    ASSERT_TRUE(std::all_of(sku.begin(), sku.end(),
                            [](char skuCharacter)
                            {
                                return std::any_of(numericCharacters.begin(), numericCharacters.end(),
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

    ASSERT_TRUE(std::any_of(productAdjectives.begin(), productAdjectives.end(),
                            [generatedProductAdjective](const std::string& adjective)
                            { return adjective == generatedProductAdjective; }));
    ASSERT_TRUE(std::any_of(productMaterials.begin(), productMaterials.end(),
                            [generatedProductMaterial](const std::string& material)
                            { return material == generatedProductMaterial; }));
    ASSERT_TRUE(std::any_of(productNames.begin(), productNames.end(),
                            [generatedProductName](const std::string& productName)
                            { return productName == generatedProductName; }));
}

TEST_F(CommerceTest, shouldGenerateProductAdjective)
{
    const auto generatedProductAdjective = Commerce::productAdjective();

    ASSERT_TRUE(std::any_of(productAdjectives.begin(), productAdjectives.end(),
                            [generatedProductAdjective](const std::string& adjective)
                            { return adjective == generatedProductAdjective; }));
}

TEST_F(CommerceTest, shouldGenerateProductMaterial)
{
    const auto generatedProductMaterial = Commerce::productMaterial();

    ASSERT_TRUE(std::any_of(productMaterials.begin(), productMaterials.end(),
                            [generatedProductMaterial](const std::string& material)
                            { return material == generatedProductMaterial; }));
}

TEST_F(CommerceTest, shouldGenerateProductName)
{
    const auto generatedProductName = Commerce::productName();

    ASSERT_TRUE(std::any_of(productNames.begin(), productNames.end(),
                            [generatedProductName](const std::string& productName)
                            { return productName == generatedProductName; }));
}
