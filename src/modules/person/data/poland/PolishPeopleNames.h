#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PolishFirstNames.h"
#include "PolishLastNames.h"
#include "PolishPrefixes.h"

namespace faker
{
const NameFormats polishPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames polishPeopleNames{{polishMalesFirstNames, {}, polishLastNames, polishMalesPrefixes, {}},
                                    {polishFemalesFirstNames, {}, polishLastNames, polishFemalesPrefixes, {}},
                                    polishPersonNameFormats};

}
