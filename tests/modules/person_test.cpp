#include "../test_helpers.h"
#include <algorithm>
#include <common/bio_helper.h>
#include <common/string_helper.h>
#include <faker/person.h>
#include <modules/person_data.h>

using namespace ::testing;
using namespace faker;

namespace {
const std::vector<std::string> sexes { "Male", "Female" };

const std::unordered_map<Country, std::string> generatedTestName {
    { Country::England, "shouldGenerateEnglishName" },
    { Country::France, "shouldGenerateFrenchName" },
    { Country::Germany, "shouldGenerateGermanName" },
    { Country::Italy, "shouldGenerateItalianName" },
    { Country::Poland, "shouldGeneratePolishName" },
    { Country::Russia, "shouldGenerateRussianName" },
    { Country::Romania, "shouldGenerateRomanianName" },
    { Country::India, "shouldGenerateIndianName" },
    { Country::Finland, "shouldGenerateFinnishName" },
    { Country::Nepal, "shouldGenerateNepaleseName" },
    { Country::Spain, "shouldGenerateSpanishName" },
    { Country::Turkey, "shouldGenerateTurkishName" },
    { Country::Czech, "shouldGenerateCzechName" },
    { Country::Slovakia, "shouldGenerateSlovakName" },
    { Country::Ukraine, "shouldGenerateUkrainianName" },
    { Country::Denmark, "shouldGenerateDanishName" },
    { Country::Sweden, "shouldGenerateSwedishName" },
    { Country::Usa, "shouldGenerateAmericanName" },
    { Country::Brazil, "shouldGenerateBrazilianName" },
    { Country::Norway, "shouldGenerateNorwegianName" },
    { Country::Japan, "shouldGenerateJapaneseName" },
    { Country::Portugal, "shouldGeneratePortugueseName" },
    { Country::Hungary, "shouldGenerateHungarianName" },
    { Country::Croatia, "shouldGenerateCroatianName" },
    { Country::Greece, "shouldGenerateGreekName" },
    { Country::Slovenia, "shouldGenerateSlovenianName" },
    { Country::Austria, "shouldGenerateAustrianName" },
    { Country::Switzerland, "shouldGenerateSwissName" },
    { Country::Belgium, "shouldGenerateBelgianName" },
    { Country::Netherlands, "shouldGenerateDutchName" },
    { Country::China, "shouldGenerateChineseName" },
    { Country::Korea, "shouldGenerateKoreanName" },
    { Country::Canada, "shouldGenerateCanadianName" },
    { Country::Mexico, "shouldGenerateMexicanName" },
    { Country::Argentina, "shouldGenerateArgentinianName" },
    { Country::Australia, "shouldGenerateAustralianName" },
    { Country::Serbia, "shouldGenerateSerbianName" },
    { Country::Macedonia, "shouldGenerateMacedonianName" },
    { Country::Latvia, "shouldGenerateLatvianName" },
    { Country::Ireland, "shouldGenerateIrishName" },
    { Country::Belarus, "shouldGenerateBelarusianName" },
    { Country::Estonia, "shouldGenerateEstonianName" },
    { Country::Albania, "shouldGenerateAlbanianName" },
    { Country::Iran, "shouldGeneratePersianName" },
    { Country::Bulgaria, "shouldGenerateBulgarianName" },
    { Country::Moldova, "shouldGenerateMoldovanName" },
    { Country::Lithuania, "shouldGenerateLithuanianName" },
    { Country::Iceland, "shouldGenerateIcelandicName" },
    { Country::Palestine, "shouldGeneratePalestinianName" },
    { Country::Israel, "shouldGenerateIsraeliName" },
    { Country::Vietnam, "shouldGenerateVietnameseName" },
    { Country::Monaco, "shouldGenerateMonacanName" },
    { Country::Bosnia, "shouldGenerateBosnianNames" },
    { Country::Lebanon, "shouldGenerateLebaneseName" },
    { Country::Syria, "shouldGenerateSyrianName" },
    { Country::Malta, "shouldGenerateMalteseName" },
    { Country::SouthAfrica, "shouldGenerateSouthAfricanName" },
    { Country::Azerbaijan, "shouldGenerateAzerbaijaniName" },
    { Country::Ghana, "shouldGenerateGhanaianName" },
    { Country::Kazakhstan, "shouldGenerateKazakhName" },
    { Country::Maldives, "shouldGenerateMaldivianName" },
};
}

class PersonTest : public TestWithParam<Country> {
public:
    PersonTest()
    {
        initializePrefixes();

        initializeSuffixes();

        initializeMiddleNames();
    }

