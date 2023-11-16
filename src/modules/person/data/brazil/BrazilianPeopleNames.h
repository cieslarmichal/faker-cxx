#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BrazilianFirstNames.h"
#include "BrazilianLastNames.h"
#include "BrazilianPrefixes.h"
#include "BrazilianSuffixes.h"

namespace faker
{
const NameFormats brazilianPersonNameFormats{
    {{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames brazilianPeopleNames{
    {brazilianMalesFirstNames, {}, brazilianLastNames, brazilianMalesPrefixes, brazilianSuffixes},
    {brazilianFemalesFirstNames, {}, brazilianLastNames, brazilianFemalesPrefixes, brazilianSuffixes},
    brazilianPersonNameFormats};

}
