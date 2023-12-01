#include "faker-cxx/Person.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "data/albania/AlbanianPeopleNames.h"
#include "data/argentina/ArgentinianPeopleNames.h"
#include "data/australia/AustralianPeopleNames.h"
#include "data/austria/AustrianPeopleNames.h"
#include "data/belarus/BelarusianPeopleNames.h"
#include "data/belgium/BelgianPeopleNames.h"
#include "data/bulgaria/BulgarianPeopleNames.h"
#include "data/canada/CanadianPeopleNames.h"
#include "data/china/ChinesePeopleNames.h"
#include "data/croatia/CroatianPeopleNames.h"
#include "data/czech/CzechPeopleNames.h"
#include "data/denmark/DanishPeopleNames.h"
#include "data/england/EnglishPeopleNames.h"
#include "data/estonia/EstonianPeopleNames.h"
#include "data/finland/FinnishPeopleNames.h"
#include "data/france/FrenchPeopleNames.h"
#include "data/Gender.h"
#include "data/germany/GermanPeopleNames.h"
#include "data/greece/GreekPeopleNames.h"
#include "data/Hobbies.h"
#include "data/hungary/HungarianPeopleNames.h"
#include "data/india/IndianPeopleNames.h"
#include "data/iran/PersianPeopleNames.h"
#include "data/ireland/IrishPeopleNames.h"
#include "data/italy/ItalianPeopleNames.h"
#include "data/japan/JapanesePeopleNames.h"
#include "data/JobTitles.h"
#include "data/korea/KoreanPeopleNames.h"
#include "data/Languages.h"
#include "data/latvia/LatvianPeopleNames.h"
#include "data/macedonia/MacedonianPeopleNames.h"
#include "data/mexico/MexicanPeopleNames.h"
#include "data/Nationalities.h"
#include "data/netherlands/DutchPeopleNames.h"
#include "data/nepal/NepalesePeopleNames.h"
#include "data/norway/NorwegianPeopleNames.h"
#include "data/poland/PolishPeopleNames.h"
#include "data/portugal/PortuguesePeopleNames.h"
#include "data/romania/RomanianPeopleNames.h"
#include "data/russia/RussianPeopleNames.h"
#include "data/serbia/SerbianPeopleNames.h"
#include "data/slovakia/SlovakPeopleNames.h"
#include "data/slovenia/SlovenianPeopleNames.h"
#include "data/spain/SpanishPeopleNames.h"
#include "data/sweden/SwedishPeopleNames.h"
#include "data/switzerland/SwissPeopleNames.h"
#include "data/turkey/TurkishPeopleNames.h"
#include "data/ukraine/UkrainianPeopleNames.h"
#include "data/ZodiacSigns.h"
#include "src/modules/person/data/brazil/BrazilianPeopleNames.h"
#include "src/modules/person/data/PeopleNames.h"
#include "src/modules/person/data/usa/UsaPeopleNames.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Country, PeopleNames> countryToPeopleNamesMapping{
    {Country::England, englishPeopleNames},       {Country::France, frenchPeopleNames},
    {Country::Germany, germanPeopleNames},        {Country::Italy, italianPeopleNames},
    {Country::Poland, polishPeopleNames},         {Country::Russia, russianPeopleNames},
    {Country::Romania, romanianPeopleNames},      {Country::India, indianPeopleNames},
    {Country::Finland, finnishPeopleNames},       {Country::Nepal, nepalesePeopleNames},
    {Country::Spain, spanishPeopleNames},         {Country::Turkey, turkishPeopleNames},
    {Country::Czech, czechPeopleNames},           {Country::Slovakia, slovakPeopleNames},
    {Country::Ukraine, ukrainianPeopleNames},     {Country::Denmark, danishPeopleNames},
    {Country::Sweden, swedishPeopleNames},        {Country::Usa, usaPeopleNames},
    {Country::Brazil, brazilianPeopleNames},      {Country::Bulgaria, bulgarianPeopleNames},
    {Country::Norway, norwegianPeopleNames},
    {Country::Japan, japanesePeopleNames},        {Country::Portugal, portuguesePeopleNames},
    {Country::Hungary, hungarianPeopleNames},     {Country::Croatia, croatianPeopleNames},
    {Country::Greece, greekPeopleNames},          {Country::Slovenia, slovenianPeopleNames},
    {Country::Austria, austrianPeopleNames},      {Country::Switzerland, swissPeopleNames},
    {Country::Belgium, belgianPeopleNames},       {Country::Netherlands, dutchPeopleNames},
    {Country::China, chinesePeopleNames},         {Country::Korea, koreanPeopleNames},
    {Country::Canada, canadianPeopleNames},       {Country::Mexico, mexicanPeopleNames},
    {Country::Argentina, argentinianPeopleNames}, {Country::Australia, australianPeopleNames},
    {Country::Serbia, serbianPeopleNames},        {Country::Macedonia, macedonianPeopleNames},
    {Country::Latvia, latvianPeopleNames},        {Country::Ireland, irishPeopleNames},
    {Country::Belarus, belarusianPeopleNames},    {Country::Estonia, estonianPeopleNames},
    {Country::Albania, albanianPeopleNames},      {Country::Iran,persianPeopleNames}};

