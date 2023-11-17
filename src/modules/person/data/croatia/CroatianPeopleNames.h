#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "CroatianFirstNames.h"
#include "CroatianLastNames.h"
#include "CroatianPrefixes.h"
#include "CroatianSuffixes.h"

namespace faker
{
const NameFormats croatianPersonNameFormats{
    {{"{firstName} {lastName}", 8}, {"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames croatianPeopleNames{
    {croatianMalesFirstNames, {}, croatianLastNames, croatianMalesPrefixes, croatianSuffixes},
    {croatianFemalesFirstNames, {}, croatianLastNames, croatianFemalesPrefixes, croatianSuffixes},
    croatianPersonNameFormats};
}
