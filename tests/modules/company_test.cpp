#include <algorithm>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "company_data.h"
#include "faker-cxx/company.h"
#include "person_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::company;

namespace
{
const struct CompanyDefinition& getCompanyDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSCompanyDefinition;
    }
}
}

class CompanyTest : public TestWithParam<Locale>
{
public:
};

TEST_P(CompanyTest, shouldGenerateCompanyName)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCompanyName = companyName(std::nullopt, locale);
    const auto generatedCompanyFirstLastNames = companyName(CompanyNameFormat::FirstNameLastNameSuffix, locale);
    const auto generatedCompanyFirstLastNamesJobArea =
        companyName(CompanyNameFormat::FirstNameLastNameJobAreaSuffix, locale);

    const auto companyNameElements = common::split(generatedCompanyName, " ");
    const auto companyNameElements1 = common::split(generatedCompanyFirstLastNames, " ");
    const auto companyNameElements2 = common::split(generatedCompanyFirstLastNamesJobArea, " ");

    std::vector<std::string_view> expectedFirstNames(person::englishMaleFirstNames.begin(),
                                                     person::englishMaleFirstNames.end());
    expectedFirstNames.insert(expectedFirstNames.end(), person::englishFemaleFirstNames.begin(),
                              person::englishFemaleFirstNames.end());

    EXPECT_TRUE(companyNameElements.size() == 2);
    EXPECT_TRUE(companyNameElements1.size() == 3);
    EXPECT_TRUE(companyNameElements2.size() == 4);

    if (companyNameElements.size() == 2)
    {

        const auto& generatedLastName = companyNameElements[0];
        const auto& lastElement = companyNameElements[1];

        ASSERT_TRUE(std::ranges::any_of(person::englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companyDefintion.companySuffixes,
                                        [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }

    if (companyNameElements1.size() == 3)
    {

        const auto& generatedFirstName = companyNameElements1[0];
        const auto& generatedLastName = companyNameElements1[1];
        const auto& lastElement = companyNameElements1[2];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string_view& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(person::englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companyDefintion.companySuffixes,
                                        [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }

    if (companyNameElements2.size() == 4)
    {

        const auto& generatedFirstName = companyNameElements2[0];
        const auto& generatedLastName = companyNameElements2[1];
        const auto& generatedJobArea = companyNameElements2[2];
        const auto& lastElement = companyNameElements2[3];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string_view& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(person::englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(person::jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                        { return jobArea == generatedJobArea; }));
        ASSERT_TRUE(std::ranges::any_of(companyDefintion.companySuffixes,
                                        [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }
}

TEST_P(CompanyTest, shouldGenerateCompanyType)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCompanyType = type(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.companyTypes,
                                    [generatedCompanyType](const std::string_view& companyType)
                                    { return companyType == generatedCompanyType; }));
}

TEST_P(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCompanyIndustry = industry(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.companyIndustries,
                                    [generatedCompanyIndustry](const std::string_view& companyIndustry)
                                    { return companyIndustry == generatedCompanyIndustry; }));
}

TEST_P(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedBuzzPhrase = buzzPhrase(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzVerbs, [generatedBuzzPhrase](const std::string_view& buzzVerb)
                                    { return generatedBuzzPhrase.find(buzzVerb) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzAdjectives,
                                    [generatedBuzzPhrase](const std::string_view& buzzAdjective)
                                    { return generatedBuzzPhrase.find(buzzAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzNouns, [generatedBuzzPhrase](const std::string_view& buzzNoun)
                                    { return generatedBuzzPhrase.find(buzzNoun) != std::string::npos; }));
}

TEST_P(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedBuzzVerb = buzzVerb(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzVerbs, [generatedBuzzVerb](const std::string_view& buzzVerb)
                                    { return buzzVerb == generatedBuzzVerb; }));
}

TEST_P(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedBuzzAdjective = buzzAdjective(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzAdjectives,
                                    [generatedBuzzAdjective](const std::string_view& buzzAdjective)
                                    { return buzzAdjective == generatedBuzzAdjective; }));
}

TEST_P(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);

    const auto generatedBuzzNoun = buzzNoun(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.buzzNouns, [generatedBuzzNoun](const std::string_view& buzzNoun)
                                    { return buzzNoun == generatedBuzzNoun; }));
}

TEST_P(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCatchPhrase = catchPhrase(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseAdjectives,
                                    [generatedCatchPhrase](const std::string_view& catchPhraseAdjective)
                                    { return generatedCatchPhrase.find(catchPhraseAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseDescriptors,
                                    [generatedCatchPhrase](const std::string_view& catchPhraseDescriptor)
                                    { return generatedCatchPhrase.find(catchPhraseDescriptor) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseNouns,
                                    [generatedCatchPhrase](const std::string_view& catchPhraseNoun)
                                    { return generatedCatchPhrase.find(catchPhraseNoun) != std::string::npos; }));
}

TEST_P(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCatchPhraseAdjective = catchPhraseAdjective(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseAdjectives,
                                    [generatedCatchPhraseAdjective](const std::string_view& catchPhraseAdjective)
                                    { return catchPhraseAdjective == generatedCatchPhraseAdjective; }));
}

TEST_P(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);

    const auto generatedCatchPhraseDescriptor = catchPhraseDescriptor(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseDescriptors,
                                    [generatedCatchPhraseDescriptor](const std::string_view& catchPhraseDescriptor)
                                    { return catchPhraseDescriptor == generatedCatchPhraseDescriptor; }));
}

TEST_P(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto locale = GetParam();
    const auto& companyDefintion = getCompanyDefinition(locale);
    const auto generatedCatchPhraseNoun = catchPhraseNoun(locale);

    ASSERT_TRUE(std::ranges::any_of(companyDefintion.catchPhraseNouns,
                                    [generatedCatchPhraseNoun](const std::string_view& catchPhraseNoun)
                                    { return catchPhraseNoun == generatedCatchPhraseNoun; }));
}

INSTANTIATE_TEST_SUITE_P(TestCompanyByLocale, CompanyTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
