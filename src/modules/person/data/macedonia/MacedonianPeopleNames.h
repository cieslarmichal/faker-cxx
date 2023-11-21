#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MacedonianFirstNames.h"
#include "MacedonianLastNames.h"
#include "MacedonianPrefixes.h"

namespace faker
{
const NameFormats macedonianPersonNameFormats{{{"{firstName} {lastName}", 10}, {"{prefix} {firstName} {lastName}", 1}}};

const PeopleNames macedonianPeopleNames{
    {macedonianMalesFirstNames, {}, macedonianMalesLastNames, macedonianMalesPrefixes, {}},
    {macedonianFemalesFirstNames, {}, macedonianFemalesLastNames, macedonianFemalesPrefixes, {}},
    macedonianPersonNameFormats};

}
