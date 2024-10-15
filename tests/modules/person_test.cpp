#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

#include "faker-cxx/internet.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/locale.h"
#include "person_data.h"
#include "string_helper.h"
#include "word_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::person;

namespace
{
const struct PersonDefinition& getPersonDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::en_GB:
        return englishPeopleNames;
    case Locale::fr_FR:
        return frenchPeopleNames;
    case Locale::de_DE:
        return germanPeopleNames;
    case Locale::it_IT:
        return italianPeopleNames;
    case Locale::pl_PL:
        return polishPeopleNames;
    case Locale::ru_RU:
        return russianPeopleNames;
    case Locale::ro_RO:
        return romanianPeopleNames;
    case Locale::as_IN:
    case Locale::bn_IN:
    case Locale::en_IN:
    case Locale::gu_IN:
    case Locale::hi_IN:
    case Locale::kn_IN:
    case Locale::ks_IN:
    case Locale::ml_IN:
    case Locale::mr_IN:
    case Locale::or_IN:
    case Locale::pa_IN:
    case Locale::sa_IN:
    case Locale::ta_IN:
    case Locale::te_IN:
        return indianPeopleNames;
    case Locale::fi_FI:
        return finnishPeopleNames;
    case Locale::es_ES:
        return spanishPeopleNames;
    case Locale::tr_TR:
    case Locale::ku_TR:
        return turkishPeopleNames;
    case Locale::cs_CZ:
        return czechPeopleNames;
    case Locale::sk_SK:
        return slovakPeopleNames;
    case Locale::uk_UA:
        return ukrainianPeopleNames;
    case Locale::da_DK:
        return danishPeopleNames;
    case Locale::sv_SE:
        return swedishPeopleNames;
    case Locale::en_US:
        return usaPeopleNames;
    case Locale::pt_BR:
        return brazilianPeopleNames;
    case Locale::nb_NO:
    case Locale::nn_NO:
        return norwegianPeopleNames;
    case Locale::ja_JP:
        return japanesePeopleNames;
    case Locale::pt_PT:
        return portuguesePeopleNames;
    case Locale::hu_HU:
        return hungarianPeopleNames;
    case Locale::hr_HR:
        return croatianPeopleNames;
    case Locale::el_CY:
    case Locale::el_GR:
        return greekPeopleNames;
    case Locale::sl_SI:
        return slovenianPeopleNames;
    case Locale::de_AT:
        return austrianPeopleNames;
    case Locale::de_CH:
        return swissPeopleNames;
    case Locale::de_BE:
        return belgianPeopleNames;
    case Locale::nl_NL:
    case Locale::nl_BE:
        return dutchPeopleNames;
    case Locale::zh_CN:
        return chinesePeopleNames;
    case Locale::ko_KR:
        return koreanPeopleNames;
    case Locale::en_CA:
    case Locale::fr_CA:
        return canadianPeopleNames;
    case Locale::es_MX:
        return mexicanPeopleNames;
    case Locale::es_AR:
        return argentinianPeopleNames;
    case Locale::en_AU:
        return australianPeopleNames;
    case Locale::sr_ME:
    case Locale::sr_RS:
        return serbianPeopleNames;
    case Locale::mk_MK:
        return macedonianPeopleNames;
    case Locale::lv_LV:
        return latvianPeopleNames;
    case Locale::en_IE:
        return irishPeopleNames;
    case Locale::be_BY:
        return belarusianPeopleNames;
    case Locale::et_EE:
        return estonianPeopleNames;
    case Locale::sq_AL:
        return albanianPeopleNames;
    case Locale::ar_IQ:
        return persianPeopleNames;
    case Locale::bg_BG:
        return bulgarianPeopleNames;
    case Locale::ro_MD:
        return moldovanPeopleNames;
    case Locale::bs_BA:
        return bosnianPeopleNames;
    case Locale::lt_LT:
        return lithuanianPeopleNames;
    case Locale::is_IS:
        return icelandicPeopleNames;
    case Locale::ar_PS:
        return palestinianPeopleNames;
    case Locale::he_IL:
        return israeliPeopleNames;
    case Locale::vi_VN:
        return vietnamesePeopleNames;
    case Locale::fr_MC:
        return monacanPeopleNames;
    case Locale::ar_LB:
        return lebanesePeopleNames;
    case Locale::ar_SY:
        return syrianPeopleNames;
    case Locale::en_MT:
        return maltesePeopleNames;
    case Locale::af_ZA:
        return southAfricanPeopleNames;
    case Locale::az_AZ:
        return azerbaijaniPeopleNames;
    case Locale::en_GH:
        return ghanaianPeopleNames;
    case Locale::kk_KZ:
        return kazakhPeopleNames;
    case Locale::dv_MV:
        return maldiviansPeopleNames;
    default:
        return usaPeopleNames;
    }
}

}

