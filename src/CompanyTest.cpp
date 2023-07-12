#include "Company.h"

#include "gtest/gtest.h"

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/JobTitles.h"
#include "data/LastNames.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<std::string> companySuffixes{"Inc", "LLC", "Group"};
}

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
