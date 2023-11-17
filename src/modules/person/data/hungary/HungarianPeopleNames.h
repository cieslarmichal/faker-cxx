#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "HungarianFirstNames.h"
#include "HungarianLastNames.h"
#include "HungarianPrefixes.h"

namespace faker
{
const NameFormats hungarianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames hungarianPeopleNames{{hungarianMalesFirstNames, {}, hungarianLastNames, hungarianPrefixes, {}},
                                       {hungarianFemalesFirstNames, {}, hungarianLastNames, hungarianPrefixes, {}},
                                       hungarianPersonNameFormats};

}
