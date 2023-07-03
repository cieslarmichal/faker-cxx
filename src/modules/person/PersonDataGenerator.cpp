#include "PersonDataGenerator.h"

#include "data/FirstNamesMales.h"
#include "data/LastNames.h"

namespace faker::person
{
std::string PersonDataGenerator::firstName()
{
    return firstNamesMales[0];
}

std::string PersonDataGenerator::lastName()
{
    return lastNames[0];
}
}
