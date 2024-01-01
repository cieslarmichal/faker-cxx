#include "faker-cxx/Company.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/Format.h"
#include "../../common/StringHelper.h"
#include "../person/data/england/EnglishFirstNames.h"
#include "../person/data/england/EnglishLastNames.h"
#include "../person/data/JobTitles.h"
#include "data/BuzzAdjectives.h"
#include "data/BuzzNouns.h"
#include "data/BuzzVerbs.h"
#include "data/CatchPhraseAdjectives.h"
#include "data/CatchPhraseDescriptors.h"
#include "data/CatchPhraseNouns.h"
#include "data/CompanyTypes.h"
#include "data/Industries.h"
#include "data/Suffixes.h"

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

    std::vector<std::string> expectedFirstNames{englishMalesFirstNames};

    expectedFirstNames.insert(expectedFirstNames.end(), englishFemalesFirstNames.begin(),
                              englishFemalesFirstNames.end());

    if (companyNameElements.size() == 2)
    {
        const auto& generatedLastName = companyNameElements[0];
        const auto& generatedCompanySuffix = companyNameElements[1];

        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companySuffixes, [generatedCompanySuffix](const std::string& companySuffix)
                                        { return companySuffix == generatedCompanySuffix; }));
    }
    else if (companyNameElements.size() == 3)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                        { return jobArea == generatedJobArea; }));
    }
    else if (companyNameElements.size() == 4)
    {
        const auto& generatedFirstName = companyNameElements[0];
        const auto& generatedLastName = companyNameElements[1];
        const auto& generatedJobArea = companyNameElements[2];
        const auto& lastElement = companyNameElements[3];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(englishLastNames, [generatedLastName](const std::string& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                        { return jobArea == generatedJobArea; }));
        ASSERT_TRUE(lastElement == "Services" ||
                    std::ranges::any_of(companySuffixes, [lastElement](const std::string& companySuffix)
                                        { return companySuffix == lastElement; }));
    }
}

TEST_F(CompanyTest, shouldGenerateCompanyType)
{
    const auto generatedCompanyType = Company::type();

    ASSERT_TRUE(std::ranges::any_of(companyTypes, [generatedCompanyType](const std::string& companyType)
                                    { return companyType == generatedCompanyType; }));
}

TEST_F(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto generatedCompanyIndustry = Company::industry();

    ASSERT_TRUE(std::ranges::any_of(companyIndustries, [generatedCompanyIndustry](const std::string& companyIndustry)
                                    { return companyIndustry == generatedCompanyIndustry; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto buzzPhrase = Company::buzzPhrase();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [buzzPhrase](const std::string& buzzVerb)
                                    { return buzzPhrase.find(buzzVerb) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [buzzPhrase](const std::string& buzzAdjective)
                                    { return buzzPhrase.find(buzzAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [buzzPhrase](const std::string& buzzNoun)
                                    { return buzzPhrase.find(buzzNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto generatedBuzzVerb = Company::buzzVerb();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [generatedBuzzVerb](const std::string& buzzVerb)
                                    { return buzzVerb == generatedBuzzVerb; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto generatedBuzzAdjective = Company::buzzAdjective();

    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [generatedBuzzAdjective](const std::string& buzzAdjective)
                                    { return buzzAdjective == generatedBuzzAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto generatedBuzzNoun = Company::buzzNoun();

    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [generatedBuzzNoun](const std::string& buzzNoun)
                                    { return buzzNoun == generatedBuzzNoun; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto catchPhrase = Company::catchPhrase();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives, [catchPhrase](const std::string& catchPhraseAdjective)
                                    { return catchPhrase.find(catchPhraseAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors, [catchPhrase](const std::string& catchPhraseDescriptor)
                                    { return catchPhrase.find(catchPhraseDescriptor) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns, [catchPhrase](const std::string& catchPhraseNoun)
                                    { return catchPhrase.find(catchPhraseNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto generatedCatchPhraseAdjective = Company::catchPhraseAdjective();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives,
                                    [generatedCatchPhraseAdjective](const std::string& catchPhraseAdjective)
                                    { return catchPhraseAdjective == generatedCatchPhraseAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto generatedCatchPhraseDescriptor = Company::catchPhraseDescriptor();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors,
                                    [generatedCatchPhraseDescriptor](const std::string& catchPhraseDescriptor)
                                    { return catchPhraseDescriptor == generatedCatchPhraseDescriptor; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto generatedCatchPhraseNoun = Company::catchPhraseNoun();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns, [generatedCatchPhraseNoun](const std::string& catchPhraseNoun)
                                    { return catchPhraseNoun == generatedCatchPhraseNoun; }));
}
