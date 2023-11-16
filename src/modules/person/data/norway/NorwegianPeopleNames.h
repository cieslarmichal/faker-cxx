#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "NorwegianFirstNames.h"
#include "NorwegianLastNames.h"
#include "NorwegianPrefixes.h"
#include "NorwegianSuffixes.h"

namespace faker
{
const NameFormats norwegianPersonNameFormats{
    {{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames norwegianPeopleNames{
    {norwegianMalesFirstNames, {}, norwegianLastNames, norwegianPrefixes, norwegianSuffixes},
    {norwegianFemalesFirstNames, {}, norwegianLastNames, norwegianPrefixes, norwegianSuffixes},
    norwegianPersonNameFormats};

}
