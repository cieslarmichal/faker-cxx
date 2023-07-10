#include "Person.h"

#include <format>

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/Gender.h"
#include "data/LastNames.h"
#include "Helper.h"

namespace faker
{
namespace
{
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
}
