#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "RomanianFirstNames.h"
#include "RomanianLastNames.h"
#include "RomanianPrefixes.h"
#include "RomanianSuffixes.h"

namespace faker
{
const NameFormats romanianPersonNameFormats{{{"{firstName} {lastName}", 49},
                                             {"{lastName} {firstName}", 7},
                                             {"{prefix} {firstName} {lastName}", 7},
                                             {"{firstName} {lastName} {suffix}", 7},
                                             {"{prefix} {firstName} {lastName} {suffix}", 1}}};

const PeopleNames romanianPeopleNames{
    {romanianMalesFirstNames, {}, romanianLastNames, romanianMalesPrefixes, romanianSuffixes},
    {romanianFemalesFirstNames, {}, romanianLastNames, romanianFemalesPrefixes, romanianSuffixes},
    romanianPersonNameFormats};

}
