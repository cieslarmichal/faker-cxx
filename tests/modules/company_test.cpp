#include "../test_helpers.h"
#include <common/formatter.h>
#include <common/strings.h>
#include <faker/company.h>
#include <modules/company_data.h>
#include <modules/person_data.h>

using namespace faker;

TEST(CompanyTest, shouldGenerateCompanyName)
{
    auto expectedFirstNames = faker::testing::make_vector(
        person::data::englishMalesFirstNames, person::data::englishFemalesFirstNames);

    auto companyName = company::name();

    auto companyNameElements = utils::split(companyName, " ");
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
    auto buzzPhrase = company::buzz_phrase();

    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzVerbs);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzAdjectives);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzzNouns);
}

TEST(CompanyTest, shouldGenerateBuzzVerb)
{
    auto generatedBuzzVerb = company::buzz_verb();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzVerbs, generatedBuzzVerb);
}

TEST(CompanyTest, shouldGenerateBuzzAdjective)
{
    auto generatedBuzzAdjective = company::buzz_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzAdjectives, generatedBuzzAdjective);
}

TEST(CompanyTest, shouldGenerateBuzzNoun)
{
    auto generatedBuzzNoun = company::buzz_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzzNouns, generatedBuzzNoun);
}

TEST(CompanyTest, shouldGenerateCatchPhrase)
{
    auto catchPhrase = company::catch_phrase();

    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseAdjectives);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseDescriptors);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catchPhraseNouns);
}

TEST(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    auto generatedCatchPhraseAdjective = company::catch_phrase_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catchPhraseAdjectives, generatedCatchPhraseAdjective);
}

TEST(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    auto generatedCatchPhraseDescriptor = company::catch_phrase_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catchPhraseDescriptors, generatedCatchPhraseDescriptor);
}

TEST(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    auto generatedCatchPhraseNoun = company::catch_phrase_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catchPhraseNouns, generatedCatchPhraseNoun);
}
