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
        person::data::english_male_first_names, person::data::english_female_first_names);

    auto companyName = company::name();

    auto companyNameElements = utils::split(companyName, " ");
    if (companyNameElements.size() == 2) {
        auto generatedLastName = companyNameElements[0];
        auto generatedCompanySuffix = companyNameElements[1];

        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_suffixes, generatedCompanySuffix);
    } else if (companyNameElements.size() == 3) {
        auto generatedFirstName = companyNameElements[0];
        auto generatedLastName = companyNameElements[1];
        auto generatedJobArea = companyNameElements[2];

        FAKER_EXPECT_CONTAINER_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, generatedJobArea);
    } else if (companyNameElements.size() == 4) {
        auto generatedFirstName = companyNameElements[0];
        auto generatedLastName = companyNameElements[1];
        auto generatedJobArea = companyNameElements[2];
        auto lastElement = companyNameElements[3];

        FAKER_EXPECT_CONTAINER_CONTAINS(expectedFirstNames, generatedFirstName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, generatedLastName);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, generatedJobArea);
        ASSERT_TRUE(lastElement == "Services"
            || faker::testing::contains(company::data::company_suffixes, lastElement));
    }
}

TEST(CompanyTest, shouldGenerateCompanyType)
{
    auto generatedCompanyType = company::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_types, generatedCompanyType);
}

TEST(CompanyTest, shouldGenerateCompanyIndustry)
{
    auto generatedCompanyIndustry = company::industry();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_industries, generatedCompanyIndustry);
}

TEST(CompanyTest, shouldGenerateBuzzPhrase)
{
    auto buzzPhrase = company::buzz_phrase();

    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzz_verbs);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzz_adjectives);
    FAKER_EXPECT_STRING_CONTAINS(buzzPhrase, company::data::buzz_nouns);
}

TEST(CompanyTest, shouldGenerateBuzzVerb)
{
    auto generatedBuzzVerb = company::buzz_verb();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_verbs, generatedBuzzVerb);
}

TEST(CompanyTest, shouldGenerateBuzzAdjective)
{
    auto generatedBuzzAdjective = company::buzz_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_adjectives, generatedBuzzAdjective);
}

TEST(CompanyTest, shouldGenerateBuzzNoun)
{
    auto generatedBuzzNoun = company::buzz_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_nouns, generatedBuzzNoun);
}

TEST(CompanyTest, shouldGenerateCatchPhrase)
{
    auto catchPhrase = company::catch_phrase();

    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catch_phrase_adjectives);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catch_phrase_descriptors);
    FAKER_EXPECT_STRING_CONTAINS(catchPhrase, company::data::catch_phrase_nouns);
}

TEST(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    auto generatedCatchPhraseAdjective = company::catch_phrase_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catch_phrase_adjectives, generatedCatchPhraseAdjective);
}

TEST(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    auto generatedCatchPhraseDescriptor = company::catch_phrase_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        company::data::catch_phrase_descriptors, generatedCatchPhraseDescriptor);
}

TEST(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    auto generatedCatchPhraseNoun = company::catch_phrase_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catch_phrase_nouns, generatedCatchPhraseNoun);
}
