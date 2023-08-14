#include "faker-cxx/Person.h"

#include <format>
#include <map>

#include "data/english/EnglishFirstNamesFemales.h"
#include "data/english/EnglishFirstNamesMales.h"
#include "data/english/EnglishLastNames.h"
#include "data/french/FrenchFirstNamesFemales.h"
#include "data/french/FrenchFirstNamesMales.h"
#include "data/french/FrenchLastNames.h"
#include "data/Gender.h"
#include "data/german/GermanFirstNamesFemales.h"
#include "data/german/GermanFirstNamesMales.h"
#include "data/german/GermanLastNames.h"
#include "data/italian/ItalianFirstNamesFemales.h"
#include "data/italian/ItalianFirstNamesMales.h"
#include "data/italian/ItalianLastNames.h"
#include "data/JobTitles.h"
#include "data/polish/PolishFirstNamesFemales.h"
#include "data/polish/PolishFirstNamesMales.h"
#include "data/polish/PolishLastNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
namespace
{
const std::string malePrefix{"Mr."};
const std::vector<std::string> femalePrefixes{"Ms.", "Miss"};
const std::vector<std::string> allPrefixes{"Mr.", "Ms.", "Miss"};
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToFirstNamesMapping{
    {Language::English, {{Sex::Male, englishFirstNamesMales}, {Sex::Female, englishFirstNamesFemales}}},
    {Language::French, {{Sex::Male, frenchFirstNamesMales}, {Sex::Female, frenchFirstNamesFemales}}},
    {Language::German, {{Sex::Male, germanFirstNamesMales}, {Sex::Female, germanFirstNamesFemales}}},
    {Language::Italian, {{Sex::Male, italianFirstNamesMales}, {Sex::Female, italianFirstNamesFemales}}},
    {Language::Polish, {{Sex::Male, polishFirstNamesMales}, {Sex::Female, polishFirstNamesFemales}}},
};

const std::map<Language, std::vector<std::string>> languageToLastNamesMapping{
    {Language::English, englishLastNames}, {Language::French, frenchLastNames}, {Language::German, germanLastNames},
    {Language::Italian, italianLastNames}, {Language::Polish, polishLastNames},
};
}

std::string Person::firstName(Language language, std::optional<Sex> sex)
{
    const auto& firstNamesBySexMapping = languageToFirstNamesMapping.at(language);

    std::vector<std::string> firstNames;

    if (sex == Sex::Male)
    {
        const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);

        firstNames.insert(firstNames.end(), firstNamesMales.begin(), firstNamesMales.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

        firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());
    }
    else
    {
        const auto& firstNamesMales = firstNamesBySexMapping.at(Sex::Male);
        const auto& firstNamesFemales = firstNamesBySexMapping.at(Sex::Female);

        firstNames.insert(firstNames.end(), firstNamesMales.begin(), firstNamesMales.end());
        firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());
    }

    return Helper::arrayElement<std::string>(firstNames);
}

std::string Person::lastName(Language language)
{
    return Helper::arrayElement<std::string>(languageToLastNamesMapping.at(language));
}

std::string Person::fullName(Language language, std::optional<Sex> sex)
{
    return std::format("{} {}", firstName(language, sex), lastName(language));
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
    return std::format("{} {} {}", jobDescriptor(), jobArea(), jobType());
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

std::string Person::prefix(std::optional<Sex> sex)
{
    std::vector<std::string> prefixes;

    if (sex == Sex::Male)
    {
        return malePrefix;
    }
    else if (sex == Sex::Female)
    {
        return Helper::arrayElement<std::string>(femalePrefixes);
    }
    else
    {
        return Helper::arrayElement<std::string>(allPrefixes);
    }
}
}
