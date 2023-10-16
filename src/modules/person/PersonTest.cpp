#include "faker-cxx/Person.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/english/EnglishFirstNamesFemales.h"
#include "data/english/EnglishFirstNamesMales.h"
#include "data/english/EnglishLastNames.h"
#include "data/finnish/FinnishFirstNamesFemales.h"
#include "data/finnish/FinnishFirstNamesMales.h"
#include "data/finnish/FinnishLastNames.h"
#include "data/french/FrenchFirstNamesFemales.h"
#include "data/french/FrenchFirstNamesMales.h"
#include "data/french/FrenchLastNames.h"
#include "data/Gender.h"
#include "data/german/GermanFirstNamesFemales.h"
#include "data/german/GermanFirstNamesMales.h"
#include "data/german/GermanLastNames.h"
#include "data/Hobbies.h"
#include "data/indian/IndianFirstNames.h"
#include "data/indian/IndianLastNames.h"
#include "data/italian/ItalianFirstNamesFemales.h"
#include "data/italian/ItalianFirstNamesMales.h"
#include "data/italian/ItalianLastNames.h"
#include "data/JobTitles.h"
#include "data/polish/PolishFirstNamesFemales.h"
#include "data/polish/PolishFirstNamesMales.h"
#include "data/polish/PolishLastNames.h"
#include "data/romanian/RomanianFirstNamesFemales.h"
#include "data/romanian/RomanianFirstNamesMales.h"
#include "data/romanian/RomanianLastNames.h"
#include "data/russian/RussianFirstNamesFemales.h"
#include "data/russian/RussianFirstNamesMales.h"
#include "data/russian/RussianLastNamesFemales.h"
#include "data/russian/RussianLastNamesMales.h"
#include "src/common/StringHelper.h"
#include "src/modules/person/data/nepalese/NepaleseFirstNamesFemales.h"
#include "src/modules/person/data/nepalese/NepaleseFirstNamesMales.h"
#include "src/modules/person/data/nepalese/NepaleseLastNames.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto malePrefix{"Mr."};
const std::vector<std::string> femalePrefixes{"Ms.", "Miss"};
const std::vector<std::string> allPrefixes{"Mr.", "Ms.", "Miss"};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToFirstNamesMapping{
    {Language::English, {{Sex::Male, englishFirstNamesMales}, {Sex::Female, englishFirstNamesFemales}}},
    {Language::French, {{Sex::Male, frenchFirstNamesMales}, {Sex::Female, frenchFirstNamesFemales}}},
    {Language::German, {{Sex::Male, germanFirstNamesMales}, {Sex::Female, germanFirstNamesFemales}}},
    {Language::Italian, {{Sex::Male, italianFirstNamesMales}, {Sex::Female, italianFirstNamesFemales}}},
    {Language::Polish, {{Sex::Male, polishFirstNamesMales}, {Sex::Female, polishFirstNamesFemales}}},
    {Language::Russian, {{Sex::Male, russianFirstNamesMales}, {Sex::Female, russianFirstNamesFemales}}},
    {Language::Romanian, {{Sex::Male, romanianFirstNamesMales}, {Sex::Female, romanianFirstNamesFemales}}},
    {Language::Hindi, {{Sex::Male, indianFirstNamesMales}, {Sex::Female, indianFirstNamesFemales}}},
    {Language::Finnish, {{Sex::Male, finnishFirstNamesMales}, {Sex::Female, finnishFirstNamesFemales}}},
    {Language::Nepali, {{Sex::Male, nepaleseFirstNamesMales}, {Sex::Female, nepaleseFirstNamesFemales}}},
};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToLastNamesMapping{
    {Language::English, {{Sex::Male, englishLastNames}, {Sex::Female, englishLastNames}}},
    {Language::French, {{Sex::Male, frenchLastNames}, {Sex::Female, frenchLastNames}}},
    {Language::German, {{Sex::Male, germanLastNames}, {Sex::Female, germanLastNames}}},
    {Language::Italian, {{Sex::Male, italianLastNames}, {Sex::Female, italianLastNames}}},
    {Language::Polish, {{Sex::Male, polishLastNames}, {Sex::Female, polishLastNames}}},
    {Language::Russian, {{Sex::Male, russianLastNamesMales}, {Sex::Female, russianLastNamesFemales}}},
    {Language::Romanian, {{Sex::Male, romanianLastNames}, {Sex::Female, romanianLastNames}}},
    {Language::Hindi, {{Sex::Male, indianLastNames}, {Sex::Female, indianLastNames}}},
    {Language::Finnish, {{Sex::Male, finnishLastNames}, {Sex::Female, finnishLastNames}}},
    {Language::Nepali, {{Sex::Male, nepaleseLastNames}, {Sex::Female, nepaleseLastNames}}},
};

const std::map<Language, std::string> generatedTestName{
    {Language::English, "shouldGenerateEnglishName"},   {Language::French, "shouldGenerateFrenchName"},
    {Language::German, "shouldGenerateGermanName"},     {Language::Italian, "shouldGenerateItalianName"},
    {Language::Polish, "shouldGeneratePolishName"},     {Language::Russian, "shouldGenerateRussianName"},
    {Language::Romanian, "shouldGenerateRomanianName"}, {Language::Hindi, "shouldGenerateIndianName"},
    {Language::Finnish, "shouldGenerateFinnishName"},   {Language::Nepali, "shouldGenerateNepaleseName"},
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

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGeneratemMaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);

    const auto generatedFirstName = Person::firstName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(firstNamesMales, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

    const auto generatedFirstName = Person::firstName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(firstNamesFemales, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto language = GetParam();

    const auto& lastNamesMale = languageToLastNamesMapping.at(language).at(Sex::Male);

    const auto generatedLastName = Person::lastName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(lastNamesMale, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto language = GetParam();

    const auto& lastNamesFemale = languageToLastNamesMapping.at(language).at(Sex::Female);

    const auto generatedLastName = Person::lastName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(lastNamesFemale, [generatedLastName](const std::string& lastName)
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

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
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

    ASSERT_TRUE(std::ranges::any_of(firstNamesMales, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
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

    ASSERT_TRUE(std::ranges::any_of(firstNamesFemales, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByLanguages, PersonTest, ValuesIn(languages),
                         [](const TestParamInfo<Language>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateSex)
{
    const std::vector<std::string> sexes{"Male", "Female"};

    const auto generatedSex = Person::sex();

    ASSERT_TRUE(std::ranges::any_of(sexes, [generatedSex](const std::string& sex) { return sex == generatedSex; }));
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = Person::gender();

    ASSERT_TRUE(std::ranges::any_of(genders, [generatedGender](const std::string& gender)
                                    { return gender == generatedGender; }));
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = Person::jobDescriptor();

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = Person::jobArea();

    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                    { return jobArea == generatedJobArea; }));
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = Person::jobType();

    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = Person::jobTitle();

    const auto jobTitleElements = StringHelper::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                    { return jobArea == generatedJobArea; }));
    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = Person::prefix();

    ASSERT_TRUE(std::ranges::any_of(allPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Male);

    ASSERT_EQ(generatedPrefix, malePrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalePrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = Person::hobby();

    ASSERT_TRUE(
        std::ranges::any_of(hobbies, [generatedHobby](const std::string& hobby) { return hobby == generatedHobby; }));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    const auto generatedLanguage = Person::language();

    ASSERT_TRUE(std::ranges::any_of(languages, [generatedLanguage](Language language)
                                    { return generatedLanguage == toString(language); }));
}