    void initializePrefixes()
    {
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping) {
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
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping) {
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
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping) {
            malesMiddleNames.insert(malesMiddleNames.end(),
                peopleNames.malesNames.middleNames.begin(),
                peopleNames.malesNames.middleNames.end());

            femalesMiddleNames.insert(femalesMiddleNames.end(),
                peopleNames.femalesNames.middleNames.begin(),
                peopleNames.femalesNames.middleNames.end());

            allMiddleNames.insert(allMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                peopleNames.malesNames.middleNames.end());
            allMiddleNames.insert(allMiddleNames.end(),
                peopleNames.femalesNames.middleNames.begin(),
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

    std::vector<std::string> firstNames { malesFirstNames };

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = person::firstName(country);

    ASSERT_TRUE(
        faker::testing::any_of(firstNames, [generatedFirstName](const std::string& firstName) {
            return firstName == generatedFirstName;
        }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = person::firstName(country, Sex::Male);

    ASSERT_TRUE(
        faker::testing::any_of(malesFirstNames, [generatedFirstName](const std::string& firstName) {
            return firstName == generatedFirstName;
        }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = person::firstName(country, Sex::Female);

    ASSERT_TRUE(faker::testing::any_of(
        femalesFirstNames, [generatedFirstName](const std::string& firstName) {
            return firstName == generatedFirstName;
        }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = person::lastName(country, Sex::Male);

    ASSERT_TRUE(
        faker::testing::any_of(malesLastNames, [generatedLastName](const std::string& lastName) {
            return lastName == generatedLastName;
        }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = person::lastName(country, Sex::Female);

    ASSERT_TRUE(
        faker::testing::any_of(femalesLastNames, [generatedLastName](const std::string& lastName) {
            return lastName == generatedLastName;
        }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string> firstNames { malesFirstNames };
    std::vector<std::string> lastNames { malesLastNames };

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = person::fullName(country);

    ASSERT_TRUE(
        faker::testing::any_of(firstNames, [generatedFullName](const std::string& firstName) {
            return generatedFullName.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(lastNames, [generatedFullName](const std::string& lastName) {
        return generatedFullName.find(lastName) != std::string::npos;
    }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = person::fullName(country, Sex::Male);

    ASSERT_TRUE(
        faker::testing::any_of(malesFirstNames, [generatedFullName](const std::string& firstName) {
            return generatedFullName.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(
        faker::testing::any_of(malesLastNames, [generatedFullName](const std::string& lastName) {
            return generatedFullName.find(lastName) != std::string::npos;
        }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = person::fullName(country, Sex::Female);

    ASSERT_TRUE(faker::testing::any_of(
        femalesFirstNames, [generatedFullName](const std::string& firstName) {
            return generatedFullName.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(
        faker::testing::any_of(femalesLastNames, [generatedFullName](const std::string& lastName) {
            return generatedFullName.find(lastName) != std::string::npos;
        }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
    [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateMiddleName)
{
    const auto generatedMiddleName = person::middleName();

    FAKER_EXPECT_CONTAINS(allMiddleNames, generatedMiddleName);
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = person::prefix();

    FAKER_EXPECT_CONTAINS(allPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = person::prefix(Sex::Male);

    FAKER_EXPECT_CONTAINS(malesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = person::prefix(Sex::Female);

    FAKER_EXPECT_CONTAINS(femalesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = person::suffix();

    FAKER_EXPECT_CONTAINS(allSuffixes, generatedSuffix);
}

TEST_F(PersonTest, shouldGenerateSex)
{
    const auto generatedSex = person::sex();

    FAKER_EXPECT_CONTAINS(sexes, generatedSex);
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = person::gender();

    FAKER_EXPECT_CONTAINS(genders, generatedGender);
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = person::jobDescriptor();

    FAKER_EXPECT_CONTAINS(jobDescriptors, generatedJobDescriptor);
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = person::jobArea();

    FAKER_EXPECT_CONTAINS(jobAreas, generatedJobArea);
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = person::jobType();

    FAKER_EXPECT_CONTAINS(jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = person::jobTitle();

    const auto jobTitleElements = StringHelper::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    FAKER_EXPECT_CONTAINS(jobDescriptors, generatedJobDescriptor);
    FAKER_EXPECT_CONTAINS(jobAreas, generatedJobArea);
    FAKER_EXPECT_CONTAINS(jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = person::hobby();

    FAKER_EXPECT_CONTAINS(hobbies, generatedHobby);
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = person::bio();

    ASSERT_TRUE(BioHelper::checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    auto generatedLanguage = person::language();

    FAKER_EXPECT_CONTAINS(languages, generatedLanguage);
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    auto generatedNationality = person::nationality();

    FAKER_EXPECT_CONTAINS(nationalities, generatedNationality);
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    auto generatedWesternZodiacs = person::westernZodiac();

    FAKER_EXPECT_CONTAINS(westernZodiacs, generatedWesternZodiacs);
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = person::chineseZodiac();

    FAKER_EXPECT_CONTAINS(chineseZodiacs, generatedChineseZodiacs);
}

class PersonSexSuite : public TestWithParam<std::pair<Language, Sex>> { };

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = sexTranslations.at(language).at(sex);
    const auto actualTranslation = translateSex(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<Language, Sex>> languageSexPairs
    = { { Language::English, Sex::Male }, { Language::English, Sex::Female },
          { Language::Polish, Sex::Male }, { Language::Polish, Sex::Female },
          { Language::Italian, Sex::Male }, { Language::Italian, Sex::Female },
          { Language::French, Sex::Male }, { Language::French, Sex::Female },
          { Language::German, Sex::Male }, { Language::German, Sex::Female },
          { Language::Russian, Sex::Male }, { Language::Russian, Sex::Female },
          { Language::Romanian, Sex::Male }, { Language::Romanian, Sex::Female },
          { Language::Hindi, Sex::Male }, { Language::Hindi, Sex::Female },
          { Language::Finnish, Sex::Male }, { Language::Finnish, Sex::Female },
          { Language::Nepali, Sex::Male }, { Language::Nepali, Sex::Female },
          { Language::Spanish, Sex::Male }, { Language::Spanish, Sex::Female },
          { Language::Turkish, Sex::Male }, { Language::Turkish, Sex::Female },
          { Language::Czech, Sex::Male }, { Language::Czech, Sex::Female },
          { Language::Slovak, Sex::Male }, { Language::Slovak, Sex::Female },
          { Language::Ukrainian, Sex::Male }, { Language::Ukrainian, Sex::Female },
          { Language::Danish, Sex::Male }, { Language::Danish, Sex::Female },
          { Language::Swedish, Sex::Male }, { Language::Swedish, Sex::Female },
          { Language::Portuguese, Sex::Male }, { Language::Portuguese, Sex::Female },
          { Language::Norwegian, Sex::Male }, { Language::Norwegian, Sex::Female },
          { Language::Japanese, Sex::Male }, { Language::Japanese, Sex::Female },
          { Language::Hungarian, Sex::Male }, { Language::Hungarian, Sex::Female },
          { Language::Croatian, Sex::Male }, { Language::Croatian, Sex::Female },
          { Language::Greek, Sex::Male }, { Language::Greek, Sex::Female },
          { Language::Slovene, Sex::Male }, { Language::Slovene, Sex::Female },
          { Language::Dutch, Sex::Male }, { Language::Dutch, Sex::Female },
          { Language::Mandarin, Sex::Male }, { Language::Mandarin, Sex::Female },
          { Language::Korean, Sex::Male }, { Language::Korean, Sex::Female },
          { Language::Serbian, Sex::Male }, { Language::Serbian, Sex::Female },
          { Language::Macedonian, Sex::Male }, { Language::Macedonian, Sex::Female },
          { Language::Albanian, Sex::Male }, { Language::Albanian, Sex::Female },
          { Language::Latvian, Sex::Male }, { Language::Latvian, Sex::Female },
          { Language::Irish, Sex::Male }, { Language::Irish, Sex::Female },
          { Language::Belarusian, Sex::Male }, { Language::Belarusian, Sex::Female },
          { Language::Estonian, Sex::Male }, { Language::Estonian, Sex::Female } };

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, ValuesIn(languageSexPairs),
    [](const TestParamInfo<PersonSexSuite::ParamType>& info) {
        std::string result;
        result += toString(info.param.first);
        result += '_';
        result += toString(info.param.second);
        return result;
    });

const std::unordered_map<SsnCountry, unsigned> ssnLengths {
    { SsnCountry::Poland, 11 },
    { SsnCountry::UnitedStates, 11 },
    { SsnCountry::UnitedKingdom, 13 },
    { SsnCountry::Germany, 12 },
    { SsnCountry::France, 19 },
    { SsnCountry::Italy, 19 },
    { SsnCountry::Spain, 10 },
    { SsnCountry::India, 10 },
};

class PersonSsnSuite : public TestWithParam<SsnCountry> { };

// TODO: add more precise tests
TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = person::ssn(country);

    const auto expectedSsnLength = ssnLengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite, ValuesIn(supportedSsnCountries),
    [](const TestParamInfo<PersonSsnSuite::ParamType>& info) {
        std::string result("shouldGenerate");
        result += toString(info.param);
        result += "Ssn";
        return result;
    });
