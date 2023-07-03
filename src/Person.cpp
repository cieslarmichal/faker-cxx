#include "Person.h"

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"
#include "Helper.h"

namespace faker
{
std::string Person::firstName()
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    return Helper::arrayElement(firstNames);
}

std::string Person::lastName()
{
    return Helper::arrayElement(lastNames);
}
}
