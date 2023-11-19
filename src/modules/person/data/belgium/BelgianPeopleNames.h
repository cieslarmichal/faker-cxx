#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BelgianFirstNames.h"
#include "BelgianLastNames.h"
#include "BelgianPrefixes.h"
#include "BelgianSuffixes.h"

namespace faker
{
const NameFormats belgianPersonNameFormats{{
    {"{firstName} {lastName}", 8},
    {"{prefix} {firstName} {lastName}", 1},
    {"{firstName} {lastName} {suffix}", 1},
}};

const PeopleNames belgianPeopleNames{{belgianMalesFirstNames, {}, belgianLastNames, belgianPrefixes, belgianSuffixes},
                                     {belgianFemalesFirstNames, {}, belgianLastNames, belgianPrefixes, belgianSuffixes},
                                     belgianPersonNameFormats};
}
