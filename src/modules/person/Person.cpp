#include "faker-cxx/Person.h"

#include <map>
#include <set>

#include "../../common/StringHelper.h"
#include "data/czech/CzechPeopleNames.h"
#include "data/english/EnglishPeopleNames.h"
#include "data/finnish/FinnishPeopleNames.h"
#include "data/french/FrenchPeopleNames.h"
#include "data/Gender.h"
#include "data/german/GermanPeopleNames.h"
#include "data/Hobbies.h"
#include "data/indian/IndianPeopleNames.h"
#include "data/italian/ItalianPeopleNames.h"
#include "data/JobTitles.h"
#include "data/Nationalities.h"
#include "data/nepalese/NepalesePeopleNames.h"
#include "data/polish/PolishPeopleNames.h"
#include "data/romanian/RomanianPeopleNames.h"
#include "data/russian/RussianPeopleNames.h"
#include "data/slovak/SlovakPeopleNames.h"
#include "data/spanish/SpanishPeopleNames.h"
#include "data/turkish/TurkishPeopleNames.h"
#include "data/ZodiacSigns.h"
#include "faker-cxx/Helper.h"
#include "fmt/format.h"

namespace faker
{
namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Language, PeopleNames> languageToPeopleNamesMapping{
    {Language::English, englishPeopleNames},   {Language::French, frenchPeopleNames},
    {Language::German, germanPeopleNames},     {Language::Italian, italianPeopleNames},
    {Language::Polish, polishPeopleNames},     {Language::Russian, russianPeopleNames},
    {Language::Romanian, romanianPeopleNames}, {Language::Hindi, indianPeopleNames},
    {Language::Finnish, finnishPeopleNames},   {Language::Nepali, nepalesePeopleNames},
    {Language::Spanish, spanishPeopleNames},   {Language::Turkish, turkishPeopleNames},
    {Language::Czech, czechPeopleNames},       {Language::Slovak, slovakPeopleNames}};

std::string middleNameForLanguage(Language language, std::optional<Sex> sex);
std::string prefixForLanguage(Language language, std::optional<Sex> sex);
std::string suffixForLanguage(Language language, std::optional<Sex> sex);
}

std::string Person::firstName(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<std::string> firstNames;

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

    return Helper::arrayElement<std::string>(firstNames);
}

std::string Person::lastName(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<std::string> lastNames;

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

    return Helper::arrayElement<std::string>(lastNames);
}

std::string Person::middleName(std::optional<Sex> sex)
{
    std::vector<std::string> allMiddleNames;

    for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
    {
        std::vector<std::string> middleNames;

        if (sex == Sex::Male)
        {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        }
        else if (sex == Sex::Female)
        {
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }
        else
        {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
            middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }

        std::set<std::string> uniqueMiddleNames(middleNames.begin(), middleNames.end());

        middleNames.assign(uniqueMiddleNames.begin(), uniqueMiddleNames.end());

        allMiddleNames.insert(allMiddleNames.end(), middleNames.begin(), middleNames.end());
    }

    if (allMiddleNames.empty())
    {
        throw std::runtime_error{fmt::format("No middle name fround, sex: {}.", sex ? toString(*sex) : "none")};
    }

    return Helper::arrayElement<std::string>(allMiddleNames);
}

std::string Person::fullName(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<Helper::WeightedElement<std::string>> weightedElements;

    for (const auto& nameFormat : peopleNames.nameFormats)
    {
        weightedElements.push_back({nameFormat.weight, nameFormat.format});
    }

    const auto nameFormat = Helper::weightedArrayElement<std::string>(weightedElements);

    const auto nameFormatElements = StringHelper::split(nameFormat, " ");

    std::vector<std::string> nameElements;

    for (const auto& nameFormatElement : nameFormatElements)
    {
        if (nameFormatElement == "{firstName}")
        {
            nameElements.push_back(Person::firstName(language, sex));
        }
        else if (nameFormatElement == "{middleName}")
        {
            nameElements.push_back(middleNameForLanguage(language, sex));
        }
        else if (nameFormatElement == "{lastName}")
        {
            nameElements.push_back(Person::lastName(language, sex));
        }
        else if (nameFormatElement == "{prefix}")
        {
            nameElements.push_back(prefixForLanguage(language, sex));
        }
        else if (nameFormatElement == "{suffix}")
        {
            nameElements.push_back(suffixForLanguage(language, sex));
        }
    }

    return StringHelper::join(nameElements, " ");
}

std::string Person::prefix(std::optional<Sex> sex)
{
    std::vector<std::string> allPrefixes;

    for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
    {
        std::vector<std::string> prefixes;

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

        std::set<std::string> uniquePrefixes(prefixes.begin(), prefixes.end());

        prefixes.assign(uniquePrefixes.begin(), uniquePrefixes.end());

        allPrefixes.insert(allPrefixes.end(), prefixes.begin(), prefixes.end());
    }

    if (allPrefixes.empty())
    {
        throw std::runtime_error{fmt::format("No prefixes fround, sex: {}.", sex ? toString(*sex) : "none")};
    }

    return Helper::arrayElement<std::string>(allPrefixes);
}

std::string Person::suffix()
{
    std::vector<std::string> allSuffixes;

    for (const auto& [_, peopleNames] : languageToPeopleNamesMapping)
    {
        std::vector<std::string> suffixes;

        const auto& malesSuffixes = peopleNames.malesNames.suffixes;
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());

        std::set<std::string> uniqueSuffixes(suffixes.begin(), suffixes.end());

        suffixes.assign(uniqueSuffixes.begin(), uniqueSuffixes.end());

        allSuffixes.insert(allSuffixes.end(), suffixes.begin(), suffixes.end());
    }

    return Helper::arrayElement<std::string>(allSuffixes);
}

std::string Person::sex()
{
    return Helper::arrayElement<std::string>(sexes);
}

std::string Person::gender()
{
    return Helper::arrayElement<std::string>(genders);
}

std::string Person::jobTitle()
{
    return fmt::format("{} {} {}", jobDescriptor(), jobArea(), jobType());
}

std::string Person::jobDescriptor()
{
    return Helper::arrayElement<std::string>(jobDescriptors);
}

std::string Person::jobArea()
{
    return Helper::arrayElement<std::string>(jobAreas);
}

std::string Person::jobType()
{
    return Helper::arrayElement<std::string>(jobTypes);
}

std::string Person::hobby()
{
    return Helper::arrayElement<std::string>(hobbies);
}

std::string Person::language()
{
    return toString(Helper::arrayElement<Language>(languages));
}

std::string Person::nationality()
{
    return Helper::arrayElement<std::string>(nationalities);
}

namespace
{
std::string middleNameForLanguage(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<std::string> middleNames;

    if (sex == Sex::Male)
    {
        const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

        middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

        middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
    }
    else
    {
        const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
        const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

        middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
    }

    return Helper::arrayElement<std::string>(middleNames);
}

std::string prefixForLanguage(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<std::string> prefixes;

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

    return Helper::arrayElement<std::string>(prefixes);
}

std::string suffixForLanguage(Language language, std::optional<Sex> sex)
{
    const auto& peopleNames = languageToPeopleNamesMapping.at(language);

    std::vector<std::string> suffixes;

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

    return Helper::arrayElement<std::string>(suffixes);
}
}

std::string Person::westernZodiac()
{
    return Helper::arrayElement<std::string>(westernZodiacs);
}

std::string Person::chineseZodiac()
{
    return Helper::arrayElement<std::string>(chineseZodiacs);
}
}
