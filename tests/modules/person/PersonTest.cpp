#include "faker-cxx/Person.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

#include "faker-cxx/Internet.h"
#include "faker-cxx/types/Country.h"
#include "person/PersonData.h"
#include "StringHelper.h"
#include "word/data/Nouns.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::vector<Country> countries{
    Country::Usa,       Country::England,     Country::Poland,      Country::Italy,     Country::France,
    Country::Germany,   Country::Russia,      Country::Romania,     Country::India,     Country::Finland,
    Country::Nepal,     Country::Spain,       Country::Turkey,      Country::Czech,     Country::Slovakia,
    Country::Ukraine,   Country::Denmark,     Country::Sweden,      Country::Brazil,    Country::Norway,
    Country::Japan,     Country::Portugal,    Country::Hungary,     Country::Croatia,   Country::Greece,
    Country::Slovenia,  Country::Austria,     Country::Switzerland, Country::Belgium,   Country::Netherlands,
    Country::China,     Country::Korea,       Country::Canada,      Country::Mexico,    Country::Argentina,
    Country::Australia, Country::Serbia,      Country::Macedonia,   Country::Albania,   Country::Latvia,
    Country::Ireland,   Country::Belarus,     Country::Estonia,     Country::Iran,      Country::Bulgaria,
    Country::Moldova,   Country::Lithuania,   Country::Iceland,     Country::Palestine, Country::Israel,
    Country::Vietnam,   Country::Monaco,      Country::Bosnia,      Country::Lebanon,   Country::Syria,
    Country::Malta,     Country::SouthAfrica, Country::Azerbaijan,  Country::Ghana,     Country::Kazakhstan,
    Country::Maldives,
};

const PeopleNames& getPeopleNamesByCountry(const Country& country)
{
    switch (country)
    {
    case Country::England:
        return englishPeopleNames;
    case Country::France:
        return frenchPeopleNames;
    case Country::Germany:
        return germanPeopleNames;
    case Country::Italy:
        return italianPeopleNames;
    case Country::Poland:
        return polishPeopleNames;
    case Country::Russia:
        return russianPeopleNames;
    case Country::Romania:
        return romanianPeopleNames;
    case Country::India:
        return indianPeopleNames;
    case Country::Finland:
        return finnishPeopleNames;
    case Country::Nepal:
        return nepalesePeopleNames;
    case Country::Spain:
        return spanishPeopleNames;
    case Country::Turkey:
        return turkishPeopleNames;
    case Country::Czech:
        return czechPeopleNames;
    case Country::Slovakia:
        return slovakPeopleNames;
    case Country::Ukraine:
        return ukrainianPeopleNames;
    case Country::Denmark:
        return danishPeopleNames;
    case Country::Sweden:
        return swedishPeopleNames;
    case Country::Usa:
        return usaPeopleNames;
    case Country::Brazil:
        return brazilianPeopleNames;
    case Country::Norway:
        return norwegianPeopleNames;
    case Country::Japan:
        return japanesePeopleNames;
    case Country::Portugal:
        return portuguesePeopleNames;
    case Country::Hungary:
        return hungarianPeopleNames;
    case Country::Croatia:
        return croatianPeopleNames;
    case Country::Greece:
        return greekPeopleNames;
    case Country::Slovenia:
        return slovenianPeopleNames;
    case Country::Austria:
        return austrianPeopleNames;
    case Country::Switzerland:
        return swissPeopleNames;
    case Country::Belgium:
        return belgianPeopleNames;
    case Country::Netherlands:
        return dutchPeopleNames;
    case Country::China:
        return chinesePeopleNames;
    case Country::Korea:
        return koreanPeopleNames;
    case Country::Canada:
        return canadianPeopleNames;
    case Country::Mexico:
        return mexicanPeopleNames;
    case Country::Argentina:
        return argentinianPeopleNames;
    case Country::Australia:
        return australianPeopleNames;
    case Country::Serbia:
        return serbianPeopleNames;
    case Country::Macedonia:
        return macedonianPeopleNames;
    case Country::Latvia:
        return latvianPeopleNames;
    case Country::Ireland:
        return irishPeopleNames;
    case Country::Belarus:
        return belarusianPeopleNames;
    case Country::Estonia:
        return estonianPeopleNames;
    case Country::Albania:
        return albanianPeopleNames;
    case Country::Iran:
        return persianPeopleNames;
    case Country::Bulgaria:
        return bulgarianPeopleNames;
    case Country::Moldova:
        return moldovanPeopleNames;
    case Country::Bosnia:
        return bosnianPeopleNames;
    case Country::Lithuania:
        return lithuanianPeopleNames;
    case Country::Iceland:
        return icelandicPeopleNames;
    case Country::Palestine:
        return palestinianPeopleNames;
    case Country::Israel:
        return israeliPeopleNames;
    case Country::Vietnam:
        return vietnamesePeopleNames;
    case Country::Monaco:
        return monacanPeopleNames;
    case Country::Lebanon:
        return lebanesePeopleNames;
    case Country::Syria:
        return syrianPeopleNames;
    case Country::Malta:
        return maltesePeopleNames;
    case Country::SouthAfrica:
        return southAfricanPeopleNames;
    case Country::Azerbaijan:
        return azerbaijaniPeopleNames;
    case Country::Ghana:
        return ghanaianPeopleNames;
    case Country::Kazakhstan:
        return kazakhPeopleNames;
    case Country::Maldives:
        return maldiviansPeopleNames;
    default:
        throw std::runtime_error{"Country not found."};
    }
}

