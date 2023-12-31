#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BulgarianFirstNames.h"
#include "BulgarianLastNames.h"
#include "BulgarianPrefixes.h"
#include "BulgarianSuffixes.h"

namespace faker
{
const NameFormats bulgarianPersonNameFormats{{
    {"{firstName} {lastName}", 8},
    {"{prefix} {firstName} {lastName}", 1},
    {"{firstName} {lastName} {suffix}", 1},
}};

const PeopleNames bulgarianPeopleNames{
    {bulgarianMalesFirstNames, {}, bulgarianLastNames, bulgarianMalesPrefixes, bulgarianSuffixes},
    {bulgarianFemalesFirstNames, {}, bulgarianLastNames, bulgarianFemalesPrefixes, bulgarianSuffixes},
    bulgarianPersonNameFormats};
}
