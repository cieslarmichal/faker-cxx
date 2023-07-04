#include "Person.h"

#include <format>

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"
#include "Helper.h"

namespace faker
{
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

    return Helper::arrayElement(firstNames);
}

std::string Person::lastName()
{
    return Helper::arrayElement(lastNames);
}

std::string Person::fullName(std::optional<Sex> sex)
{
    return std::format("{} {}", firstName(sex), lastName());
}
}
