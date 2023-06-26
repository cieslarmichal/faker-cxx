#include "PersonGenerator.h"

#include "data/FirstNamesMales.h"

namespace faker::person
{
std::string PersonGenerator::firstName()
{
    return firstNamesMales[0];
}
}
