#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SlovenianLastNames.h"
#include "SlovenianFirstNames.h"

namespace faker
{
const NameFormats slovenianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames slovenianPeopleNames{{slovenianMalesFirstNames, {}, slovenianLastNames, {}, {}},
                                     {slovenianFemalesFirstNames, {}, slovenianLastNames, {}, {}},
                                     slovenianPersonNameFormats};
}
