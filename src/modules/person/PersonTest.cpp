#include "faker-cxx/Person.h"

#include <algorithm>
#include <regex>

#include "gtest/gtest.h"

#include "../word/data/Nouns.h"
#include "data/albania/AlbanianPeopleNames.h"
#include "data/argentina/ArgentinianPeopleNames.h"
#include "data/australia/AustralianPeopleNames.h"
#include "data/austria/AustrianPeopleNames.h"
#include "data/azerbaijan/AzerbaijaniPeopleNames.h"
#include "data/belarus/BelarusianPeopleNames.h"
#include "data/belgium/BelgianPeopleNames.h"
#include "data/Bio.h"
#include "data/bosnia/BosnianPeopleNames.h"
#include "data/brazil/BrazilianPeopleNames.h"
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
#include "data/ghana/GhanaianPeopleNames.h"
#include "data/greece/GreekPeopleNames.h"
#include "data/Hobbies.h"
#include "data/hungary/HungarianPeopleNames.h"
#include "data/iceland/IcelandicPeopleNames.h"
#include "data/india/IndianPeopleNames.h"
#include "data/iran/PersianPeopleNames.h"
#include "data/ireland/IrishPeopleNames.h"
#include "data/israel/IsraeliPeopleNames.h"
#include "data/italy/ItalianPeopleNames.h"
#include "data/japan/JapanesePeopleNames.h"
#include "data/JobTitles.h"
#include "data/kazakhstan/KazakhPeopleNames.h"
#include "data/korea/KoreanPeopleNames.h"
#include "data/Languages.h"
#include "data/latvia/LatvianPeopleNames.h"
#include "data/lebanon/LebanesePeopleNames.h"
#include "data/lithuania/LithuanianPeopleNames.h"
#include "data/macedonia/MacedonianPeopleNames.h"
#include "data/maldives/MaldiviansPeopleNames.h"
#include "data/malta/MaltesePeopleNames.h"
#include "data/mexico/MexicanPeopleNames.h"
#include "data/moldova/MoldovanPeopleNames.h"
#include "data/monaco/MonacanPeopleNames.h"
#include "data/Nationalities.h"
#include "data/nepal/NepalesePeopleNames.h"
#include "data/netherlands/DutchPeopleNames.h"
#include "data/norway/NorwegianPeopleNames.h"
#include "data/palestine/PalestinianPeopleNames.h"
#include "data/PeopleNames.h"
#include "data/poland/PolishPeopleNames.h"
#include "data/portugal/PortuguesePeopleNames.h"
#include "data/romania/RomanianPeopleNames.h"
#include "data/russia/RussianPeopleNames.h"
#include "data/serbia/SerbianPeopleNames.h"
#include "data/slovakia/SlovakPeopleNames.h"
#include "data/slovenia/SlovenianPeopleNames.h"
#include "data/southAfrica/SouthAfricanPeopleNames.h"
#include "data/spain/SpanishPeopleNames.h"
#include "data/sweden/SwedishPeopleNames.h"
#include "data/switzerland/SwissPeopleNames.h"
#include "data/syria/SyrianPeopleNames.h"
#include "data/turkey/TurkishPeopleNames.h"
#include "data/ukraine/UkrainianPeopleNames.h"
#include "data/usa/UsaPeopleNames.h"
#include "data/vietnam/VietnamesePeopleNames.h"
#include "data/ZodiacSigns.h"
#include "faker-cxx/Internet.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Country, PeopleNames> countryToPeopleNamesMapping{
    {Country::England, englishPeopleNames},
    {Country::France, frenchPeopleNames},
    {Country::Germany, germanPeopleNames},
    {Country::Italy, italianPeopleNames},
    {Country::Poland, polishPeopleNames},
    {Country::Russia, russianPeopleNames},
    {Country::Romania, romanianPeopleNames},
    {Country::India, indianPeopleNames},
    {Country::Finland, finnishPeopleNames},
    {Country::Nepal, nepalesePeopleNames},
    {Country::Spain, spanishPeopleNames},
    {Country::Turkey, turkishPeopleNames},
    {Country::Czech, czechPeopleNames},
    {Country::Slovakia, slovakPeopleNames},
    {Country::Ukraine, ukrainianPeopleNames},
    {Country::Denmark, danishPeopleNames},
    {Country::Sweden, swedishPeopleNames},
    {Country::Usa, usaPeopleNames},
    {Country::Brazil, brazilianPeopleNames},
    {Country::Norway, norwegianPeopleNames},
    {Country::Japan, japanesePeopleNames},
    {Country::Portugal, portuguesePeopleNames},
    {Country::Hungary, hungarianPeopleNames},
    {Country::Croatia, croatianPeopleNames},
    {Country::Greece, greekPeopleNames},
    {Country::Slovenia, slovenianPeopleNames},
    {Country::Austria, austrianPeopleNames},
    {Country::Switzerland, swissPeopleNames},
    {Country::Belgium, belgianPeopleNames},
    {Country::Netherlands, dutchPeopleNames},
    {Country::China, chinesePeopleNames},
    {Country::Korea, koreanPeopleNames},
    {Country::Canada, canadianPeopleNames},
    {Country::Mexico, mexicanPeopleNames},
    {Country::Argentina, argentinianPeopleNames},
    {Country::Australia, australianPeopleNames},
    {Country::Serbia, serbianPeopleNames},
    {Country::Macedonia, macedonianPeopleNames},
    {Country::Latvia, latvianPeopleNames},
    {Country::Ireland, irishPeopleNames},
    {Country::Belarus, belarusianPeopleNames},
    {Country::Estonia, estonianPeopleNames},
    {Country::Albania, albanianPeopleNames},
    {Country::Iran, persianPeopleNames},
    {Country::Bulgaria, bulgarianPeopleNames},
    {Country::Moldova, moldovanPeopleNames},
    {Country::Lithuania, lithuanianPeopleNames},
    {Country::Iceland, icelandicPeopleNames},
    {Country::Palestine, palestinianPeopleNames},
    {Country::Israel, israeliPeopleNames},
    {Country::Vietnam, vietnamesePeopleNames},
    {Country::Monaco, monacanPeopleNames},
    {Country::Bosnia, bosnianPeopleNames},
    {Country::Lebanon, lebanesePeopleNames},
    {Country::Syria, syrianPeopleNames},
    {Country::Malta, maltesePeopleNames},
    {Country::SouthAfrica, southAfricanPeopleNames},
    {Country::Azerbaijan, azerbaijaniPeopleNames},
    {Country::Ghana, ghanaianPeopleNames},
    {Country::Kazakhstan, kazakhPeopleNames},
    {Country::Maldives, maldiviansPeopleNames},
};

