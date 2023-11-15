#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SlovakFirstNames.h"
#include "SlovakLastNames.h"
#include "SlovakPrefixes.h"
#include "SlovakSuffixes.h"

namespace faker
{
const NameFormats slovakPersonNameFormats{
    {{"{firstName} {lastName}", 8}, {"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames slovakPeopleNames{{slovakMalesFirstNames, {}, slovakMalesLastNames, slovakPrefixes, slovakSuffixes},
                                   {slovakFemalesFirstNames, {}, slovakFemalesLastNames, slovakPrefixes, slovakSuffixes},
                                   slovakPersonNameFormats};
}
