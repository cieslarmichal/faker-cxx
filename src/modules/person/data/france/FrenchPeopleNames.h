#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "FrenchFirstNames.h"
#include "FrenchLastNames.h"
#include "FrenchPrefixes.h"

namespace faker
{
const NameFormats frenchPersonNameFormats{{{"{prefix} {firstName} {lastName}", 2}, {"{firstName} {lastName}", 8}}};

const PeopleNames frenchPeopleNames{{frenchMalesFirstNames, {}, frenchLastNames, frenchMalesPrefixes, {}},
                                    {frenchFemalesFirstNames, {}, frenchLastNames, frenchFemalesPrefixes, {}},
                                    frenchPersonNameFormats};
}
