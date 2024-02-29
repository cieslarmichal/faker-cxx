#include "../bio_helper.h"
#include "../test_helpers.h"
#include <algorithm>
#include <array>
#include <common/strings.h>
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
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
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
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
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
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
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
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.malesNames.firstNames, peopleNames.femalesNames.firstNames);

    const auto generatedFirstName = person::first_name(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(firstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();
    const auto& malesFirstNames
        = person::data::countryToPeopleNamesMapping.at(country).malesNames.firstNames;

    const auto generatedFirstName = person::first_name(country, person::Sex::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();
    const auto& femalesFirstNames
        = person::data::countryToPeopleNamesMapping.at(country).femalesNames.firstNames;

    const auto generatedFirstName = person::first_name(country, person::Sex::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();
    const auto& malesLastNames
        = person::data::countryToPeopleNamesMapping.at(country).malesNames.lastNames;

    const auto generatedLastName = person::last_name(country, person::Sex::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();
    const auto& femalesLastNames
        = person::data::countryToPeopleNamesMapping.at(country).femalesNames.lastNames;

    const auto generatedLastName = person::last_name(country, person::Sex::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.malesNames.firstNames, peopleNames.femalesNames.firstNames);
    auto lastNames = faker::testing::make_vector(
        peopleNames.malesNames.lastNames, peopleNames.femalesNames.lastNames);

    const auto generatedFullName = person::full_name(country);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, lastNames);
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);

    const auto generatedFullName = person::full_name(country, person::Sex::male);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.malesNames.firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.malesNames.lastNames);
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);

    const auto generatedFullName = person::full_name(country, person::Sex::female);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.femalesNames.firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.femalesNames.lastNames);
}

const std::array<Country, 61> countries {
    Country::Usa,
    Country::England,
    Country::Poland,
    Country::Italy,
    Country::France,
    Country::Germany,
    Country::Russia,
    Country::Romania,
    Country::India,
    Country::Finland,
    Country::Nepal,
    Country::Spain,
    Country::Turkey,
    Country::Czech,
    Country::Slovakia,
    Country::Ukraine,
    Country::Denmark,
    Country::Sweden,
    Country::Brazil,
    Country::Norway,
    Country::Japan,
    Country::Portugal,
    Country::Hungary,
    Country::Croatia,
    Country::Greece,
    Country::Slovenia,
    Country::Austria,
    Country::Switzerland,
    Country::Belgium,
    Country::Netherlands,
    Country::China,
    Country::Korea,
    Country::Canada,
    Country::Mexico,
    Country::Argentina,
    Country::Australia,
    Country::Serbia,
    Country::Macedonia,
    Country::Albania,
    Country::Latvia,
    Country::Ireland,
    Country::Belarus,
    Country::Estonia,
    Country::Iran,
    Country::Bulgaria,
    Country::Moldova,
    Country::Lithuania,
    Country::Iceland,
    Country::Palestine,
    Country::Israel,
    Country::Vietnam,
    Country::Monaco,
    Country::Bosnia,
    Country::Lebanon,
    Country::Syria,
    Country::Malta,
    Country::SouthAfrica,
    Country::Azerbaijan,
    Country::Ghana,
    Country::Kazakhstan,
    Country::Maldives,
};

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
    [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateMiddleName)
{
    const auto generatedMiddleName = person::middle_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(allMiddleNames, generatedMiddleName);
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = person::prefix();

    FAKER_EXPECT_CONTAINER_CONTAINS(allPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = person::prefix(person::Sex::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = person::prefix(person::Sex::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = person::suffix();

    FAKER_EXPECT_CONTAINER_CONTAINS(allSuffixes, generatedSuffix);
}

TEST_F(PersonTest, shouldGenerateSex)
{
    const auto generatedSex = person::sex();

    FAKER_EXPECT_CONTAINER_CONTAINS(sexes, generatedSex);
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = person::gender();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::genders, generatedGender);
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = person::job_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobDescriptors, generatedJobDescriptor);
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = person::job_area();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = person::job_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = person::job_title();

    const auto jobTitleElements = utils::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobDescriptors, generatedJobDescriptor);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = person::hobby();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::hobbies, generatedHobby);
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = person::bio();

    ASSERT_TRUE(BioHelper::checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    auto generatedLanguage = person::language();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::languages, generatedLanguage);
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    auto generatedNationality = person::nationality();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::nationalities, generatedNationality);
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    auto generatedWesternZodiacs = person::western_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::westernZodiacs, generatedWesternZodiacs);
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = person::chinese_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::chineseZodiacs, generatedChineseZodiacs);
}

