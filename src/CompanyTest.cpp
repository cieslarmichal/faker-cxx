#include "Company.h"

#include "gtest/gtest.h"

#include "data/company/BuzzAdjectives.h"
#include "data/company/BuzzNouns.h"
#include "data/company/BuzzVerbs.h"
#include "data/company/CatchPhraseAdjectives.h"
#include "data/company/CatchPhraseDescriptors.h"
#include "data/company/CatchPhraseNouns.h"
#include "data/company/CompanyTypes.h"
#include "data/company/Industries.h"
#include "data/company/Suffixes.h"
#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/JobTitles.h"
#include "data/LastNames.h"
#include "StringHelper.h"

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

    std::vector<std::string> expectedFirstNames{firstNamesMales};

    expectedFirstNames.insert(expectedFirstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    if (companyNameElements.size() == 2)
    {
        const auto& generatedLastName = companyNameElements[0];
        const auto& generatedCompanySuffix = companyNameElements[1];

        ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                                [generatedLastName](const std::string& lastName)
                                { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::any_of(companySuffixes.begin(), companySuffixes.end(),
                                [generatedCompanySuffix](const std::string& companySuffix)
                                { return companySuffix == generatedCompanySuffix; }));
    }
    else if (companyNameElements.size() == 3)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];

        ASSERT_TRUE(std::any_of(expectedFirstNames.begin(), expectedFirstNames.end(),
                                [generatedFirstName](const std::string& firstName)
                                { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                                [generatedLastName](const std::string& lastName)
                                { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::any_of(jobAreas.begin(), jobAreas.end(),
                                [generatedJobArea](const std::string& jobArea)
                                { return jobArea == generatedJobArea; }));
    }
    else if (companyNameElements.size() == 4)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];
        const auto& lastElement = companyNameElements[3];

        ASSERT_TRUE(std::any_of(expectedFirstNames.begin(), expectedFirstNames.end(),
                                [generatedFirstName](const std::string& firstName)
                                { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                                [generatedLastName](const std::string& lastName)
                                { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::any_of(jobAreas.begin(), jobAreas.end(),
                                [generatedJobArea](const std::string& jobArea)
                                { return jobArea == generatedJobArea; }));
        ASSERT_TRUE(lastElement == "Services" || std::any_of(companySuffixes.begin(), companySuffixes.end(),
                                                             [lastElement](const std::string& companySuffix)
                                                             { return companySuffix == lastElement; }));
    }
}

TEST_F(CompanyTest, shouldGenerateCompanyType)
{
    const auto generatedCompanyType = Company::type();

    ASSERT_TRUE(std::any_of(companyTypes.begin(), companyTypes.end(),
                            [generatedCompanyType](const std::string& companyType)
                            { return companyType == generatedCompanyType; }));
}

TEST_F(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto generatedCompanyIndustry = Company::industry();

    ASSERT_TRUE(std::any_of(companyIndustries.begin(), companyIndustries.end(),
                            [generatedCompanyIndustry](const std::string& companyIndustry)
                            { return companyIndustry == generatedCompanyIndustry; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto buzzPhrase = Company::buzzPhrase();

    ASSERT_TRUE(std::any_of(buzzVerbs.begin(), buzzVerbs.end(),
                            [buzzPhrase](const std::string& buzzVerb)
                            { return buzzPhrase.find(buzzVerb) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(buzzAdjectives.begin(), buzzAdjectives.end(),
                            [buzzPhrase](const std::string& buzzAdjective)
                            { return buzzPhrase.find(buzzAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(buzzNouns.begin(), buzzNouns.end(),
                            [buzzPhrase](const std::string& buzzNoun)
                            { return buzzPhrase.find(buzzNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto generatedBuzzVerb = Company::buzzVerb();

    ASSERT_TRUE(std::any_of(buzzVerbs.begin(), buzzVerbs.end(),
                            [generatedBuzzVerb](const std::string& buzzVerb)
                            { return buzzVerb == generatedBuzzVerb; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto generatedBuzzAdjective = Company::buzzAdjective();

    ASSERT_TRUE(std::any_of(buzzAdjectives.begin(), buzzAdjectives.end(),
                            [generatedBuzzAdjective](const std::string& buzzAdjective)
                            { return buzzAdjective == generatedBuzzAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto generatedBuzzNoun = Company::buzzNoun();

    ASSERT_TRUE(std::any_of(buzzNouns.begin(), buzzNouns.end(),
                            [generatedBuzzNoun](const std::string& buzzNoun)
                            { return buzzNoun == generatedBuzzNoun; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto catchPhrase = Company::catchPhrase();

    ASSERT_TRUE(std::any_of(catchPhraseAdjectives.begin(), catchPhraseAdjectives.end(),
                            [catchPhrase](const std::string& catchPhraseAdjective)
                            { return catchPhrase.find(catchPhraseAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(catchPhraseDescriptors.begin(), catchPhraseDescriptors.end(),
                            [catchPhrase](const std::string& catchPhraseDescriptor)
                            { return catchPhrase.find(catchPhraseDescriptor) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(catchPhraseNouns.begin(), catchPhraseNouns.end(),
                            [catchPhrase](const std::string& catchPhraseNoun)
                            { return catchPhrase.find(catchPhraseNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto generatedCatchPhraseAdjective = Company::catchPhraseAdjective();

    ASSERT_TRUE(std::any_of(catchPhraseAdjectives.begin(), catchPhraseAdjectives.end(),
                            [generatedCatchPhraseAdjective](const std::string& catchPhraseAdjective)
                            { return catchPhraseAdjective == generatedCatchPhraseAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto generatedCatchPhraseDescriptor = Company::catchPhraseDescriptor();

    ASSERT_TRUE(std::any_of(catchPhraseDescriptors.begin(), catchPhraseDescriptors.end(),
                            [generatedCatchPhraseDescriptor](const std::string& catchPhraseDescriptor)
                            { return catchPhraseDescriptor == generatedCatchPhraseDescriptor; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto generatedCatchPhraseNoun = Company::catchPhraseNoun();

    ASSERT_TRUE(std::any_of(catchPhraseNouns.begin(), catchPhraseNouns.end(),
                            [generatedCatchPhraseNoun](const std::string& catchPhraseNoun)
                            { return catchPhraseNoun == generatedCatchPhraseNoun; }));
}
