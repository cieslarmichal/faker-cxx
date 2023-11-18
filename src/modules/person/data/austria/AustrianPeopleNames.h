#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "AustrianFirstNames.h"
#include "AustrianLastNames.h"
#include "AustrianPrefixes.h"

namespace faker
{
const NameFormats austrianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 5}}};

const PeopleNames austrianPeopleNames{{austrianMalesFirstNames, {}, austrianLastNames, austrianMalesPrefixes, {}},
                                      {austrianFemalesFirstNames, {}, austrianLastNames, austrianFemalesPrefixes, {}},
                                      austrianPersonNameFormats};

}