class PersonSexSuite : public TestWithParam<std::pair<person::Language, person::Sex>> { };

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = person::data::sexTranslations.at(language).at(sex);
    const auto actualTranslation = to_string(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<person::Language, person::Sex>> languageSexPairs
    = { { person::Language::English, person::Sex::male },
          { person::Language::English, person::Sex::female },
          { person::Language::Polish, person::Sex::male },
          { person::Language::Polish, person::Sex::female },
          { person::Language::Italian, person::Sex::male },
          { person::Language::Italian, person::Sex::female },
          { person::Language::French, person::Sex::male },
          { person::Language::French, person::Sex::female },
          { person::Language::German, person::Sex::male },
          { person::Language::German, person::Sex::female },
          { person::Language::Russian, person::Sex::male },
          { person::Language::Russian, person::Sex::female },
          { person::Language::Romanian, person::Sex::male },
          { person::Language::Romanian, person::Sex::female },
          { person::Language::Hindi, person::Sex::male },
          { person::Language::Hindi, person::Sex::female },
          { person::Language::Finnish, person::Sex::male },
          { person::Language::Finnish, person::Sex::female },
          { person::Language::Nepali, person::Sex::male },
          { person::Language::Nepali, person::Sex::female },
          { person::Language::Spanish, person::Sex::male },
          { person::Language::Spanish, person::Sex::female },
          { person::Language::Turkish, person::Sex::male },
          { person::Language::Turkish, person::Sex::female },
          { person::Language::Czech, person::Sex::male },
          { person::Language::Czech, person::Sex::female },
          { person::Language::Slovak, person::Sex::male },
          { person::Language::Slovak, person::Sex::female },
          { person::Language::Ukrainian, person::Sex::male },
          { person::Language::Ukrainian, person::Sex::female },
          { person::Language::Danish, person::Sex::male },
          { person::Language::Danish, person::Sex::female },
          { person::Language::Swedish, person::Sex::male },
          { person::Language::Swedish, person::Sex::female },
          { person::Language::Portuguese, person::Sex::male },
          { person::Language::Portuguese, person::Sex::female },
          { person::Language::Norwegian, person::Sex::male },
          { person::Language::Norwegian, person::Sex::female },
          { person::Language::Japanese, person::Sex::male },
          { person::Language::Japanese, person::Sex::female },
          { person::Language::Hungarian, person::Sex::male },
          { person::Language::Hungarian, person::Sex::female },
          { person::Language::Croatian, person::Sex::male },
          { person::Language::Croatian, person::Sex::female },
          { person::Language::Greek, person::Sex::male },
          { person::Language::Greek, person::Sex::female },
          { person::Language::Slovene, person::Sex::male },
          { person::Language::Slovene, person::Sex::female },
          { person::Language::Dutch, person::Sex::male },
          { person::Language::Dutch, person::Sex::female },
          { person::Language::Mandarin, person::Sex::male },
          { person::Language::Mandarin, person::Sex::female },
          { person::Language::Korean, person::Sex::male },
          { person::Language::Korean, person::Sex::female },
          { person::Language::Serbian, person::Sex::male },
          { person::Language::Serbian, person::Sex::female },
          { person::Language::Macedonian, person::Sex::male },
          { person::Language::Macedonian, person::Sex::female },
          { person::Language::Albanian, person::Sex::male },
          { person::Language::Albanian, person::Sex::female },
          { person::Language::Latvian, person::Sex::male },
          { person::Language::Latvian, person::Sex::female },
          { person::Language::Irish, person::Sex::male },
          { person::Language::Irish, person::Sex::female },
          { person::Language::Belarusian, person::Sex::male },
          { person::Language::Belarusian, person::Sex::female },
          { person::Language::Estonian, person::Sex::male },
          { person::Language::Estonian, person::Sex::female } };

std::string_view toString(person::Language language)
{
    switch (language) {
    case person::Language::English:
        return "English";
    case person::Language::Polish:
        return "Polish";
    case person::Language::Italian:
        return "Italian";
    case person::Language::French:
        return "French";
    case person::Language::German:
        return "German";
    case person::Language::Russian:
        return "Russian";
    case person::Language::Romanian:
        return "Romanian";
    case person::Language::Hindi:
        return "Hindi";
    case person::Language::Finnish:
        return "Finnish";
    case person::Language::Nepali:
        return "Nepali";
    case person::Language::Spanish:
        return "Spanish";
    case person::Language::Turkish:
        return "Turkish";
    case person::Language::Czech:
        return "Czech";
    case person::Language::Slovak:
        return "Slovak";
    case person::Language::Ukrainian:
        return "Ukrainian";
    case person::Language::Danish:
        return "Danish";
    case person::Language::Swedish:
        return "Swedish";
    case person::Language::Portuguese:
        return "Portuguese";
    case person::Language::Norwegian:
        return "Norwegian";
    case person::Language::Japanese:
        return "Japanese";
    case person::Language::Hungarian:
        return "Hungarian";
    case person::Language::Croatian:
        return "Croatian";
    case person::Language::Greek:
        return "Greek";
    case person::Language::Slovene:
        return "Slovene";
    case person::Language::Dutch:
        return "Dutch";
    case person::Language::Mandarin:
        return "Mandarin";
    case person::Language::Korean:
        return "Korean";
    case person::Language::Serbian:
        return "Serbian";
    case person::Language::Macedonian:
        return "Macedonian";
    case person::Language::Albanian:
        return "Albanian";
    case person::Language::Latvian:
        return "Latvian";
    case person::Language::Irish:
        return "Irish";
    case person::Language::Belarusian:
        return "Belarusian";
    case person::Language::Estonian:
        return "Estonian";
    default:
        throw std::invalid_argument("Invalid language");
    }
}

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, ValuesIn(languageSexPairs),
    [](const TestParamInfo<PersonSexSuite::ParamType>& info) {
        std::string result;
        result += toString(info.param.first);
        result += '_';
        result += to_string(info.param.second);
        return result;
    });

class PersonSsnSuite : public TestWithParam<person::ssn_country> { };

// TODO: add more precise tests
TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = person::ssn(country);

    const auto expectedSsnLength = person::data::ssnLengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

std::string_view toString(person::ssn_country country)
{
    switch (country) {
    case person::ssn_country::usa:
        return "UnitedStates";
    case person::ssn_country::england:
        return "UnitedKingdom";
    case person::ssn_country::poland:
        return "Poland";
    case person::ssn_country::italy:
        return "Italy";
    case person::ssn_country::france:
        return "France";
    case person::ssn_country::germany:
        return "Germany";
    case person::ssn_country::india:
        return "India";
    case person::ssn_country::spain:
        return "Spain";
    default:
        throw std::invalid_argument("Invalid country");
    }
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite,
    ValuesIn(person::data::supportedSsnCountries),
    [](const TestParamInfo<PersonSsnSuite::ParamType>& info) {
        std::string result("shouldGenerate");
        result += toString(info.param);
        result += "Ssn";
        return result;
    });
