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

const std::unordered_map<country_t, std::string> generatedTestName {
    { country_t::england, "shouldGenerateEnglishName" },
    { country_t::france, "shouldGenerateFrenchName" },
    { country_t::germany, "shouldGenerateGermanName" },
    { country_t::italy, "shouldGenerateItalianName" },
    { country_t::poland, "shouldGeneratePolishName" },
    { country_t::russia, "shouldGenerateRussianName" },
    { country_t::romania, "shouldGenerateRomanianName" },
    { country_t::india, "shouldGenerateIndianName" },
    { country_t::finland, "shouldGenerateFinnishName" },
    { country_t::nepal, "shouldGenerateNepaleseName" },
    { country_t::spain, "shouldGenerateSpanishName" },
    { country_t::turkey, "shouldGenerateTurkishName" },
    { country_t::czech, "shouldGenerateCzechName" },
    { country_t::slovakia, "shouldGenerateSlovakName" },
    { country_t::ukraine, "shouldGenerateUkrainianName" },
    { country_t::denmark, "shouldGenerateDanishName" },
    { country_t::sweden, "shouldGenerateSwedishName" },
    { country_t::usa, "shouldGenerateAmericanName" },
    { country_t::brazil, "shouldGenerateBrazilianName" },
    { country_t::norway, "shouldGenerateNorwegianName" },
    { country_t::japan, "shouldGenerateJapaneseName" },
    { country_t::portugal, "shouldGeneratePortugueseName" },
    { country_t::hungary, "shouldGenerateHungarianName" },
    { country_t::croatia, "shouldGenerateCroatianName" },
    { country_t::greece, "shouldGenerateGreekName" },
    { country_t::slovenia, "shouldGenerateSlovenianName" },
    { country_t::austria, "shouldGenerateAustrianName" },
    { country_t::switzerland, "shouldGenerateSwissName" },
    { country_t::belgium, "shouldGenerateBelgianName" },
    { country_t::netherlands, "shouldGenerateDutchName" },
    { country_t::china, "shouldGenerateChineseName" },
    { country_t::korea, "shouldGenerateKoreanName" },
    { country_t::canada, "shouldGenerateCanadianName" },
    { country_t::mexico, "shouldGenerateMexicanName" },
    { country_t::argentina, "shouldGenerateArgentinianName" },
    { country_t::australia, "shouldGenerateAustralianName" },
    { country_t::serbia, "shouldGenerateSerbianName" },
    { country_t::macedonia, "shouldGenerateMacedonianName" },
    { country_t::latvia, "shouldGenerateLatvianName" },
    { country_t::ireland, "shouldGenerateIrishName" },
    { country_t::belarus, "shouldGenerateBelarusianName" },
    { country_t::estonia, "shouldGenerateEstonianName" },
    { country_t::albania, "shouldGenerateAlbanianName" },
    { country_t::iran, "shouldGeneratePersianName" },
    { country_t::bulgaria, "shouldGenerateBulgarianName" },
    { country_t::moldova, "shouldGenerateMoldovanName" },
    { country_t::lithuania, "shouldGenerateLithuanianName" },
    { country_t::iceland, "shouldGenerateIcelandicName" },
    { country_t::palestine, "shouldGeneratePalestinianName" },
    { country_t::israel, "shouldGenerateIsraeliName" },
    { country_t::vietnam, "shouldGenerateVietnameseName" },
    { country_t::monaco, "shouldGenerateMonacanName" },
    { country_t::bosnia, "shouldGenerateBosnianNames" },
    { country_t::lebanon, "shouldGenerateLebaneseName" },
    { country_t::syria, "shouldGenerateSyrianName" },
    { country_t::malta, "shouldGenerateMalteseName" },
    { country_t::south_africa, "shouldGenerateSouthAfricanName" },
    { country_t::azerbaijan, "shouldGenerateAzerbaijaniName" },
    { country_t::ghana, "shouldGenerateGhanaianName" },
    { country_t::kazakhstan, "shouldGenerateKazakhName" },
    { country_t::maldives, "shouldGenerateMaldivianName" },
};
}

class PersonTest : public TestWithParam<country_t> {
public:
    PersonTest()
    {
        initializePrefixes();

        initializeSuffixes();

        initializeMiddleNames();
    }

