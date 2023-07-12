#include "Person.h"

#include <format>

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/Gender.h"
#include "data/JobTitles.h"
#include "data/LastNames.h"
#include "Helper.h"

namespace faker
{
namespace
{
const auto malePrefix{"Mr."};
const std::vector<std::string> femalePrefixes{"Ms.", "Miss"};
const std::vector<std::string> allPrefixes{"Mr.", "Ms.", "Miss"};
const std::vector<std::string> sexes{"Male", "Female"};
}

std::string Person::firstName(std::optional<Sex> sex)
{
    std::vector<std::string> firstNames;

    if (sex == Sex::Male)
    {
        firstNames.insert(firstNames.end(), firstNamesMales.begin(), firstNamesMales.end());
    }
    else if (sex == Sex::Female)
    {
        firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());
    }
    else
    {
        firstNames.insert(firstNames.end(), firstNamesMales.begin(), firstNamesMales.end());
        firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());
    }

    return Helper::arrayElement<std::string>(firstNames);
}

std::string Person::lastName()
{
    return Helper::arrayElement<std::string>(lastNames);
}

std::string Person::fullName(std::optional<Sex> sex)
{
    return std::format("{} {}", firstName(sex), lastName());
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