bool checkTokenFormat(const std::string& bio);

class PersonTest : public TestWithParam<Locale>
{
public:
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    std::vector<std::string> firstNames(malesFirstNames.begin(), malesFirstNames.end());

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = firstName(locale);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPersonDefinition(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = firstName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = getPersonDefinition(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = firstName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string_view& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();

    const auto& peopleNames = getPersonDefinition(country);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = lastName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string_view& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();

    const auto& peopleNames = getPersonDefinition(country);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = lastName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string_view& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string_view> firstNames(malesFirstNames.begin(), malesFirstNames.end());
    std::vector<std::string_view> lastNames(malesLastNames.begin(), malesLastNames.end());

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = fullName(locale);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = fullName(locale, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = fullName(locale, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string_view& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string_view& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGeneratePrefix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

    const auto& malesPrefixes = peopleNames.malesNames.prefixes;

    std::vector<std::string_view> prefixes(femalesPrefixes.begin(), femalesPrefixes.end());

    prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());

    const auto generatedPrefix = prefix(locale);

    ASSERT_TRUE(std::ranges::any_of(prefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return generatedPrefix == prefix; }) ||
                generatedPrefix.empty());
}

TEST_P(PersonTest, shouldGenerateMalePrefix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& malesPrefixes = peopleNames.malesNames.prefixes;

    const auto generatedPrefix = prefix(locale, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesPrefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return generatedPrefix == prefix; }) ||
                generatedPrefix.empty());
}

TEST_P(PersonTest, shouldGenerateFemalePrefix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

    const auto generatedPrefix = prefix(locale, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesPrefixes, [generatedPrefix](const std::string_view& prefix)
                                    { return generatedPrefix == prefix; }) ||
                generatedPrefix.empty());
}

TEST_P(PersonTest, shouldGenerateSuffix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

    const auto& malesSuffixes = peopleNames.malesNames.suffixes;

    std::vector<std::string_view> suffixes(femalesSuffixes.begin(), femalesSuffixes.end());

    suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());

    const auto generatedSuffix = suffix(locale);

    ASSERT_TRUE(std::ranges::any_of(suffixes, [generatedSuffix](const std::string_view& suffix)
                                    { return generatedSuffix == suffix; }) ||
                generatedSuffix.empty());
}

TEST_P(PersonTest, shouldGenerateMaleSuffix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& malesSuffixes = peopleNames.malesNames.suffixes;

    const auto generatedSuffix = suffix(locale, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesSuffixes, [generatedSuffix](const std::string_view& suffix)
                                    { return generatedSuffix == suffix; }) ||
                generatedSuffix.empty());
}

TEST_P(PersonTest, shouldGenerateFemaleSuffix)
{
    const auto locale = GetParam();

    const auto& peopleNames = getPersonDefinition(locale);

    const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

    const auto generatedSuffix = suffix(locale, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesSuffixes, [generatedSuffix](const std::string_view& suffix)
                                    { return generatedSuffix == suffix; }) ||
                generatedSuffix.empty());
}

TEST_P(PersonTest, shouldGenerateSex)
{
    const auto locale = GetParam();

    const auto generatedSex = sex(locale);

    const auto sexTranslation =
        sexTranslations.contains(locale) ? sexTranslations.at(locale) : sexTranslations.at(Locale::en_US);

    ASSERT_TRUE(generatedSex == sexTranslation.at(Sex::Male) || generatedSex == sexTranslation.at(Sex::Female));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByLocale, PersonTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = gender();

    ASSERT_TRUE(std::ranges::any_of(genders, [generatedGender](const std::string_view& gender)
                                    { return gender == generatedGender; }));
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = jobDescriptor();

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string_view& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = jobArea();

    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string_view& jobArea)
                                    { return jobArea == generatedJobArea; }));
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = jobType();

    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string_view& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = jobTitle();

    const auto jobTitleElements = common::split(generatedJobTitle, " ");

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
    const auto generatedHobby = hobby();

    ASSERT_TRUE(std::ranges::any_of(hobbies, [generatedHobby](const std::string_view& hobby)
                                    { return hobby == generatedHobby; }));
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = bio();

    ASSERT_TRUE(checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    const auto generatedLanguage = language();

    ASSERT_TRUE(std::ranges::any_of(languages, [generatedLanguage](const std::string_view& language)
                                    { return generatedLanguage == language; }));
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    const auto generatedNationality = nationality();

    ASSERT_TRUE(std::ranges::any_of(nationalities, [generatedNationality](const std::string_view& nationality)
                                    { return generatedNationality == nationality; }));
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    const auto generatedWesternZodiacs = westernZodiac();

    ASSERT_TRUE(std::ranges::any_of(westernZodiacs, [generatedWesternZodiacs](const std::string_view& westernZodiac)
                                    { return generatedWesternZodiacs == westernZodiac; }));
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = chineseZodiac();

    ASSERT_TRUE(std::ranges::any_of(chineseZodiacs, [generatedChineseZodiacs](const std::string_view& chineseZodiac)
                                    { return generatedChineseZodiacs == chineseZodiac; }));
}

