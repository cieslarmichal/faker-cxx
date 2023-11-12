#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "GermanFirstNames.h"
#include "GermanLastNames.h"
#include "GermanPrefixes.h"

namespace faker
{
const NameFormats germanPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 8}}};

const PeopleNames germanPeopleNames{{germanMalesFirstNames, {}, germanLastNames, germanMalesPrefixes, {}},
                                    {germanFemalesFirstNames, {}, germanLastNames, germanFemalesPrefixes, {}},
                                    germanPersonNameFormats};

}