    void initializePrefixes()
    {
        for (const auto& [_, peopleNames] : person::data::people_names) {
            malesPrefixes.insert(malesPrefixes.end(), peopleNames.males_names.prefixes.begin(),
                peopleNames.males_names.prefixes.end());

            femalesPrefixes.insert(femalesPrefixes.end(), peopleNames.female_names.prefixes.begin(),
                peopleNames.female_names.prefixes.end());

            allPrefixes.insert(allPrefixes.end(), peopleNames.males_names.prefixes.begin(),
                peopleNames.males_names.prefixes.end());
            allPrefixes.insert(allPrefixes.end(), peopleNames.female_names.prefixes.begin(),
                peopleNames.female_names.prefixes.end());
        }
    }

    void initializeSuffixes()
    {
        for (const auto& [_, peopleNames] : person::data::people_names) {
            malesSuffixes.insert(malesSuffixes.end(), peopleNames.males_names.suffixes.begin(),
                peopleNames.males_names.suffixes.end());

            femalesSuffixes.insert(femalesSuffixes.end(), peopleNames.female_names.suffixes.begin(),
                peopleNames.female_names.suffixes.end());

            allSuffixes.insert(allSuffixes.end(), peopleNames.males_names.suffixes.begin(),
                peopleNames.males_names.suffixes.end());
            allSuffixes.insert(allSuffixes.end(), peopleNames.female_names.suffixes.begin(),
                peopleNames.female_names.suffixes.end());
        }
    }

    void initializeMiddleNames()
    {
        for (const auto& [_, peopleNames] : person::data::people_names) {
            malesMiddleNames.insert(malesMiddleNames.end(),
                peopleNames.males_names.middle_names.begin(),
                peopleNames.males_names.middle_names.end());

            femalesMiddleNames.insert(femalesMiddleNames.end(),
                peopleNames.female_names.middle_names.begin(),
                peopleNames.female_names.middle_names.end());

            allMiddleNames.insert(allMiddleNames.end(),
                peopleNames.males_names.middle_names.begin(),
                peopleNames.males_names.middle_names.end());
            allMiddleNames.insert(allMiddleNames.end(),
                peopleNames.female_names.middle_names.begin(),
                peopleNames.female_names.middle_names.end());
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
    const auto& peopleNames = person::data::people_names.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.males_names.first_names, peopleNames.female_names.first_names);

    const auto generatedFirstName = person::first_name(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(firstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();
    const auto& malesFirstNames = person::data::people_names.at(country).males_names.first_names;

    const auto generatedFirstName = person::first_name(country, person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();
    const auto& femalesFirstNames = person::data::people_names.at(country).female_names.first_names;

    const auto generatedFirstName = person::first_name(country, person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();
    const auto& malesLastNames = person::data::people_names.at(country).males_names.last_names;

    const auto generatedLastName = person::last_name(country, person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();
    const auto& femalesLastNames = person::data::people_names.at(country).female_names.last_names;

    const auto generatedLastName = person::last_name(country, person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::people_names.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.males_names.first_names, peopleNames.female_names.first_names);
    auto lastNames = faker::testing::make_vector(
        peopleNames.males_names.last_names, peopleNames.female_names.last_names);

    const auto generatedFullName = person::full_name(country);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, lastNames);
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::people_names.at(country);

    const auto generatedFullName = person::full_name(country, person::sex_t::male);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.males_names.first_names);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.males_names.last_names);
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::people_names.at(country);

    const auto generatedFullName = person::full_name(country, person::sex_t::female);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.female_names.first_names);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.female_names.last_names);
}

const std::array<country_t, 61> countries {
    country_t::usa,
    country_t::england,
    country_t::poland,
    country_t::italy,
    country_t::france,
    country_t::germany,
    country_t::russia,
    country_t::romania,
    country_t::india,
    country_t::finland,
    country_t::nepal,
    country_t::spain,
    country_t::turkey,
    country_t::czech,
    country_t::slovakia,
    country_t::ukraine,
    country_t::denmark,
    country_t::sweden,
    country_t::brazil,
    country_t::norway,
    country_t::japan,
    country_t::portugal,
    country_t::hungary,
    country_t::croatia,
    country_t::greece,
    country_t::slovenia,
    country_t::austria,
    country_t::switzerland,
    country_t::belgium,
    country_t::netherlands,
    country_t::china,
    country_t::korea,
    country_t::canada,
    country_t::mexico,
    country_t::argentina,
    country_t::australia,
    country_t::serbia,
    country_t::macedonia,
    country_t::albania,
    country_t::latvia,
    country_t::ireland,
    country_t::belarus,
    country_t::estonia,
    country_t::iran,
    country_t::bulgaria,
    country_t::moldova,
    country_t::lithuania,
    country_t::iceland,
    country_t::palestine,
    country_t::israel,
    country_t::vietnam,
    country_t::monaco,
    country_t::bosnia,
    country_t::lebanon,
    country_t::syria,
    country_t::malta,
    country_t::south_africa,
    country_t::azerbaijan,
    country_t::ghana,
    country_t::kazakhstan,
    country_t::maldives,
};

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
    [](const TestParamInfo<country_t>& info) { return generatedTestName.at(info.param); });

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
    const auto generatedPrefix = person::prefix(person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = person::prefix(person::sex_t::female);

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

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_descriptors, generatedJobDescriptor);
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = person::job_area();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, generatedJobArea);
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = person::job_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_types, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = person::job_title();

    const auto jobTitleElements = utils::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_descriptors, generatedJobDescriptor);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, generatedJobArea);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_types, generatedJobType);
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

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::western_zodiacs, generatedWesternZodiacs);
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = person::chinese_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::chinese_zodiacs, generatedChineseZodiacs);
}

