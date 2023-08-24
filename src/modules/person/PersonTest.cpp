#include "faker-cxx/Person.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/english/EnglishFirstNamesFemales.h"
#include "data/english/EnglishFirstNamesMales.h"
#include "data/english/EnglishLastNames.h"
#include "data/french/FrenchFirstNamesFemales.h"
#include "data/french/FrenchFirstNamesMales.h"
#include "data/french/FrenchLastNames.h"
#include "data/Gender.h"
#include "data/german/GermanFirstNamesFemales.h"
#include "data/german/GermanFirstNamesMales.h"
#include "data/german/GermanLastNames.h"
#include "data/italian/ItalianFirstNamesFemales.h"
#include "data/italian/ItalianFirstNamesMales.h"
#include "data/italian/ItalianLastNames.h"
#include "data/JobTitles.h"
#include "data/polish/PolishFirstNamesFemales.h"
#include "data/polish/PolishFirstNamesMales.h"
#include "data/polish/PolishLastNames.h"
#include "data/russian/RussianFirstNamesFemales.h"
#include "data/russian/RussianFirstNamesMales.h"
#include "data/russian/RussianLastNamesFemales.h"
#include "data/russian/RussianLastNamesMales.h"
#include "src/common/StringHelper.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto malePrefix{"Mr."};
const std::vector<std::string> femalePrefixes{"Ms.", "Miss"};
const std::vector<std::string> allPrefixes{"Mr.", "Ms.", "Miss"};

const std::vector<Language> languages{Language::English, Language::French, Language::German, Language::Italian,
                                      Language::Polish, Language::Russian};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToFirstNamesMapping{
    {Language::English, {{Sex::Male, englishFirstNamesMales}, {Sex::Female, englishFirstNamesFemales}}},
    {Language::French, {{Sex::Male, frenchFirstNamesMales}, {Sex::Female, frenchFirstNamesFemales}}},
    {Language::German, {{Sex::Male, germanFirstNamesMales}, {Sex::Female, germanFirstNamesFemales}}},
    {Language::Italian, {{Sex::Male, italianFirstNamesMales}, {Sex::Female, italianFirstNamesFemales}}},
    {Language::Polish, {{Sex::Male, polishFirstNamesMales}, {Sex::Female, polishFirstNamesFemales}}},
    {Language::Russian, {{Sex::Male, russianFirstNamesMales}, {Sex::Female, russianFirstNamesFemales}}}
};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToLastNamesMapping{
    {Language::English, {{Sex::Male, englishLastNames}, {Sex::Female, englishLastNames}}},
    {Language::French, {{Sex::Male, frenchLastNames}, {Sex::Female, frenchLastNames}}},
    {Language::German, {{Sex::Male, germanLastNames}, {Sex::Female, germanLastNames}}},
    {Language::Italian, {{Sex::Male, italianLastNames}, {Sex::Female, italianLastNames}}},
    {Language::Polish, {{Sex::Male, polishLastNames}, {Sex::Female, polishLastNames}}},
    {Language::Russian, {{Sex::Male, russianLastNamesMales}, {Sex::Female, russianLastNamesFemales}}},
};

const std::map<Language, std::string> generatedTestName{
    {Language::English, "shouldGenerateEnglishName"}, {Language::French, "shouldGenerateFrenchName"},
    {Language::German, "shouldGenerateGermanName"},   {Language::Italian, "shouldGenerateItalianName"},
    {Language::Polish, "shouldGeneratePolishName"}, {Language::Russian, "shouldGenerateRussianName"}
};
}

class PersonTest : public TestWithParam<Language>
{
public:
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);
    const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto generatedFirstName = Person::firstName(language);

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGeneratemMaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);

    const auto generatedFirstName = Person::firstName(language, Sex::Male);

    ASSERT_TRUE(std::any_of(firstNamesMales.begin(), firstNamesMales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

    const auto generatedFirstName = Person::firstName(language, Sex::Female);

    ASSERT_TRUE(std::any_of(firstNamesFemales.begin(), firstNamesFemales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto language = GetParam();

    const auto& lastNamesMale = languageToLastNamesMapping.at(language).at(Sex::Male);

    const auto generatedLastName = Person::lastName(language, Sex::Male);

    ASSERT_TRUE(std::any_of(lastNamesMale.begin(), lastNamesMale.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto language = GetParam();

    const auto& lastNamesFemale = languageToLastNamesMapping.at(language).at(Sex::Female);

    const auto generatedLastName = Person::lastName(language, Sex::Female);

    ASSERT_TRUE(std::any_of(lastNamesFemale.begin(), lastNamesFemale.end(),
                            [generatedLastName](const std::string& lastName)
                            { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);
    const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

    const auto& lastNamesBySexMapping = languageToLastNamesMapping.at(language);

    const auto& lastNamesMales = lastNamesBySexMapping.at(Sex::Male);
    const auto& lastNamesFemales = lastNamesBySexMapping.at(Sex::Female);

    std::vector<std::string> firstNames{firstNamesMales};
    std::vector<std::string> lastNames{lastNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());
    lastNames.insert(lastNames.end(), lastNamesFemales.begin(), lastNamesFemales.end());

    const auto generatedFullName = Person::fullName(language);

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedFullName](const std::string& lastName)
                            { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);

    const auto& lastNames = languageToLastNamesMapping.at(language).at(Sex::Male);

    const auto generatedFullName = Person::fullName(language, Sex::Male);

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];

    ASSERT_TRUE(std::any_of(firstNamesMales.begin(), firstNamesMales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedFullName](const std::string& lastName)
                            { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

    const auto& lastNames = languageToLastNamesMapping.at(language).at(Sex::Female);

    const auto generatedFullName = Person::fullName(language, Sex::Female);

    const auto names = StringHelper::split(generatedFullName, " ");

    const auto& generatedFirstName = names[0];

    ASSERT_TRUE(std::any_of(firstNamesFemales.begin(), firstNamesFemales.end(),
                            [generatedFirstName](const std::string& firstName)
                            { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedFullName](const std::string& lastName)
                            { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByLanguages, PersonTest, ValuesIn(languages),
                         [](const TestParamInfo<Language>& info) { return generatedTestName.at(info.param); });

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
