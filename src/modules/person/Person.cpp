#include "faker-cxx/Person.h"

#include <map>

#include "data/english/EnglishFirstNamesFemales.h"
#include "data/english/EnglishFirstNamesMales.h"
#include "data/english/EnglishLastNames.h"
#include "data/finnish/FinnishFirstNamesFemales.h"
#include "data/finnish/FinnishFirstNamesMales.h"
#include "data/finnish/FinnishLastNames.h"
#include "data/french/FrenchFirstNamesFemales.h"
#include "data/french/FrenchFirstNamesMales.h"
#include "data/french/FrenchLastNames.h"
#include "data/Gender.h"
#include "data/german/GermanFirstNamesFemales.h"
#include "data/german/GermanFirstNamesMales.h"
#include "data/german/GermanLastNames.h"
#include "data/Hobbies.h"
#include "data/indian/IndianFirstNames.h"
#include "data/indian/IndianLastNames.h"
#include "data/italian/ItalianFirstNamesFemales.h"
#include "data/italian/ItalianFirstNamesMales.h"
#include "data/italian/ItalianLastNames.h"
#include "data/JobTitles.h"
#include "data/Nationalities.h"
#include "data/nepalese/NepaleseFirstNamesFemales.h"
#include "data/nepalese/NepaleseFirstNamesMales.h"
#include "data/nepalese/NepaleseLastNames.h"
#include "data/polish/PolishFirstNamesFemales.h"
#include "data/polish/PolishFirstNamesMales.h"
#include "data/polish/PolishLastNames.h"
#include "data/romanian/RomanianFirstNamesFemales.h"
#include "data/romanian/RomanianFirstNamesMales.h"
#include "data/romanian/RomanianLastNames.h"
#include "data/russian/RussianFirstNamesFemales.h"
#include "data/russian/RussianFirstNamesMales.h"
#include "data/russian/RussianLastNamesFemales.h"
#include "data/russian/RussianLastNamesMales.h"
#include "data/spanish/SpanishFirstNamesFemales.h"
#include "data/spanish/SpanishFirstNamesMales.h"
#include "data/spanish/SpanishLastNames.h"
#include "faker-cxx/Helper.h"
#include "fmt/format.h"

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
    {Language::Russian, {{Sex::Male, russianFirstNamesMales}, {Sex::Female, russianFirstNamesFemales}}},
    {Language::Romanian, {{Sex::Male, romanianFirstNamesMales}, {Sex::Female, romanianFirstNamesFemales}}},
    {Language::Hindi, {{Sex::Male, indianFirstNamesMales}, {Sex::Female, indianFirstNamesFemales}}},
    {Language::Finnish, {{Sex::Male, finnishFirstNamesMales}, {Sex::Female, finnishFirstNamesFemales}}},
    {Language::Nepali, {{Sex::Male, nepaleseFirstNamesMales}, {Sex::Female, nepaleseFirstNamesFemales}}},
    {Language::Spanish, {{Sex::Male, spanishFirstNamesMales}, {Sex::Female, spanishFirstNamesFemales}}},
};

const std::map<Language, std::map<Sex, std::vector<std::string>>> languageToLastNamesMapping{
    {Language::English, {{Sex::Male, englishLastNames}, {Sex::Female, englishLastNames}}},
    {Language::French, {{Sex::Male, frenchLastNames}, {Sex::Female, frenchLastNames}}},
    {Language::German, {{Sex::Male, germanLastNames}, {Sex::Female, germanLastNames}}},
    {Language::Italian, {{Sex::Male, italianLastNames}, {Sex::Female, italianLastNames}}},
    {Language::Polish, {{Sex::Male, polishLastNames}, {Sex::Female, polishLastNames}}},
    {Language::Russian, {{Sex::Male, russianLastNamesMales}, {Sex::Female, russianLastNamesFemales}}},
    {Language::Romanian, {{Sex::Male, romanianLastNames}, {Sex::Female, romanianLastNames}}},
    {Language::Hindi, {{Sex::Male, indianLastNames}, {Sex::Female, indianLastNames}}},
    {Language::Finnish, {{Sex::Male, finnishLastNames}, {Sex::Female, finnishLastNames}}},
    {Language::Nepali, {{Sex::Male, nepaleseLastNames}, {Sex::Female, nepaleseLastNames}}},
    {Language::Spanish, {{Sex::Male, spanishLastNames}, {Sex::Female, spanishLastNames}}},
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

std::string Person::lastName(Language language, std::optional<Sex> sex)
{
    const auto& lastNamesBySexMapping = languageToLastNamesMapping.at(language);

    std::vector<std::string> lastNames;

    if (sex == Sex::Male)
    {
        const auto& lastNamesMales = lastNamesBySexMapping.at(Sex::Male);

        lastNames.insert(lastNames.end(), lastNamesMales.begin(), lastNamesMales.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& lastNamesFemales = lastNamesBySexMapping.at(Sex::Female);

        lastNames.insert(lastNames.end(), lastNamesFemales.begin(), lastNamesFemales.end());
    }
    else
    {
        const auto& lastNamesMales = lastNamesBySexMapping.at(Sex::Male);
        const auto& lastNamesFemales = lastNamesBySexMapping.at(Sex::Female);

        lastNames.insert(lastNames.end(), lastNamesMales.begin(), lastNamesMales.end());
        lastNames.insert(lastNames.end(), lastNamesFemales.begin(), lastNamesFemales.end());
    }
    return Helper::arrayElement<std::string>(lastNames);
}

std::string Person::fullName(Language language, std::optional<Sex> sex)
{
    return fmt::format("{} {}", firstName(language, sex), lastName(language, sex));
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
}
