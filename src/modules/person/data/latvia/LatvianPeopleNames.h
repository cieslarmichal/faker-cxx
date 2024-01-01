#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "LatvianFirstNames.h"
#include "LatvianLastNames.h"
#include "LatvianPrefixes.h"
#include "LatvianSuffixes.h"

namespace faker
{
const NameFormats latvianPersonNameFormats{
    {{"{firstName} {lastName}", 8}, {"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames latvianPeopleNames{
    {latvianMalesFirstNames, {}, latvianMalesLastNames, latvianPrefixes, latvianSuffixes},
    {latvianFemalesFirstNames, {}, latvianFemalesLastNames, latvianPrefixes, latvianSuffixes},
    latvianPersonNameFormats};
}
