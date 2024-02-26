#include "../test_helpers.h"
#include <common/format_helper.h>
#include <common/string_helper.h>
#include <faker/company.h>
#include <modules/company_data.h>
#include <modules/person_data.h>

using namespace faker;

TEST(CompanyTest, shouldGenerateCompanyName)
{
    auto expectedFirstNames = faker::testing::make_vector(
        person::data::englishMalesFirstNames, person::data::englishFemalesFirstNames);

    auto companyName = company::name();

    auto companyNameElements = StringHelper::split(companyName, " ");
    if (companyNameElements.size() == 2) {
        auto generatedLastName = companyNameElements[0];
        auto generatedCompanySuffix = companyNameElements[1];

        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(company::data::companySuffixes, generatedCompanySuffix);
    } else if (companyNameElements.size() == 3) {
        auto generatedFirstName = companyNameElements[0];
        auto generatedLastName = companyNameElements[1];
        auto generatedJobArea = companyNameElements[2];

        FAKER_EXPECT_CONTAINER_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
    } else if (companyNameElements.size() == 4) {
        auto generatedFirstName = companyNameElements[0];
        auto generatedLastName = companyNameElements[1];
        auto generatedJobArea = companyNameElements[2];
        auto lastElement = companyNameElements[3];

        FAKER_EXPECT_CONTAINER_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::englishLastNames, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
        ASSERT_TRUE(lastElement == "Services"
            || faker::testing::contains(company::data::companySuffixes, lastElement));
    }
}

TEST(CompanyTest, shouldGenerateCompanyType)
{
    auto generatedCompanyType = company::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::companyTypes, generatedCompanyType);
}

TEST(CompanyTest, shouldGenerateCompanyIndustry)
{
    auto generatedCompanyIndustry = company::industry();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::companyIndustries, generatedCompanyIndustry);
}

TEST(CompanyTest, shouldGenerateBuzzPhrase)
{
    auto buzzPhrase = company::buzzPhrase();

    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzVerbs);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzAdjectives);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzNouns);
}

TEST(CompanyTest, shouldGenerateBuzzVerb)
{
    auto generatedBuzzVerb = company::buzzVerb();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzVerbs, generatedBuzzVerb);
}

TEST(CompanyTest, shouldGenerateBuzzAdjective)
{
    auto generatedBuzzAdjective = company::buzzAdjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzAdjectives, generatedBuzzAdjective);
}

TEST(CompanyTest, shouldGenerateBuzzNoun)
{
    auto generatedBuzzNoun = company::buzzNoun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzNouns, generatedBuzzNoun);
}

TEST(CompanyTest, shouldGenerateCatchPhrase)
{
    auto catchPhrase = company::catchPhrase();

    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseAdjectives);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseDescriptors);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseNouns);
}

TEST(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    auto generatedCatchPhraseAdjective = company::catchPhraseAdjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catchPhraseAdjectives, generatedCatchPhraseAdjective);
}

TEST(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    auto generatedCatchPhraseDescriptor = company::catchPhraseDescriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catchPhraseDescriptors, generatedCatchPhraseDescriptor);
}

TEST(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    auto generatedCatchPhraseNoun = company::catchPhraseNoun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catchPhraseNouns, generatedCatchPhraseNoun);
}