const std::unordered_map<Locale, unsigned> ssnLengths{
    {Locale::pl_PL, 11}, {Locale::es_US, 11}, {Locale::en_US, 11}, {Locale::en_GB, 13}, {Locale::de_DE, 12},
    {Locale::fr_FR, 19}, {Locale::it_IT, 19}, {Locale::es_ES, 10}, {Locale::ca_ES, 10}, {Locale::as_IN, 10},
    {Locale::bn_IN, 10}, {Locale::en_IN, 10}, {Locale::gu_IN, 10}, {Locale::hi_IN, 10}, {Locale::kn_IN, 10},
    {Locale::ks_IN, 10}, {Locale::ml_IN, 10}, {Locale::mr_IN, 10}, {Locale::or_IN, 10}, {Locale::pa_IN, 10},
    {Locale::sa_IN, 10}, {Locale::ta_IN, 10}, {Locale::te_IN, 10},
};

class PersonSsnSuite : public TestWithParam<Locale>
{
};

TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto locale = GetParam();

    const auto generatedSsn = ssn(locale);

    const auto expectedSsnLength = ssnLengths.contains(locale) ? ssnLengths.at(locale) : ssnLengths.at(Locale::en_US);

    ASSERT_EQ(generatedSsn.size(), expectedSsnLength);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite, testing::ValuesIn(locales),
                         [](const testing::TestParamInfo<PersonSsnSuite::ParamType>& paramInfo)
                         { return toString(paramInfo.param); });

class PersonPassportTest : public Test
{
public:
};

TEST_F(PersonPassportTest, shouldGenerateUsaPassport)
{
    const auto passportNumber = passport(Locale::en_US);

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
    const auto passportNumber = passport(Locale::pl_PL);

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
    const auto passportNumber = passport(Locale::fr_FR);

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
    const auto passportNumber = passport(Locale::ro_RO);
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
    const std::regex firstRegex(R"(^(\w+\s?\w+)$)");
    const std::regex secondRegex(R"(^(\w+\s?\w+), (\w+\s?\w+)$)");
    const std::regex thirdRegex(R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)");
    const std::regex fourthRegex(R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)");
    const std::regex fifthRegex(R"(^(\w+\-?\w+) (\w+)$)");
    const std::regex sixthRegex(R"(^(\w+\-?\w+) (\w+) (\S+)$)");
    const std::regex seventhRegex(R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)");
    const std::regex eightRegex(R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)");

    std::smatch matches;
    //
    if (std::regex_match(bio, matches, firstRegex))
    {
        // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part
        // vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string(matches[0])) != bioParts.end())
        {
            return true;
        }
    }

    if (std::regex_match(bio, matches, secondRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is present in the
        // bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string(matches[1])) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[2])) != bioParts.end())
        {
            return true;
        }
    }

    if (std::regex_match(bio, matches, thirdRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string(matches[1])) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[2])) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[3])) != bioParts.end())
            return true;
    }

    if (std::regex_match(bio, matches, fourthRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(bioParts.begin(), bioParts.end(), std::string(matches[1])) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[2])) != bioParts.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[3])) != bioParts.end() &&
            internet::checkIfEmojiIsValid(std::string(matches[4])))
            return true;
    }

    if (std::regex_match(bio, matches, fifthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is present
        // in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string(matches[1])) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string(matches[2])) != bioSupporters.end())
            return true;
    }

    if (std::regex_match(bio, matches, sixthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string(matches[1])) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string(matches[2])) != bioSupporters.end() &&
            internet::checkIfEmojiIsValid(std::string(matches[3])))
            return true;
    }


    if (std::regex_match(bio, matches, seventhRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string(matches[1])) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string(matches[2])) != bioSupporters.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[3])) != bioParts.end())
            return true;
    }

    if (std::regex_match(bio, matches, eightRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(word::nouns.begin(), word::nouns.end(), std::string(matches[1])) != word::nouns.end() &&
            std::find(bioSupporters.begin(), bioSupporters.end(), std::string(matches[2])) != bioSupporters.end() &&
            std::find(bioParts.begin(), bioParts.end(), std::string(matches[3])) != bioParts.end() &&
            internet::checkIfEmojiIsValid(std::string(matches[4])))
            return true;
    }

    return false;
}
