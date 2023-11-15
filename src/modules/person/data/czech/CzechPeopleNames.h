#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "CzechFirstNames.h"
#include "CzechLastNames.h"
#include "CzechPrefixes.h"
#include "CzechSuffixes.h"

namespace faker
{
const NameFormats czechPersonNameFormats{
    {{"{firstName} {lastName}", 8}, {"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames czechPeopleNames{{czechMalesFirstNames, {}, czechMalesLastNames, czechPrefixes, czechSuffixes},
                                   {czechFemalesFirstNames, {}, czechFemalesLastNames, czechPrefixes, czechSuffixes},
                                   czechPersonNameFormats};
}
