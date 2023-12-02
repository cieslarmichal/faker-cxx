#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "DutchFirstNames.h"
#include "DutchLastNames.h"
#include "DutchPrefixes.h"
#include "DutchSuffixes.h"

namespace faker
{
const NameFormats dutchPersonNameFormats{{
    {"{firstName} {lastName}", 8},
    {"{prefix} {firstName} {lastName}", 1},
    {"{firstName} {lastName} {suffix}", 1},
}};

const PeopleNames dutchPeopleNames{{dutchMalesFirstNames, {}, dutchLastNames, dutchMalesPrefixes, dutchSuffixes},
                                   {dutchFemalesFirstNames, {}, dutchLastNames, dutchFemalesPrefixes, dutchSuffixes},
                                   dutchPersonNameFormats};
}
