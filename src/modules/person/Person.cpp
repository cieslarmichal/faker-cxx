#include "faker-cxx/Person.h"

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "common/FormatHelper.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/Word.h"
#include "PersonData.h"

namespace faker
{
namespace
{
const std::unordered_map<PassportCountry, std::string_view> passportFormats{
    {PassportCountry::Usa, "AA0000000"},
    {PassportCountry::Poland, "AA0000000"},
    {PassportCountry::France, "00AA00000"},
    {PassportCountry::Romania, "00000000"},
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

}

std::string_view Person::firstName(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    const auto country = countryOpt ? *countryOpt : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(country);

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

    return Helper::arrayElement(firstNames);
}

std::string_view Person::lastName(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    const auto country = countryOpt ? *countryOpt : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(country);

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

    return Helper::arrayElement(lastNames);
}

std::string_view Person::middleName(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    return firstName(countryOpt, sex);
}

std::string Person::fullName(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    const auto country = countryOpt ? *countryOpt : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(country);

    std::vector<Helper::WeightedElement<std::string_view>> weightedElements;

    for (const auto& nameFormat : peopleNames.nameFormats)
    {
        weightedElements.push_back({nameFormat.weight, nameFormat.format});
    }

    const auto nameFormat = static_cast<std::string>(Helper::weightedArrayElement<std::string_view>(weightedElements));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&country, &sex]() { return std::string{firstName(country, sex)}; }},
        {"middleName", [&country, &sex]() { return std::string{middleName(country, sex)}; }},
        {"lastName", [&country, &sex]() { return std::string{lastName(country, sex)}; }},
        {"prefix", [&country, &sex]() { return std::string{middleName(country, sex)}; }},
        {"suffix", [&country, &sex]() { return std::string{middleName(country, sex)}; }}};

    return FormatHelper::fillTokenValues(nameFormat, dataGeneratorsMapping);
}

std::string_view Person::prefix(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    const auto country = countryOpt ? *countryOpt : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(country);

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

    return Helper::arrayElement(prefixes);
}

std::string_view Person::suffix(std::optional<Country> countryOpt, std::optional<Sex> sex)
{
    const auto country = countryOpt ? *countryOpt : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(country);

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

    return Helper::arrayElement(suffixes);
}

std::string Person::bio()
{
    const auto randomBioFormat = static_cast<std::string>(Helper::arrayElement(bioFormats));

    const std::unordered_map<std::string_view, std::function<std::string_view()>> dataGeneratorsMapping{
        {"bio_part", []() { return Helper::arrayElement(bioParts); }},
        {"bio_supporter", []() { return Helper::arrayElement(bioSupporters); }},
        {"noun", []() { return Word::noun(); }},
        {"emoji", []() { return Internet::emoji(); }}};

    return FormatHelper::fillTokenValues(randomBioFormat, dataGeneratorsMapping);
}

std::string_view Person::sex(std::optional<Language> languageOpt)
{
    const std::vector<std::string> sexes{"Male", "Female"};

    const auto chosenSex = Helper::arrayElement(sexes);

    const auto sexEnum = chosenSex == "Male" ? Sex::Male : Sex::Female;

    const auto language = languageOpt ? *languageOpt : Language::English;

    const auto sexTranslation = sexTranslations.find(language);

    if (sexTranslation == sexTranslations.end())
    {
        throw std::runtime_error{"Sex not found."};
    }

    return sexTranslation->second.at(sexEnum);
}

std::string_view Person::gender()
{
    return Helper::arrayElement(genders);
}

std::string Person::jobTitle()
{
    return FormatHelper::format("{} {} {}", jobDescriptor(), jobArea(), jobType());
}

std::string_view Person::jobDescriptor()
{
    return Helper::arrayElement(jobDescriptors);
}

std::string_view Person::jobArea()
{
    return Helper::arrayElement(jobAreas);
}

std::string_view Person::jobType()
{
    return Helper::arrayElement(jobTypes);
}

std::string_view Person::hobby()
{
    return Helper::arrayElement(hobbies);
}

std::string_view Person::language()
{
    return Helper::arrayElement(languages);
}

std::string_view Person::nationality()
{
    return Helper::arrayElement(nationalities);
}

std::string Person::ssn(std::optional<SsnCountry> country)
{
    const auto ssnCountry = country ? *country : Helper::arrayElement(supportedSsnCountries);

    const auto& ssnFormat = std::string{ssnFormats.at(ssnCountry)};

    auto ssnWithoutRegexes = Helper::regexpStyleStringParse(ssnFormat);

    std::string ssn;

    for (const auto& ssnFormatCharacter : ssnWithoutRegexes)
    {
        if (ssnFormatCharacter == 'L')
        {
            ssn += String::alpha(1, StringCasing::Upper);
        }
        else if (ssnFormatCharacter == 'F')
        {
            ssn += String::alphanumeric(1, StringCasing::Upper);
        }
        else if (ssnFormatCharacter == '#')
        {
            ssn += std::to_string(Number::integer(0, 9));
        }
        else
        {
            ssn += ssnFormatCharacter;
        }
    }

    return ssn;
}

std::string_view Person::westernZodiac()
{
    return Helper::arrayElement(westernZodiacs);
}

std::string_view Person::chineseZodiac()
{
    return Helper::arrayElement(chineseZodiacs);
}

std::string Person::passport(std::optional<PassportCountry> countryOpt)
{
    const auto country = countryOpt ? *countryOpt : PassportCountry::Usa;

    const auto& passportFormat = passportFormats.at(country);

    std::string passportNumber;

    for (const char& c : passportFormat)
    {
        if (c == 'A')
        {
            passportNumber += String::alpha(1, StringCasing::Upper);
        }

        else if (c == '0')
        {
            passportNumber += String::numeric(1);
        }
    }

    return passportNumber;
}

}