class PersonSexSuite : public TestWithParam<std::pair<person::language_t, person::sex_t>> { };

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = person::data::sex_translations.at(language).at(sex);
    const auto actualTranslation = to_string(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<person::language_t, person::sex_t>> languageSexPairs
    = { { person::language_t::english, person::sex_t::male },
          { person::language_t::english, person::sex_t::female },
          { person::language_t::polish, person::sex_t::male },
          { person::language_t::polish, person::sex_t::female },
          { person::language_t::italian, person::sex_t::male },
          { person::language_t::italian, person::sex_t::female },
          { person::language_t::french, person::sex_t::male },
          { person::language_t::french, person::sex_t::female },
          { person::language_t::german, person::sex_t::male },
          { person::language_t::german, person::sex_t::female },
          { person::language_t::russian, person::sex_t::male },
          { person::language_t::russian, person::sex_t::female },
          { person::language_t::romanian, person::sex_t::male },
          { person::language_t::romanian, person::sex_t::female },
          { person::language_t::hindi, person::sex_t::male },
          { person::language_t::hindi, person::sex_t::female },
          { person::language_t::finnish, person::sex_t::male },
          { person::language_t::finnish, person::sex_t::female },
          { person::language_t::nepali, person::sex_t::male },
          { person::language_t::nepali, person::sex_t::female },
          { person::language_t::spanish, person::sex_t::male },
          { person::language_t::spanish, person::sex_t::female },
          { person::language_t::turkish, person::sex_t::male },
          { person::language_t::turkish, person::sex_t::female },
          { person::language_t::czech, person::sex_t::male },
          { person::language_t::czech, person::sex_t::female },
          { person::language_t::slovak, person::sex_t::male },
          { person::language_t::slovak, person::sex_t::female },
          { person::language_t::ukrainian, person::sex_t::male },
          { person::language_t::ukrainian, person::sex_t::female },
          { person::language_t::danish, person::sex_t::male },
          { person::language_t::danish, person::sex_t::female },
          { person::language_t::swedish, person::sex_t::male },
          { person::language_t::swedish, person::sex_t::female },
          { person::language_t::portuguese, person::sex_t::male },
          { person::language_t::portuguese, person::sex_t::female },
          { person::language_t::norwegian, person::sex_t::male },
          { person::language_t::norwegian, person::sex_t::female },
          { person::language_t::japanese, person::sex_t::male },
          { person::language_t::japanese, person::sex_t::female },
          { person::language_t::hungarian, person::sex_t::male },
          { person::language_t::hungarian, person::sex_t::female },
          { person::language_t::croatian, person::sex_t::male },
          { person::language_t::croatian, person::sex_t::female },
          { person::language_t::greek, person::sex_t::male },
          { person::language_t::greek, person::sex_t::female },
          { person::language_t::slovene, person::sex_t::male },
          { person::language_t::slovene, person::sex_t::female },
          { person::language_t::dutch, person::sex_t::male },
          { person::language_t::dutch, person::sex_t::female },
          { person::language_t::mandarin, person::sex_t::male },
          { person::language_t::mandarin, person::sex_t::female },
          { person::language_t::korean, person::sex_t::male },
          { person::language_t::korean, person::sex_t::female },
          { person::language_t::serbian, person::sex_t::male },
          { person::language_t::serbian, person::sex_t::female },
          { person::language_t::macedonian, person::sex_t::male },
          { person::language_t::macedonian, person::sex_t::female },
          { person::language_t::albanian, person::sex_t::male },
          { person::language_t::albanian, person::sex_t::female },
          { person::language_t::latvian, person::sex_t::male },
          { person::language_t::latvian, person::sex_t::female },
          { person::language_t::irish, person::sex_t::male },
          { person::language_t::irish, person::sex_t::female },
          { person::language_t::belarusian, person::sex_t::male },
          { person::language_t::belarusian, person::sex_t::female },
          { person::language_t::estonian, person::sex_t::male },
          { person::language_t::estonian, person::sex_t::female } };

std::string_view toString(person::language_t language)
{
    switch (language) {
    case person::language_t::english:
        return "English";
    case person::language_t::polish:
        return "Polish";
    case person::language_t::italian:
        return "Italian";
    case person::language_t::french:
        return "French";
    case person::language_t::german:
        return "German";
    case person::language_t::russian:
        return "Russian";
    case person::language_t::romanian:
        return "Romanian";
    case person::language_t::hindi:
        return "Hindi";
    case person::language_t::finnish:
        return "Finnish";
    case person::language_t::nepali:
        return "Nepali";
    case person::language_t::spanish:
        return "Spanish";
    case person::language_t::turkish:
        return "Turkish";
    case person::language_t::czech:
        return "Czech";
    case person::language_t::slovak:
        return "Slovak";
    case person::language_t::ukrainian:
        return "Ukrainian";
    case person::language_t::danish:
        return "Danish";
    case person::language_t::swedish:
        return "Swedish";
    case person::language_t::portuguese:
        return "Portuguese";
    case person::language_t::norwegian:
        return "Norwegian";
    case person::language_t::japanese:
        return "Japanese";
    case person::language_t::hungarian:
        return "Hungarian";
    case person::language_t::croatian:
        return "Croatian";
    case person::language_t::greek:
        return "Greek";
    case person::language_t::slovene:
        return "Slovene";
    case person::language_t::dutch:
        return "Dutch";
    case person::language_t::mandarin:
        return "Mandarin";
    case person::language_t::korean:
        return "Korean";
    case person::language_t::serbian:
        return "Serbian";
    case person::language_t::macedonian:
        return "Macedonian";
    case person::language_t::albanian:
        return "Albanian";
    case person::language_t::latvian:
        return "Latvian";
    case person::language_t::irish:
        return "Irish";
    case person::language_t::belarusian:
        return "Belarusian";
    case person::language_t::estonian:
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

class PersonSsnSuite : public TestWithParam<person::ssn_country_t> { };

// TODO: add more precise tests
TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = person::ssn(country);

    const auto expectedSsnLength = person::data::ssn_lengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

std::string_view toString(person::ssn_country_t country)
{
    switch (country) {
    case person::ssn_country_t::usa:
        return "UnitedStates";
    case person::ssn_country_t::england:
        return "UnitedKingdom";
    case person::ssn_country_t::poland:
        return "Poland";
    case person::ssn_country_t::italy:
        return "Italy";
    case person::ssn_country_t::france:
        return "France";
    case person::ssn_country_t::germany:
        return "Germany";
    case person::ssn_country_t::india:
        return "India";
    case person::ssn_country_t::spain:
        return "Spain";
    default:
        throw std::invalid_argument("Invalid country");
    }
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite,
    ValuesIn(person::data::supported_ssn_countries),
    [](const TestParamInfo<PersonSsnSuite::ParamType>& info) {
        std::string result("shouldGenerate");
        result += toString(info.param);
        result += "Ssn";
        return result;
    });
