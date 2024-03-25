#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SouthAfricanFirstNames.h"
#include "SouthAfricanLastNames.h"

namespace faker
{
const NameFormats southAfricanPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames southAfricanPeopleNames{{southAfricanMalesFirstNames, {}, southAfricanLastNames, {}, {}},
                                          {southAfricanFemalesFirstNames, {}, southAfricanLastNames, {}, {}},
                                          southAfricanPersonNameFormats};
}
