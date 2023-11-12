#include "faker-cxx/Person.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "data/english/EnglishPeopleNames.h"
#include "data/finnish/FinnishPeopleNames.h"
#include "data/french/FrenchPeopleNames.h"
#include "data/Gender.h"
#include "data/german/GermanPeopleNames.h"
#include "data/Hobbies.h"
#include "data/indian/IndianPeopleNames.h"
#include "data/italian/ItalianPeopleNames.h"
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
#include "data/turkish/TurkishFirstNamesFemales.h"
#include "data/turkish/TurkishFirstNamesMales.h"
#include "data/turkish/TurkishLastNames.h"
#include "data/ZodiacSigns.h"
#include "data/nepalese/NepalesePeopleNames.h"
#include "data/polish/PolishPeopleNames.h"
#include "data/romanian/RomanianPeopleNames.h"
#include "data/russian/RussianPeopleNames.h"
#include "data/spanish/SpanishPeopleNames.h"
#include "data/turkish/TurkishPeopleNames.h"
#include "src/modules/person/data/PeopleNames.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Language, PeopleNames> languageToPeopleNamesMapping{
    {Language::English, englishPeopleNames},   {Language::French, frenchPeopleNames},
    {Language::German, germanPeopleNames},     {Language::Italian, italianPeopleNames},
    {Language::Polish, polishPeopleNames},     {Language::Russian, russianPeopleNames},
    {Language::Romanian, romanianPeopleNames}, {Language::Hindi, indianPeopleNames},
    {Language::Finnish, finnishPeopleNames},   {Language::Nepali, nepalesePeopleNames},
    {Language::Spanish, spanishPeopleNames},   {Language::Turkish, turkishPeopleNames},
};

const std::map<Language, std::string> generatedTestName{
    {Language::English, "shouldGenerateEnglishName"},   {Language::French, "shouldGenerateFrenchName"},
    {Language::German, "shouldGenerateGermanName"},     {Language::Italian, "shouldGenerateItalianName"},
    {Language::Polish, "shouldGeneratePolishName"},     {Language::Russian, "shouldGenerateRussianName"},
    {Language::Romanian, "shouldGenerateRomanianName"}, {Language::Hindi, "shouldGenerateIndianName"},
    {Language::Finnish, "shouldGenerateFinnishName"},   {Language::Nepali, "shouldGenerateNepaleseName"},
    {Language::Spanish, "shouldGenerateSpanishName"},   {Language::Turkish, "shouldGenerateTurkishName"},
};
}

class PersonTest : public TestWithParam<Language>
{
public:
    PersonTest()
    {
        initializePrefixes();

        initializeSuffixes();

        initializeMiddleNames();
    }

    void initializePrefixes()
    {
        for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
        {
            malesPrefixes.insert(malesPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                                 peopleNames.malesNames.prefixes.end());

            femalesPrefixes.insert(femalesPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                                   peopleNames.femalesNames.prefixes.end());

            allPrefixes.insert(allPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                               peopleNames.malesNames.prefixes.end());
            allPrefixes.insert(allPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                               peopleNames.femalesNames.prefixes.end());
        }
    }

    void initializeSuffixes()
    {
        for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
        {
            malesSuffixes.insert(malesSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                                 peopleNames.malesNames.suffixes.end());

            femalesSuffixes.insert(femalesSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                                   peopleNames.femalesNames.suffixes.end());

            allSuffixes.insert(allSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                               peopleNames.malesNames.suffixes.end());
            allSuffixes.insert(allSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                               peopleNames.femalesNames.suffixes.end());
        }
    }

    void initializeMiddleNames()
    {
        for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
        {
            malesMiddleNames.insert(malesMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                                    peopleNames.malesNames.middleNames.end());

            femalesMiddleNames.insert(femalesMiddleNames.end(), peopleNames.femalesNames.middleNames.begin(),
                                      peopleNames.femalesNames.middleNames.end());

            allMiddleNames.insert(allMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                                  peopleNames.malesNames.middleNames.end());
            allMiddleNames.insert(allMiddleNames.end(), peopleNames.femalesNames.middleNames.begin(),
                                  peopleNames.femalesNames.middleNames.end());
        }
    }

    std::vector<std::string> allPrefixes;
    std::vector<std::string> malesPrefixes;
    std::vector<std::string> femalesPrefixes;
    std::vector<std::string> allSuffixes;
    std::vector<std::string> malesSuffixes;
    std::vector<std::string> femalesSuffixes;
    std::vector<std::string> allMiddleNames;
    std::vector<std::string> malesMiddleNames;
    std::vector<std::string> femalesMiddleNames;
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    std::vector<std::string> firstNames{malesFirstNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = Person::firstName(language);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = Person::firstName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = Person::firstName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = Person::lastName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = Person::lastName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string> firstNames{malesFirstNames};
    std::vector<std::string> lastNames{malesLastNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = Person::fullName(language);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = Person::fullName(language, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto language = GetParam();

    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = Person::fullName(language, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByLanguages, PersonTest, ValuesIn(languages),
                         [](const TestParamInfo<Language>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateMiddleName)
{
    const auto generatedMiddleName = Person::middleName();

    ASSERT_TRUE(std::ranges::any_of(allMiddleNames, [generatedMiddleName](const std::string& middleName)
                                    { return middleName == generatedMiddleName; }));
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

    ASSERT_TRUE(std::ranges::any_of(malesPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = Person::suffix();

    ASSERT_TRUE(std::ranges::any_of(allSuffixes, [generatedSuffix](const std::string& suffix)
                                    { return suffix == generatedSuffix; }));
}

TEST_F(PersonTest, shouldGenerateSex)
{
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

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    const auto generatedWesternZodiacs = Person::westernZodiac();

    ASSERT_TRUE(std::ranges::any_of(westernZodiacs, [generatedWesternZodiacs](const std::string& westernZodiac)
                                    { return generatedWesternZodiacs == westernZodiac;}));

}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = Person::chineseZodiac();

    ASSERT_TRUE(std::ranges::any_of(chineseZodiacs, [generatedChineseZodiacs](const std::string& chineseZodiac)
                                    { return generatedChineseZodiacs == chineseZodiac;}));
}