#include "faker-cxx/company.h"

#include <algorithm>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "company_data.h"
#include "person_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::company;

class CompanyTest : public Test
{
public:
};

TEST_F(CompanyTest, shouldGenerateCompanyName)
{
    const auto generatedCompanyName = companyName();
    const auto generatedCompanyFirstLastNames = 
                companyName(CompanyNameFormat::FirstNameLastNameSuffix);
    const auto generatedCompanyFirstLastNamesJobArea = 
                companyName(CompanyNameFormat::FirstNameLastNameJobAreaSuffix);

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

    if (companyNameElements.size() == 2){
    
        const auto& generatedLastName = companyNameElements[0];
        const auto& lastElement = companyNameElements[1];

        ASSERT_TRUE(std::ranges::any_of(person::englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companySuffixes, [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }

    if (companyNameElements1.size() == 3){
    
        const auto& generatedFirstName = companyNameElements1[0];
        const auto& generatedLastName = companyNameElements1[1];
        const auto& lastElement = companyNameElements1[2];

        ASSERT_TRUE(std::ranges::any_of(expectedFirstNames, [generatedFirstName](const std::string_view& firstName)
                                        { return firstName == generatedFirstName; }));
        ASSERT_TRUE(std::ranges::any_of(person::englishLastNames, [generatedLastName](const std::string_view& lastName)
                                        { return lastName == generatedLastName; }));
        ASSERT_TRUE(std::ranges::any_of(companySuffixes, [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }

    if (companyNameElements2.size() == 4){
    
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
        ASSERT_TRUE(std::ranges::any_of(companySuffixes, [lastElement](const std::string_view& companySuffix)
                                        { return companySuffix == lastElement; }));
    }
}

TEST_F(CompanyTest, shouldGenerateCompanyType)
{
    const auto generatedCompanyType = type();

    ASSERT_TRUE(std::ranges::any_of(companyTypes, [generatedCompanyType](const std::string_view& companyType)
                                    { return companyType == generatedCompanyType; }));
}

TEST_F(CompanyTest, shouldGenerateCompanyIndustry)
{
    const auto generatedCompanyIndustry = industry();

    ASSERT_TRUE(std::ranges::any_of(companyIndustries,
                                    [generatedCompanyIndustry](const std::string_view& companyIndustry)
                                    { return companyIndustry == generatedCompanyIndustry; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzPhrase)
{
    const auto generatedBuzzPhrase = buzzPhrase();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [generatedBuzzPhrase](const std::string_view& buzzVerb)
                                    { return generatedBuzzPhrase.find(buzzVerb) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [generatedBuzzPhrase](const std::string_view& buzzAdjective)
                                    { return generatedBuzzPhrase.find(buzzAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [generatedBuzzPhrase](const std::string_view& buzzNoun)
                                    { return generatedBuzzPhrase.find(buzzNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzVerb)
{
    const auto generatedBuzzVerb = buzzVerb();

    ASSERT_TRUE(std::ranges::any_of(buzzVerbs, [generatedBuzzVerb](const std::string_view& buzzVerb)
                                    { return buzzVerb == generatedBuzzVerb; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzAdjective)
{
    const auto generatedBuzzAdjective = buzzAdjective();

    ASSERT_TRUE(std::ranges::any_of(buzzAdjectives, [generatedBuzzAdjective](const std::string_view& buzzAdjective)
                                    { return buzzAdjective == generatedBuzzAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateBuzzNoun)
{
    const auto generatedBuzzNoun = buzzNoun();

    ASSERT_TRUE(std::ranges::any_of(buzzNouns, [generatedBuzzNoun](const std::string_view& buzzNoun)
                                    { return buzzNoun == generatedBuzzNoun; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhrase)
{
    const auto generatedCatchPhrase = catchPhrase();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives,
                                    [generatedCatchPhrase](const std::string_view& catchPhraseAdjective)
                                    { return generatedCatchPhrase.find(catchPhraseAdjective) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors,
                                    [generatedCatchPhrase](const std::string_view& catchPhraseDescriptor)
                                    { return generatedCatchPhrase.find(catchPhraseDescriptor) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns, [generatedCatchPhrase](const std::string_view& catchPhraseNoun)
                                    { return generatedCatchPhrase.find(catchPhraseNoun) != std::string::npos; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseAdjective)
{
    const auto generatedCatchPhraseAdjective = catchPhraseAdjective();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseAdjectives,
                                    [generatedCatchPhraseAdjective](const std::string_view& catchPhraseAdjective)
                                    { return catchPhraseAdjective == generatedCatchPhraseAdjective; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseDescriptor)
{
    const auto generatedCatchPhraseDescriptor = catchPhraseDescriptor();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseDescriptors,
                                    [generatedCatchPhraseDescriptor](const std::string_view& catchPhraseDescriptor)
                                    { return catchPhraseDescriptor == generatedCatchPhraseDescriptor; }));
}

TEST_F(CompanyTest, shouldGenerateCatchPhraseNoun)
{
    const auto generatedCatchPhraseNoun = catchPhraseNoun();

    ASSERT_TRUE(std::ranges::any_of(catchPhraseNouns,
                                    [generatedCatchPhraseNoun](const std::string_view& catchPhraseNoun)
                                    { return catchPhraseNoun == generatedCatchPhraseNoun; }));
}
