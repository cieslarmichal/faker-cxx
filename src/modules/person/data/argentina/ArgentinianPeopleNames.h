#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "ArgentinianFirstNames.h"
#include "ArgentinianLastNames.h"

namespace faker
{
const NameFormats argentinianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames argentinianPeopleNames{{argentinianMalesFirstNames, {}, argentinianLastNames, {}, {}},
                                         {argentinianFemalesFirstNames, {}, argentinianLastNames, {}, {}},
                                         argentinianPersonNameFormats};

}
