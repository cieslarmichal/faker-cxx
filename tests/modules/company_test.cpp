#include "../test_helpers.h"
#include <algorithm>
#include <common/format_helper.h>
#include <common/string_helper.h>
#include <faker/company.h>
#include <modules/company_data.h>
#include <modules/person_data.h>

using namespace ::testing;
using namespace faker;

class CompanyTest : public Test {
public:
};

TEST_F(CompanyTest, shouldGenerateCompanyName)
{
    const auto companyName = company::name();

    const auto companyNameElements = StringHelper::split(companyName, " ");

    std::vector<std::string> expectedFirstNames { englishMalesFirstNames };

    expectedFirstNames.insert(
        expectedFirstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    if (companyNameElements.size() == 2) {
        const auto& generatedLastName = companyNameElements[0];
        const auto& generatedCompanySuffix = companyNameElements[1];

        ASSERT_TRUE(faker::testing::contains(englishLastNames, generatedLastName));
        ASSERT_TRUE(faker::testing::contains(companySuffixes, generatedCompanySuffix));
    } else if (companyNameElements.size() == 3) {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];

        ASSERT_TRUE(faker::testing::contains(expectedFirstNames, generatedFirstName));
        ASSERT_TRUE(faker::testing::contains(englishLastNames, generatedLastName));
        ASSERT_TRUE(faker::testing::contains(jobAreas, generatedJobArea));
    } else if (companyNameElements.size() == 4) {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];
        const auto& lastElement = companyNameElements[3];

        ASSERT_TRUE(faker::testing::contains(expectedFirstNames, generatedFirstName));
        ASSERT_TRUE(faker::testing::contains(englishLastNames, generatedLastName));
        ASSERT_TRUE(faker::testing::contains(jobAreas, generatedJobArea));
        ASSERT_TRUE(
            lastElement == "Services" || faker::testing::contains(companySuffixes, lastElement));
    }
}

TEST_F(CompanyTest, shouldGenerateCompanyType)
{
    const auto generatedCompanyType = company::type();
    ASSERT_TRUE(faker::testing::contains(companyTypes, generatedCompanyType));
}

TEST_F(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto generatedCompanyIndustry = company::industry();
    ASSERT_TRUE(faker::testing::contains(companyIndustries, generatedCompanyIndustry));
}

TEST_F(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto buzzPhrase = company::buzzPhrase();

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

TEST_F(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto generatedBuzzVerb = company::buzzVerb();

    ASSERT_TRUE(faker::testing::contains(buzzVerbs, generatedBuzzVerb));
}

TEST_F(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto generatedBuzzAdjective = company::buzzAdjective();

    ASSERT_TRUE(faker::testing::contains(buzzAdjectives, generatedBuzzAdjective));
}

TEST_F(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto generatedBuzzNoun = company::buzzNoun();

    ASSERT_TRUE(faker::testing::contains(buzzNouns, generatedBuzzNoun));
}

TEST_F(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto catchPhrase = company::catchPhrase();

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

TEST_F(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto generatedCatchPhraseAdjective = company::catchPhraseAdjective();

    ASSERT_TRUE(faker::testing::contains(catchPhraseAdjectives, generatedCatchPhraseAdjective));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto generatedCatchPhraseDescriptor = company::catchPhraseDescriptor();

    ASSERT_TRUE(faker::testing::contains(catchPhraseDescriptors, generatedCatchPhraseDescriptor));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto generatedCatchPhraseNoun = company::catchPhraseNoun();

    ASSERT_TRUE(faker::testing::contains(catchPhraseNouns, generatedCatchPhraseNoun));
}
