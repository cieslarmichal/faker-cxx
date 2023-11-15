#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "TurkishFirstNames.h"
#include "TurkishLastNames.h"
#include "TurkishPrefixes.h"

namespace faker
{
const NameFormats turkishPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 8}}};

const PeopleNames turkishPeopleNames{{turkishMalesFirstNames, {}, turkishLastNames, turkishMalesPrefixes, {}},
                                     {turkishFemalesFirstNames, {}, turkishLastNames, turkishFemalesPrefixes, {}},
                                     turkishPersonNameFormats};

}
