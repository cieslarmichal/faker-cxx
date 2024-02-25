#include "../test_helpers.h"
#include <common/format_helper.h>
#include <common/string_helper.h>
#include <faker/company.h>
#include <modules/company_data.h>
#include <modules/person_data.h>

using namespace faker;

TEST(CompanyTest, shouldGenerateCompanyName)
{
    auto companyName = company::name();
    auto companyNameElements = StringHelper::split(companyName, " ");

    std::vector<std::string_view> expectedFirstNames { englishMalesFirstNames };

    expectedFirstNames.insert(
        expectedFirstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    if (companyNameElements.size() == 2) {
        auto& generatedLastName = companyNameElements[0];
        auto& generatedCompanySuffix = companyNameElements[1];

        FAKER_EXPECT_CONTAINS(englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINS(companySuffixes, generatedCompanySuffix);
    } else if (companyNameElements.size() == 3) {
        auto& generatedFirstName = companyNameElements[0];
        auto& generatedLastName = companyNameElements[1];
        auto& generatedJobArea = companyNameElements[2];

        FAKER_EXPECT_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINS(englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINS(jobAreas, generatedJobArea);
    } else if (companyNameElements.size() == 4) {
        auto& generatedFirstName = companyNameElements[0];
        auto& generatedLastName = companyNameElements[1];
        auto& generatedJobArea = companyNameElements[2];
        auto& lastElement = companyNameElements[3];

        FAKER_EXPECT_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINS(englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINS(jobAreas, generatedJobArea);
        ASSERT_TRUE(
            lastElement == "Services" || faker::testing::contains(companySuffixes, lastElement));
    }
}

TEST(CompanyTest, shouldGenerateCompanyType)
{
    auto generatedCompanyType = company::type();

    FAKER_EXPECT_CONTAINS(companyTypes, generatedCompanyType);
}

TEST(CompanyTest, shouldGenerateCompanyIndustry)
{
    auto generatedCompanyIndustry = company::industry();

    FAKER_EXPECT_CONTAINS(companyIndustries, generatedCompanyIndustry);
}

TEST(CompanyTest, shouldGenerateBuzzPhrase)
{
    auto buzzPhrase = company::buzzPhrase();

    ASSERT_TRUE(faker::testing::any_of(buzzVerbs, [buzzPhrase](const std::string_view& buzzVerb) {
        return buzzPhrase.find(buzzVerb) != std::string::npos;
    }));
    ASSERT_TRUE(
        faker::testing::any_of(buzzAdjectives, [buzzPhrase](const std::string_view& buzzAdjective) {
            return buzzPhrase.find(buzzAdjective) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(buzzNouns, [buzzPhrase](const std::string_view& buzzNoun) {
        return buzzPhrase.find(buzzNoun) != std::string::npos;
    }));
}

TEST(CompanyTest, shouldGenerateBuzzVerb)
{
    auto generatedBuzzVerb = company::buzzVerb();

    FAKER_EXPECT_CONTAINS(buzzVerbs, generatedBuzzVerb);
}

TEST(CompanyTest, shouldGenerateBuzzAdjective)
{
    auto generatedBuzzAdjective = company::buzzAdjective();

    FAKER_EXPECT_CONTAINS(buzzAdjectives, generatedBuzzAdjective);
}

TEST(CompanyTest, shouldGenerateBuzzNoun)
{
    auto generatedBuzzNoun = company::buzzNoun();

    FAKER_EXPECT_CONTAINS(buzzNouns, generatedBuzzNoun);
}

TEST(CompanyTest, shouldGenerateCatchPhrase)
{
    auto catchPhrase = company::catchPhrase();

    ASSERT_TRUE(faker::testing::any_of(
        catchPhraseAdjectives, [catchPhrase](const std::string_view& catchPhraseAdjective) {
            return catchPhrase.find(catchPhraseAdjective) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        catchPhraseDescriptors, [catchPhrase](const std::string_view& catchPhraseDescriptor) {
            return catchPhrase.find(catchPhraseDescriptor) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        catchPhraseNouns, [catchPhrase](const std::string_view& catchPhraseNoun) {
            return catchPhrase.find(catchPhraseNoun) != std::string::npos;
        }));
}

TEST(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    auto generatedCatchPhraseAdjective = company::catchPhraseAdjective();

    FAKER_EXPECT_CONTAINS(catchPhraseAdjectives, generatedCatchPhraseAdjective);
}

TEST(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    auto generatedCatchPhraseDescriptor = company::catchPhraseDescriptor();

    FAKER_EXPECT_CONTAINS(catchPhraseDescriptors, generatedCatchPhraseDescriptor);
}

TEST(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    auto generatedCatchPhraseNoun = company::catchPhraseNoun();

    FAKER_EXPECT_CONTAINS(catchPhraseNouns, generatedCatchPhraseNoun);
}
