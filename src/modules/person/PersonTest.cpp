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
#include "data/Nationalities.h"
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
#include "data/spanish/SpanishFirstNamesFemales.h"
#include "data/spanish/SpanishFirstNamesMales.h"
#include "data/spanish/SpanishLastNames.h"
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
    {Language::Spanish, {{Sex::Male, spanishFirstNamesMales}, {Sex::Female, spanishFirstNamesFemales}}},
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
    {Language::Spanish, {{Sex::Male, spanishLastNames}, {Sex::Female, spanishLastNames}}},
};

const std::map<Language, std::string> generatedTestName{
    {Language::English, "shouldGenerateEnglishName"},   {Language::French, "shouldGenerateFrenchName"},
    {Language::German, "shouldGenerateGermanName"},     {Language::Italian, "shouldGenerateItalianName"},
    {Language::Polish, "shouldGeneratePolishName"},     {Language::Russian, "shouldGenerateRussianName"},
    {Language::Romanian, "shouldGenerateRomanianName"}, {Language::Hindi, "shouldGenerateIndianName"},
    {Language::Finnish, "shouldGenerateFinnishName"},   {Language::Nepali, "shouldGenerateNepaleseName"},
    {Language::Spanish, "shouldGenerateSpanishName"},
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

    const auto& malesFirstNames = firstNamesBySexMapping.at(Sex::Male);
    const auto& femalesFirstNames = firstNamesBySexMapping.at(Sex::Female);

    std::vector<std::string> firstNames{malesFirstNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = Person::firstName(language);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& malesFirstNames = firstNamesBySexMapping.at(Sex::Male);

    const auto generatedFirstName = Person::firstName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& femalesFirstNames = firstNamesBySexMapping.at(Sex::Female);

    const auto generatedFirstName = Person::firstName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto language = GetParam();

    const auto& malesLastNames = languageToLastNamesMapping.at(language).at(Sex::Male);

    const auto generatedLastName = Person::lastName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto language = GetParam();

    const auto& femalesLastNames = languageToLastNamesMapping.at(language).at(Sex::Female);

    const auto generatedLastName = Person::lastName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& malesFirstNames = firstNamesBySexMapping.at(Sex::Male);
    const auto& femalesFirstNames = firstNamesBySexMapping.at(Sex::Female);

    const auto& lastNamesBySexMapping = languageToLastNamesMapping.at(language);

    const auto& malesLastNames = lastNamesBySexMapping.at(Sex::Male);
    const auto& femalesLastNames = lastNamesBySexMapping.at(Sex::Female);

    std::vector<std::string> firstNames{malesFirstNames};
    std::vector<std::string> lastNames{malesLastNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = Person::fullName(language);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.starts_with(firstName); }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.ends_with(lastName); }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& malesFirstNames = firstNamesBySexMapping.at(Sex::Male);

    const auto& malesLastNames = languageToLastNamesMapping.at(language).at(Sex::Male);

    const auto generatedFullName = Person::fullName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.starts_with(firstName); }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.ends_with(lastName); }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto language = GetParam();

    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    const auto& femalesFirstNames = firstNamesBySexMapping.at(Sex::Female);

    const auto& femalesLastNames = languageToLastNamesMapping.at(language).at(Sex::Female);

    const auto generatedFullName = Person::fullName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.starts_with(firstName); }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.ends_with(lastName); }));
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

TEST_F(PersonTest, shouldGenerateNationality)
{
    const auto generatedNationality = Person::nationality();

    ASSERT_TRUE(std::ranges::any_of(nationalities, [generatedNationality](const std::string& nationality)
                                    { return generatedNationality == nationality; }));
}
