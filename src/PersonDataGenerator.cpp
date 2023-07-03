#include "PersonDataGenerator.h"

#include "data/FirstNamesMales.h"
#include "data/FirstNamesFemales.h"
#include "data/LastNames.h"
#include "../helpers/HelperDataGenerator.h"

namespace faker::person
{
std::string PersonDataGenerator::firstName()
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    return helpers::HelperDataGenerator::arrayElement(firstNames);
}

std::string PersonDataGenerator::lastName()
{
    return helpers::HelperDataGenerator::arrayElement(lastNames);
}
}