const std::map<Country, std::string> generatedTestName{
    {Country::England, "shouldGenerateEnglishName"},
    {Country::France, "shouldGenerateFrenchName"},
    {Country::Germany, "shouldGenerateGermanName"},
    {Country::Italy, "shouldGenerateItalianName"},
    {Country::Poland, "shouldGeneratePolishName"},
    {Country::Russia, "shouldGenerateRussianName"},
    {Country::Romania, "shouldGenerateRomanianName"},
    {Country::India, "shouldGenerateIndianName"},
    {Country::Finland, "shouldGenerateFinnishName"},
    {Country::Nepal, "shouldGenerateNepaleseName"},
    {Country::Spain, "shouldGenerateSpanishName"},
    {Country::Turkey, "shouldGenerateTurkishName"},
    {Country::Czech, "shouldGenerateCzechName"},
    {Country::Slovakia, "shouldGenerateSlovakName"},
    {Country::Ukraine, "shouldGenerateUkrainianName"},
    {Country::Denmark, "shouldGenerateDanishName"},
    {Country::Sweden, "shouldGenerateSwedishName"},
    {Country::Usa, "shouldGenerateAmericanName"},
    {Country::Brazil, "shouldGenerateBrazilianName"},
    {Country::Norway, "shouldGenerateNorwegianName"},
    {Country::Japan, "shouldGenerateJapaneseName"},
    {Country::Portugal, "shouldGeneratePortugueseName"},
    {Country::Hungary, "shouldGenerateHungarianName"},
    {Country::Croatia, "shouldGenerateCroatianName"},
    {Country::Greece, "shouldGenerateGreekName"},
    {Country::Slovenia, "shouldGenerateSlovenianName"},
    {Country::Austria, "shouldGenerateAustrianName"},
    {Country::Switzerland, "shouldGenerateSwissName"},
    {Country::Belgium, "shouldGenerateBelgianName"},
    {Country::Netherlands, "shouldGenerateDutchName"},
    {Country::China, "shouldGenerateChineseName"},
    {Country::Korea, "shouldGenerateKoreanName"},
    {Country::Canada, "shouldGenerateCanadianName"},
    {Country::Mexico, "shouldGenerateMexicanName"},
    {Country::Argentina, "shouldGenerateArgentinianName"},
    {Country::Australia, "shouldGenerateAustralianName"},
    {Country::Serbia, "shouldGenerateSerbianName"},
    {Country::Macedonia, "shouldGenerateMacedonianName"},
    {Country::Latvia, "shouldGenerateLatvianName"},
    {Country::Ireland, "shouldGenerateIrishName"},
    {Country::Belarus, "shouldGenerateBelarusianName"},
    {Country::Estonia, "shouldGenerateEstonianName"},
    {Country::Albania, "shouldGenerateAlbanianName"},
    {Country::Iran, "shouldGeneratePersianName"},
    {Country::Bulgaria, "shouldGenerateBulgarianName"},
    {Country::Moldova, "shouldGenerateMoldovanName"},
    {Country::Lithuania, "shouldGenerateLithuanianName"},
    {Country::Iceland, "shouldGenerateIcelandicName"},
    {Country::Palestine, "shouldGeneratePalestinianName"},
    {Country::Israel, "shouldGenerateIsraeliName"},
    {Country::Vietnam, "shouldGenerateVietnameseName"},
    {Country::Monaco, "shouldGenerateMonacanName"},
    {Country::Bosnia, "shouldGenerateBosnianNames"},
    {Country::Lebanon, "shouldGenerateLebaneseName"},
    {Country::Syria, "shouldGenerateSyrianName"},
    {Country::Malta, "shouldGenerateMalteseName"},
    {Country::SouthAfrica, "shouldGenerateSouthAfricanName"},
    {Country::Azerbaijan, "shouldGenerateAzerbaijaniName"},
    {Country::Ghana, "shouldGenerateGhanaianName"},
    {Country::Kazakhstan, "shouldGenerateKazakhName"},
    {Country::Maldives, "shouldGenerateMaldivianName"},
};
}