const std::unordered_map<Country, std::string> generatedTestName{
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

std::string_view translateSex(Sex sex, Language language = Language::English)
{
    const auto sexTranslation = sexTranslations.find(language);

    if (sexTranslation == sexTranslations.end())
    {
        throw std::runtime_error{"Sex not found."};
    }

    return sexTranslation->second.at(sex);
}

bool checkTokenFormat(const std::string& bio);

class PersonTest : public TestWithParam<Country>
{
public:
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    std::vector<std::string> firstNames(malesFirstNames.begin(), malesFirstNames.end());

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = Person::firstName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string_view& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string_view& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string_view> firstNames(malesFirstNames.begin(), malesFirstNames.end());
    std::vector<std::string_view> lastNames(malesLastNames.begin(), malesLastNames.end());

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = Person::fullName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPeopleNamesByCountry(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
                         [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

// TODO: move to parameterized tests
TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = Person::prefix();

    std::vector<std::string_view> prefixes(englishMalePrefixes.begin(), englishMalePrefixes.end());

    prefixes.insert(prefixes.end(), englishFemalePrefixes.begin(), englishFemalePrefixes.end());

    ASSERT_TRUE(std::ranges::any_of(prefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return prefix == generatedPrefix; }));
}

// TODO: move to parameterized tests
TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = Person::prefix(std::nullopt, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(englishMalePrefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = Person::prefix(std::nullopt, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(englishFemalePrefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = Person::suffix();

    ASSERT_TRUE(std::ranges::any_of(englishSuffixes, [generatedSuffix](const std::string_view& suffix)
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

    ASSERT_TRUE(std::ranges::any_of(genders, [generatedGender](const std::string_view& gender)
                                    { return gender == generatedGender; }));
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = Person::jobDescriptor();

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string_view& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = Person::jobArea();

    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                    { return jobArea == generatedJobArea; }));
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = Person::jobType();

    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string_view& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = Person::jobTitle();

    const auto jobTitleElements = StringHelper::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string_view& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                    { return jobArea == generatedJobArea; }));
    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string_view& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = Person::hobby();

    ASSERT_TRUE(std::ranges::any_of(hobbies, [generatedHobby](const std::string_view& hobby)
                                    { return hobby == generatedHobby; }));
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = Person::bio();

    ASSERT_TRUE(checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    const auto generatedLanguage = Person::language();

    ASSERT_TRUE(std::ranges::any_of(languages, [generatedLanguage](const std::string_view& language)
                                    { return generatedLanguage == language; }));
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    const auto generatedNationality = Person::nationality();

    ASSERT_TRUE(std::ranges::any_of(nationalities, [generatedNationality](const std::string_view& nationality)
                                    { return generatedNationality == nationality; }));
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    const auto generatedWesternZodiacs = Person::westernZodiac();

    ASSERT_TRUE(std::ranges::any_of(westernZodiacs, [generatedWesternZodiacs](const std::string_view& westernZodiac)
                                    { return generatedWesternZodiacs == westernZodiac; }));
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = Person::chineseZodiac();

    ASSERT_TRUE(std::ranges::any_of(chineseZodiacs, [generatedChineseZodiacs](const std::string_view& chineseZodiac)
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

std::string toString(Sex sex, Language language = Language::English)
{
    const auto sexTranslation = sexTranslations.find(language);

    if (sexTranslation == sexTranslations.end())
    {
        throw std::runtime_error{"Sex not found."};
    }

    return std::string{sexTranslation->second.at(sex)};
}

std::string toString(Language language)
{
    static const std::unordered_map<Language, std::string> languageToStringMapping{
        {Language::English, "English"},     {Language::Polish, "Polish"},         {Language::Italian, "Italian"},
        {Language::French, "French"},       {Language::German, "German"},         {Language::Russian, "Russian"},
        {Language::Romanian, "Romanian"},   {Language::Hindi, "Hindi"},           {Language::Finnish, "Finnish"},
        {Language::Nepali, "Nepali"},       {Language::Spanish, "Spanish"},       {Language::Turkish, "Turkish"},
        {Language::Czech, "Czech"},         {Language::Slovak, "Slovak"},         {Language::Ukrainian, "Ukrainian"},
        {Language::Danish, "Danish"},       {Language::Swedish, "Swedish"},       {Language::Portuguese, "Portuguese"},
        {Language::Norwegian, "Norwegian"}, {Language::Japanese, "Japanese"},     {Language::Hungarian, "Hungarian"},
        {Language::Croatian, "Croatian"},   {Language::Greek, "Greek"},           {Language::Slovene, "Slovene"},
        {Language::Dutch, "Dutch"},         {Language::Mandarin, "Mandarin"},     {Language::Korean, "Korean"},
        {Language::Serbian, "Serbian"},     {Language::Macedonian, "Macedonian"}, {Language::Albanian, "Albanian"},
        {Language::Latvian, "Latvian"},     {Language::Irish, "Irish"},           {Language::Belarusian, "Belarusian"},
        {Language::Estonian, "Estonian"}};

    return languageToStringMapping.at(language);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, testing::ValuesIn(languageSexPairs),
                         [](const testing::TestParamInfo<PersonSexSuite::ParamType>& info)
                         {
                             auto param = info.param;
                             return toString(param.first) + "_" + toString(param.second);
                         });

const std::unordered_map<SsnCountry, unsigned> ssnLengths{
    {SsnCountry::Poland, 11}, {SsnCountry::Usa, 11},   {SsnCountry::England, 13}, {SsnCountry::Germany, 12},
    {SsnCountry::France, 19}, {SsnCountry::Italy, 19}, {SsnCountry::Spain, 10},   {SsnCountry::India, 10},
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

std::string toString(SsnCountry country)
{
    std::unordered_map<SsnCountry, std::string> countryToStringMapping{
        {SsnCountry::Usa, "Usa"},     {SsnCountry::England, "England"}, {SsnCountry::Poland, "Poland"},
        {SsnCountry::Italy, "Italy"}, {SsnCountry::France, "France"},   {SsnCountry::Germany, "Germany"},
        {SsnCountry::India, "India"}, {SsnCountry::Spain, "Spain"},
    };

    return countryToStringMapping.at(country);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite, testing::ValuesIn(supportedSsnCountries),
                         [](const testing::TestParamInfo<PersonSsnSuite::ParamType>& info)
                         { return "shouldGenerate" + toString(info.param) + "Ssn"; });

class PersonPassportTest : public Test
{
public:
};

TEST_F(PersonPassportTest, shouldGenerateUsaPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Usa);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isalpha(passportNumber[0]));
    ASSERT_TRUE(std::isalpha(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGeneratePolandPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Poland);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isalpha(passportNumber[0]));
    ASSERT_TRUE(std::isalpha(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGenerateFrenchPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::France);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isdigit(passportNumber[0]));
    ASSERT_TRUE(std::isdigit(passportNumber[1]));
    ASSERT_TRUE(std::isalpha(passportNumber[2]));
    ASSERT_TRUE(std::isalpha(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGenerateRomanianPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Romania);
    ASSERT_EQ(passportNumber.size(), 8);
    ASSERT_TRUE(std::isdigit(passportNumber[0]));
    ASSERT_TRUE(std::isdigit(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
}

bool checkTokenFormat(const std::string& bio)
{
    const std::regex firstRegex{R"(^(\w+\s?\w+)$)"};
    const std::regex secondRegex{R"(^(\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex thirdRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex fourthRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)"};
    const std::regex fifthRegex{R"(^(\w+\-?\w+) (\w+)$)"};
    const std::regex sixthRegex{R"(^(\w+\-?\w+) (\w+) (\S+)$)"};
    const std::regex seventhRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)"};
    const std::regex eightRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)"};

    std::smatch matches;
    //
    if (std::regex_match(bio, matches, firstRegex))
    {
        // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part
        // vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string{matches[0]}) != bioParts.end())
        {
            return true;
        }
    }

    if (std::regex_match(bio, matches, secondRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is present in the
        // bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string{matches[1]}) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[2]}) != bioParts.end())
        {
            return true;
        }
    }

    if (std::regex_match(bio, matches, thirdRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string{matches[1]}) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[2]}) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[3]}) != bioParts.end())
            return true;
    }

    if (std::regex_match(bio, matches, fourthRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string{matches[1]}) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[2]}) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[3]}) != bioParts.end() &&
            Internet::checkIfEmojiIsValid(std::string{matches[4]}))
            return true;
    }

    if (std::regex_match(bio, matches, fifthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is present
        // in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string{matches[1]}) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string{matches[2]}) != bioSupporters.end())
            return true;
    }

    if (std::regex_match(bio, matches, sixthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string{matches[1]}) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string{matches[2]}) != bioSupporters.end() &&
            Internet::checkIfEmojiIsValid(std::string{matches[3]}))
            return true;
    }

    if (std::regex_match(bio, matches, seventhRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(word::nouns.begin(),  word::nouns.end(), std::string{matches[1]}) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string{matches[2]}) != bioSupporters.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[3]}) != bioParts.end())
            return true;
    }

    if (std::regex_match(bio, matches, eightRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string{matches[1]}) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string{matches[2]}) != bioSupporters.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string{matches[3]}) != bioParts.end() &&
            Internet::checkIfEmojiIsValid(std::string{matches[4]}))
            return true;
    }

    return false;
}
