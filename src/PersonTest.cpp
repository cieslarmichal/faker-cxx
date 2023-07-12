#include "Person.h"

#include "gtest/gtest.h"

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/Gender.h"
#include "data/JobTitles.h"
#include "data/LastNames.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto malePrefix{"Mr."};
const std::vector<std::string> femalePrefixes{"Ms.", "Miss"};
const std::vector<std::string> allPrefixes{"Mr.", "Ms.", "Miss"};
}

class PersonTest : public Test
{
public:
};

TEST_F(PersonTest, shouldGenerateFirstName)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto generatedFirstName = Person::firstName();

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_F(PersonTest, shouldGeneratemMaleFirstName)
{
    const auto generatedFirstName = Person::firstName(Sex::Male);

    ASSERT_TRUE(std::any_of(firstNamesMales.begin(), firstNamesMales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_F(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto generatedFirstName = Person::firstName(Sex::Female);

    ASSERT_TRUE(std::any_of(firstNamesFemales.begin(), firstNamesFemales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_F(PersonTest, shouldGenerateLastName)
{
    const auto generatedLastName = Person::lastName();

    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_F(PersonTest, shouldGenerateFullName)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto generatedFullName = Person::fullName();

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];
    const auto& generatedLastName = names[1];

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_F(PersonTest, shouldGenerateMaleFullName)
{
    const auto generatedFullName = Person::fullName(Sex::Male);

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];
    const auto& generatedLastName = names[1];

    ASSERT_TRUE(std::any_of(firstNamesMales.begin(), firstNamesMales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_F(PersonTest, shouldGenerateFemaleFullName)
{
    const auto generatedFullName = Person::fullName(Sex::Female);

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];
    const auto& generatedLastName = names[1];

    ASSERT_TRUE(std::any_of(firstNamesFemales.begin(), firstNamesFemales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_F(PersonTest, shouldGenerateSex)
{
    const std::vector<std::string> sexes{"Male", "Female"};

    const auto generatedSex = Person::sex();

    ASSERT_TRUE(std::any_of(sexes.begin(), sexes.end(),
                            [generatedSex](const std::string& sex) { return sex == generatedSex; }));
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = Person::gender();

    ASSERT_TRUE(std::any_of(genders.begin(), genders.end(),
                            [generatedGender](const std::string& gender) { return gender == generatedGender; }));
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = Person::jobDescriptor();

    ASSERT_TRUE(std::any_of(jobDescriptors.begin(), jobDescriptors.end(),
                            [generatedJobDescriptor](const std::string& jobDescriptor)
                            { return jobDescriptor == generatedJobDescriptor; }));
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = Person::jobArea();

    ASSERT_TRUE(std::any_of(jobAreas.begin(), jobAreas.end(),
                            [generatedJobArea](const std::string& jobArea) { return jobArea == generatedJobArea; }));
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = Person::jobType();

    ASSERT_TRUE(std::any_of(jobTypes.begin(), jobTypes.end(),
                            [generatedJobType](const std::string& jobType) { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = Person::jobTitle();

    const auto jobTitleElements = StringHelper::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    ASSERT_TRUE(std::any_of(jobDescriptors.begin(), jobDescriptors.end(),
                            [generatedJobDescriptor](const std::string& jobDescriptor)
                            { return jobDescriptor == generatedJobDescriptor; }));
    ASSERT_TRUE(std::any_of(jobAreas.begin(), jobAreas.end(),
                            [generatedJobArea](const std::string& jobArea) { return jobArea == generatedJobArea; }));
    ASSERT_TRUE(std::any_of(jobTypes.begin(), jobTypes.end(),
                            [generatedJobType](const std::string& jobType) { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = Person::prefix();

    ASSERT_TRUE(std::any_of(allPrefixes.begin(), allPrefixes.end(),
                            [generatedPrefix](const std::string& prefix) { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Male);

    ASSERT_EQ(generatedPrefix, malePrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Female);

    ASSERT_TRUE(std::any_of(femalePrefixes.begin(), femalePrefixes.end(),
                            [generatedPrefix](const std::string& prefix) { return prefix == generatedPrefix; }));
}