bool checkTokenFormat(const std::string& bio);

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

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = Person::bio();

    ASSERT_TRUE(checkTokenFormat(generatedBio));
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

class PersonSexSuite : public TestWithParam<std::pair<Language, Sex>>
{
};

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = sexTranslations.at(language).at(sex);
    const auto actualTranslation = translateSex(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<Language, Sex>> languageSexPairs = {
    {Language::English, Sex::Male},      {Language::English, Sex::Female},   {Language::Polish, Sex::Male},
    {Language::Polish, Sex::Female},     {Language::Italian, Sex::Male},     {Language::Italian, Sex::Female},
    {Language::French, Sex::Male},       {Language::French, Sex::Female},    {Language::German, Sex::Male},
    {Language::German, Sex::Female},     {Language::Russian, Sex::Male},     {Language::Russian, Sex::Female},
    {Language::Romanian, Sex::Male},     {Language::Romanian, Sex::Female},  {Language::Hindi, Sex::Male},
    {Language::Hindi, Sex::Female},      {Language::Finnish, Sex::Male},     {Language::Finnish, Sex::Female},
    {Language::Nepali, Sex::Male},       {Language::Nepali, Sex::Female},    {Language::Spanish, Sex::Male},
    {Language::Spanish, Sex::Female},    {Language::Turkish, Sex::Male},     {Language::Turkish, Sex::Female},
    {Language::Czech, Sex::Male},        {Language::Czech, Sex::Female},     {Language::Slovak, Sex::Male},
    {Language::Slovak, Sex::Female},     {Language::Ukrainian, Sex::Male},   {Language::Ukrainian, Sex::Female},
    {Language::Danish, Sex::Male},       {Language::Danish, Sex::Female},    {Language::Swedish, Sex::Male},
    {Language::Swedish, Sex::Female},    {Language::Portuguese, Sex::Male},  {Language::Portuguese, Sex::Female},
    {Language::Norwegian, Sex::Male},    {Language::Norwegian, Sex::Female}, {Language::Japanese, Sex::Male},
    {Language::Japanese, Sex::Female},   {Language::Hungarian, Sex::Male},   {Language::Hungarian, Sex::Female},
    {Language::Croatian, Sex::Male},     {Language::Croatian, Sex::Female},  {Language::Greek, Sex::Male},
    {Language::Greek, Sex::Female},      {Language::Slovene, Sex::Male},     {Language::Slovene, Sex::Female},
    {Language::Dutch, Sex::Male},        {Language::Dutch, Sex::Female},     {Language::Mandarin, Sex::Male},
    {Language::Mandarin, Sex::Female},   {Language::Korean, Sex::Male},      {Language::Korean, Sex::Female},
    {Language::Serbian, Sex::Male},      {Language::Serbian, Sex::Female},   {Language::Macedonian, Sex::Male},
    {Language::Macedonian, Sex::Female}, {Language::Albanian, Sex::Male},    {Language::Albanian, Sex::Female},
    {Language::Latvian, Sex::Male},      {Language::Latvian, Sex::Female},   {Language::Irish, Sex::Male},
    {Language::Irish, Sex::Female},      {Language::Belarusian, Sex::Male},  {Language::Belarusian, Sex::Female},
    {Language::Estonian, Sex::Male},     {Language::Estonian, Sex::Female}};

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, testing::ValuesIn(languageSexPairs),
                         [](const testing::TestParamInfo<PersonSexSuite::ParamType>& info)
                         {
                             auto param = info.param;
                             return toString(param.first) + "_" + toString(param.second);
                         });

