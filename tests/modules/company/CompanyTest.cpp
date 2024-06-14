#include "faker-cxx/Company.h"

#include <algorithm>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

#include "common/StringHelper.h"
#include "company/CompanyData.h"
#include "person/PersonData.h"

using namespace ::testing;
using namespace faker;

class CompanyTest : public Test
{
public:
};

TEST_F(CompanyTest, shouldGenerateCompanyName)
{
    const auto companyName = Company::name();

    const auto companyNameElements = StringHelper::split(companyName, " ");

    std::vector<std::string_view> expectedFirstNames(englishMaleFirstNames.begin(), englishMaleFirstNames.end());
    expectedFirstNames.insert(expectedFirstNames.end(), englishFemaleFirstNames.begin(), englishFemaleFirstNames.end());

    if (companyNameElements.size() == 2)
    {
        const auto& generatedLastName = companyNameElements[0];
        const auto& generatedCompanySuffix = companyNameElements[1];

        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companySuffixes, [generatedCompanySuffix](const std::string_view& companySuffix)
                                        { return companySuffix == generatedCompanySuffix; }));
    }
    else if (companyNameElements.size() == 3)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string_view& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                        { return jobArea == generatedJobArea; }));
    }
    else if (companyNameElements.size() == 4)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];
        const auto& lastElement = companyNameElements[3];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string_view& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                        { return jobArea == generatedJobArea; }));
        ASSERT_TRUE(lastElement == "Services" ||
                    std::ranges::any_of(companySuffixes, [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }
}

TEST_F(CompanyTest, shouldGenerateCompanyType)
{
    const auto generatedCompanyType = Company::type();

    ASSERT_TRUE(std::ranges::any_of(companyTypes, [generatedCompanyType](const std::string_view& companyType)
                                    { return companyType == generatedCompanyType; }));
}

TEST_F(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto generatedCompanyIndustry = Company::industry();

    ASSERT_TRUE(std::ranges::any_of(companyIndustries,
                                    [generatedCompanyIndustry](const std::string_view& companyIndustry)
                                    { return companyIndustry == generatedCompanyIndustry; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto buzzPhrase = Company::buzzPhrase();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [buzzPhrase](const std::string_view& buzzVerb)
                                    { return buzzPhrase.find(buzzVerb) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [buzzPhrase](const std::string_view& buzzAdjective)
                                    { return buzzPhrase.find(buzzAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [buzzPhrase](const std::string_view& buzzNoun)
                                    { return buzzPhrase.find(buzzNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto generatedBuzzVerb = Company::buzzVerb();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [generatedBuzzVerb](const std::string_view& buzzVerb)
                                    { return buzzVerb == generatedBuzzVerb; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto generatedBuzzAdjective = Company::buzzAdjective();

    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [generatedBuzzAdjective](const std::string_view& buzzAdjective)
                                    { return buzzAdjective == generatedBuzzAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto generatedBuzzNoun = Company::buzzNoun();

    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [generatedBuzzNoun](const std::string_view& buzzNoun)
                                    { return buzzNoun == generatedBuzzNoun; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto catchPhrase = Company::catchPhrase();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives, [catchPhrase](const std::string_view& catchPhraseAdjective)
                                    { return catchPhrase.find(catchPhraseAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors, [catchPhrase](const std::string_view& catchPhraseDescriptor)
                                    { return catchPhrase.find(catchPhraseDescriptor) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns, [catchPhrase](const std::string_view& catchPhraseNoun)
                                    { return catchPhrase.find(catchPhraseNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto generatedCatchPhraseAdjective = Company::catchPhraseAdjective();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives,
                                    [generatedCatchPhraseAdjective](const std::string_view& catchPhraseAdjective)
                                    { return catchPhraseAdjective == generatedCatchPhraseAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto generatedCatchPhraseDescriptor = Company::catchPhraseDescriptor();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors,
                                    [generatedCatchPhraseDescriptor](const std::string_view& catchPhraseDescriptor)
                                    { return catchPhraseDescriptor == generatedCatchPhraseDescriptor; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto generatedCatchPhraseNoun = Company::catchPhraseNoun();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns,
                                    [generatedCatchPhraseNoun](const std::string_view& catchPhraseNoun)
                                    { return catchPhraseNoun == generatedCatchPhraseNoun; }));
}
