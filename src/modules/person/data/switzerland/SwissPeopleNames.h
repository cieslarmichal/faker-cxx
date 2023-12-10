#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SwissFirstNames.h"
#include "SwissLastNames.h"
#include "SwissPrefixes.h"

namespace faker
{
const NameFormats swissPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames swissPeopleNames{{swissMalesFirstNames, {}, swissLastNames, swissMalesPrefixes, {}},
                                   {swissFemalesFirstNames, {}, swissLastNames, swissFemalesPrefixes, {}},
                                   swissPersonNameFormats};

}
