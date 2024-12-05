#include "faker-cxx/person.h"

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/internet.h"
#include "faker-cxx/number.h"
#include "faker-cxx/string.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/word.h"
#include "person_data.h"

namespace faker::person
{
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

std::string_view firstName(Locale locale, std::optional<Sex> sex)
{
    const auto& peopleNames = getPersonDefinition(locale);

    std::vector<std::string_view> firstNames;

    if (sex == Sex::Male)
    {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    }
    else
    {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    }

    return helper::randomElement(firstNames);
}

std::string_view lastName(Locale locale, std::optional<Sex> sex)
{
    const auto& peopleNames = getPersonDefinition(locale);

    std::vector<std::string_view> lastNames;

    if (sex == Sex::Male)
    {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    }
    else
    {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    }

    return helper::randomElement(lastNames);
}

std::string fullName(Locale locale, std::optional<Sex> sex)
{
    const auto& peopleNames = getPersonDefinition(locale);

    std::vector<helper::WeightedElement<std::string_view>> weightedElements;

    weightedElements.reserve(peopleNames.nameFormats.size());

    std::transform(peopleNames.nameFormats.begin(), peopleNames.nameFormats.end(), std::back_inserter(weightedElements),
                   [](const NameFormat& nameFormat) {
                       return helper::WeightedElement<std::string_view>{nameFormat.weight, nameFormat.format};
                   });

    const auto nameFormat = static_cast<std::string>(helper::weightedRandomElement<std::string_view>(weightedElements));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&locale, &sex]() { return std::string{firstName(locale, sex)}; }},
        {"lastName", [&locale, &sex]() { return std::string{lastName(locale, sex)}; }},
        {"prefix", [&locale, &sex]() { return std::string{prefix(locale, sex)}; }},
        {"suffix", [&locale, &sex]() { return std::string{suffix(locale, sex)}; }}};

    return common::fillTokenValues(nameFormat, dataGeneratorsMapping);
}

std::string_view prefix(Locale locale, std::optional<Sex> sex)
{
    const auto& peopleNames = getPersonDefinition(locale);

    std::vector<std::string_view> prefixes;

    if (sex == Sex::Male)
    {
        const auto& malesPrefixes = peopleNames.malesNames.prefixes;

        prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

        prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
    }
    else
    {
        const auto& malesPrefixes = peopleNames.malesNames.prefixes;
        const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

        prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
        prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
    }

    if (prefixes.empty())
    {
        return {};
    }

    return helper::randomElement(prefixes);
}

std::string_view suffix(Locale locale, std::optional<Sex> sex)
{
    const auto& peopleNames = getPersonDefinition(locale);

    std::vector<std::string_view> suffixes;

    if (sex == Sex::Male)
    {
        const auto& malesSuffixes = peopleNames.malesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
    }
    else
    {
        const auto& malesSuffixes = peopleNames.malesNames.suffixes;
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
    }

    if (suffixes.empty())
    {
        return {};
    }

    return helper::randomElement(suffixes);
}

std::string bio()
{
    const auto randomBioFormat = static_cast<std::string>(helper::randomElement(bioFormats));

    const std::unordered_map<std::string_view, std::function<std::string_view()>> dataGeneratorsMapping{
        {"bio_part", []() { return helper::randomElement(bioParts); }},
        {"bio_supporter", []() { return helper::randomElement(bioSupporters); }},
        {"noun", []() { return word::noun(); }},
        {"emoji", []() { return internet::emoji(); }}};

    return common::fillTokenValues(randomBioFormat, dataGeneratorsMapping);
}

std::string_view sex(Locale locale)
{
    const std::vector<Sex> sexes{Sex::Male, Sex::Female};

    const auto sex = helper::randomElement(sexes);

    auto sexTranslation = sexTranslations.find(locale);

    if (sexTranslation == sexTranslations.end())
    {
        sexTranslation = sexTranslations.find(Locale::en_US);
    }

    return sexTranslation->second.at(sex);
}

std::string_view gender()
{
    return helper::randomElement(genders);
}

std::string jobTitle()
{
    return common::format("{} {} {}", jobDescriptor(), jobArea(), jobType());
}

std::string_view jobDescriptor()
{
    return helper::randomElement(jobDescriptors);
}

std::string_view jobArea()
{
    return helper::randomElement(jobAreas);
}

std::string_view jobType()
{
    return helper::randomElement(jobTypes);
}

std::string_view hobby()
{
    return helper::randomElement(hobbies);
}

std::string_view language()
{
    return helper::randomElement(languages);
}

std::string_view nationality()
{
    return helper::randomElement(nationalities);
}

std::string ssn(Locale locale)
{
    const auto& ssnFormat =
        std::string{ssnFormats.contains(locale) ? ssnFormats.at(locale) : ssnFormats.at(Locale::en_US)};

    auto ssnWithoutRegexes = helper::regexpStyleStringParse(ssnFormat);

    std::string ssn;

    for (const auto& ssnFormatCharacter : ssnWithoutRegexes)
    {
        if (ssnFormatCharacter == 'L')
        {
            ssn += string::alpha(1, string::StringCasing::Upper);
        }
        else if (ssnFormatCharacter == 'F')
        {
            ssn += string::alphanumeric(1, string::StringCasing::Upper);
        }
        else if (ssnFormatCharacter == '#')
        {
            ssn += std::to_string(number::integer(0, 9));
        }
        else
        {
            ssn += ssnFormatCharacter;
        }
    }

    return ssn;
}

std::string_view westernZodiac()
{
    return helper::randomElement(westernZodiacs);
}

std::string_view chineseZodiac()
{
    return helper::randomElement(chineseZodiacs);
}

std::string passport(Locale locale)
{
    const auto& passportFormat =
        passportFormats.contains(locale) ? passportFormats.at(locale) : passportFormats.at(Locale::en_US);

    std::string passportNumber;

    for (const char& c : passportFormat)
    {
        if (c == 'A')
        {
            passportNumber += string::alpha(1, string::StringCasing::Upper);
        }

        else if (c == '0')
        {
            passportNumber += string::numeric(1);
        }
    }

    return passportNumber;
}

}
