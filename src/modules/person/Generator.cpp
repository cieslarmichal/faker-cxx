#include "../helpers/Generator.h"

#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"
#include "Generator.h"

namespace faker::person
{
std::string firstName()
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    return helpers::arrayElement(firstNames);
}

std::string lastName()
{
    return helpers::arrayElement(lastNames);
}
}
