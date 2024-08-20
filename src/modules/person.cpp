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
#include "faker-cxx/types/country.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/word.h"
#include "person_data.h"

namespace faker::person
{
namespace
{
const std::unordered_map<Locale, std::string_view> passportFormats{
    {Locale::es_US, "AA0000000"}, {Locale::en_US, "AA0000000"}, {Locale::pl_PL, "AA0000000"},
    {Locale::fr_FR, "00AA00000"}, {Locale::ro_RO, "00000000"},
};

const struct PeopleNames& getPeopleNamesByCountry(const Country& country)
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

std::string_view firstName(std::optional<Country> country, std::optional<Sex> sex)
{
    const auto countryStr = country ? *country : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(countryStr);

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

std::string_view lastName(std::optional<Country> country, std::optional<Sex> sex)
{
    const auto countryStr = country ? *country : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(countryStr);

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

std::string fullName(std::optional<Country> country, std::optional<Sex> sex)
{
    const auto countryStr = country ? *country : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(countryStr);

    std::vector<helper::WeightedElement<std::string_view>> weightedElements;
    weightedElements.reserve(peopleNames.nameFormats.size());

    std::transform(peopleNames.nameFormats.begin(), peopleNames.nameFormats.end(), std::back_inserter(weightedElements),
                   [](const NameFormat& nameFormat) {
                       return helper::WeightedElement<std::string_view>{nameFormat.weight, nameFormat.format};
                   });

    const auto nameFormat = static_cast<std::string>(helper::weightedRandomElement<std::string_view>(weightedElements));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&countryStr, &sex]() { return std::string{firstName(countryStr, sex)}; }},
        {"lastName", [&countryStr, &sex]() { return std::string{lastName(countryStr, sex)}; }},
        {"prefix", [&countryStr, &sex]() { return std::string{prefix(countryStr, sex)}; }},
        {"suffix", [&countryStr, &sex]() { return std::string{suffix(countryStr, sex)}; }}};

    return common::fillTokenValues(nameFormat, dataGeneratorsMapping);
}

std::string_view prefix(std::optional<Country> country, std::optional<Sex> sex)
{
    const auto countryStr = country ? *country : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(countryStr);

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

std::string_view suffix(std::optional<Country> country, std::optional<Sex> sex)
{
    const auto countryStr = country ? *country : Country::England;

    const auto& peopleNames = getPeopleNamesByCountry(countryStr);

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

std::string_view sex(std::optional<Language> language)
{
    const std::vector<std::string> sexes{"Male", "Female"};

    const auto chosenSex = helper::randomElement(sexes);

    const auto sexEnum = chosenSex == "Male" ? Sex::Male : Sex::Female;

    const auto languageStr = language ? *language : Language::English;

    const auto sexTranslation = sexTranslations.find(languageStr);

    if (sexTranslation == sexTranslations.end())
    {
        throw std::runtime_error{"Sex not found."};
    }

    return sexTranslation->second.at(sexEnum);
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

std::string ssn(std::optional<SsnCountry> country)
{
    const auto ssnCountry = country ? *country : helper::randomElement(supportedSsnCountries);

    const auto& ssnFormat = std::string{ssnFormats.at(ssnCountry)};

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
    const auto& passportFormat = passportFormats.at(locale);

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