const std::map<Country, std::string> generatedTestName{
    {Country::England, "shouldGenerateEnglishName"},       {Country::France, "shouldGenerateFrenchName"},
    {Country::Germany, "shouldGenerateGermanName"},        {Country::Italy, "shouldGenerateItalianName"},
    {Country::Poland, "shouldGeneratePolishName"},         {Country::Russia, "shouldGenerateRussianName"},
    {Country::Romania, "shouldGenerateRomanianName"},      {Country::India, "shouldGenerateIndianName"},
    {Country::Finland, "shouldGenerateFinnishName"},       {Country::Nepal, "shouldGenerateNepaleseName"},
    {Country::Spain, "shouldGenerateSpanishName"},         {Country::Turkey, "shouldGenerateTurkishName"},
    {Country::Czech, "shouldGenerateCzechName"},           {Country::Slovakia, "shouldGenerateSlovakName"},
    {Country::Ukraine, "shouldGenerateUkrainianName"},     {Country::Denmark, "shouldGenerateDanishName"},
    {Country::Sweden, "shouldGenerateSwedishName"},        {Country::Usa, "shouldGenerateAmericanName"},
    {Country::Brazil, "shouldGenerateBrazilianName"},      {Country::Norway, "shouldGenerateNorwegianName"},
    {Country::Japan, "shouldGenerateJapaneseName"},        {Country::Portugal, "shouldGeneratePortugueseName"},
    {Country::Hungary, "shouldGenerateHungarianName"},     {Country::Croatia, "shouldGenerateCroatianName"},
    {Country::Greece, "shouldGenerateGreekName"},          {Country::Slovenia, "shouldGenerateSlovenianName"},
    {Country::Austria, "shouldGenerateAustrianName"},      {Country::Switzerland, "shouldGenerateSwissName"},
    {Country::Belgium, "shouldGenerateBelgianName"},       {Country::Netherlands, "shouldGenerateDutchName"},
    {Country::China, "shouldGenerateChineseName"},         {Country::Korea, "shouldGenerateKoreanName"},
    {Country::Canada, "shouldGenerateCanadianName"},       {Country::Mexico, "shouldGenerateMexicanName"},
    {Country::Argentina, "shouldGenerateArgentinianName"}, {Country::Australia, "shouldGenerateAustralianName"},
    {Country::Serbia, "shouldGenerateSerbianName"},        {Country::Macedonia, "shouldGenerateMacedonianName"},
    {Country::Latvia, "shouldGenerateLatvianName"},        {Country::Ireland, "shouldGenerateIrishName"},
    {Country::Belarus, "shouldGenerateBelarusianName"},    {Country::Estonia, "shouldGenerateEstonianName"},
    {Country::Albania, "shouldGenerateAlbanianName"},      {Country::Iran, "shouldGeneratePersianName"}};
}

class PersonTest : public TestWithParam<Country>
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
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
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
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
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
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
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
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    std::vector<std::string> firstNames{malesFirstNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = Person::firstName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string> firstNames{malesFirstNames};
    std::vector<std::string> lastNames{malesLastNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = Person::fullName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
                         [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

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

    ASSERT_TRUE(std::ranges::any_of(languages, [generatedLanguage](const std::string& language)
                                    { return generatedLanguage == language; }));
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
                                    { return generatedWesternZodiacs == westernZodiac; }));
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = Person::chineseZodiac();

    ASSERT_TRUE(std::ranges::any_of(chineseZodiacs, [generatedChineseZodiacs](const std::string& chineseZodiac)
                                    { return generatedChineseZodiacs == chineseZodiac; }));
}