const std::map<SsnCountry, unsigned> ssnLengths{
    {SsnCountry::Poland, 11},  {SsnCountry::UnitedStates, 11}, {SsnCountry::UnitedKingdom, 13},
    {SsnCountry::Germany, 12}, {SsnCountry::France, 19},       {SsnCountry::Italy, 19},
    {SsnCountry::Spain, 10},   {SsnCountry::India, 10},
};

class PersonSsnSuite : public TestWithParam<SsnCountry>
{
};

TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = Person::ssn(country);

    const auto expectedSsnLength = ssnLengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite, testing::ValuesIn(supportedSsnCountries),
                         [](const testing::TestParamInfo<PersonSsnSuite::ParamType>& info)
                         { return "shouldGenerate" + toString(info.param) + "Ssn"; });

bool checkTokenFormat(const std::string& bio)
{
    const std::regex firstRegex{R"(^(\w+\s?\w+)$)"};
    const std::regex secondRegex{R"(^(\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex thirdRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex fourthRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)"};
    const std::regex fifthRegex{R"(^(\w+\-?\w+) (\w+)$)"};
    const std::regex sixthRegex{R"(^(\w+\-?\w+) (\w+) (\S+)$)"};
    const std::regex seventhRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)"};
    const std::regex eigthRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)"};

    std::smatch matches;
    //
    if (std::regex_match(bio, matches, firstRegex))
    {
        // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[0]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, secondRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is present in the
        // bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, thirdRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that the value is present
        // in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, fourthRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so check that the value is
        // present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() &&
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;
    }

    if (std::regex_match(bio, matches, fifthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end())
            return true;
    }

    if (std::regex_match(bio, matches, sixthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            Internet::checkIfEmojiIsValid(matches[3]))
            return true;
    }

    if (std::regex_match(bio, matches, seventhRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, eigthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check that the value is
        // present in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() &&
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;
    }

    return false;
}
