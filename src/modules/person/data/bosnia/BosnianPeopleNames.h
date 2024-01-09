#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BosnianFirstNames.h"
#include "BosnianLastNames.h"

namespace faker
{

const NameFormats bosnianPersonNameFormats{{"{lastName} {firstName}", 1}};

const PeopleNames bosnianPeopleNames{{bosnianMalesFirstNames, {}, bosnianLastNames, {}, {}},
                                     {bosnianFemalesFirstNames, {}, bosnianLastNames, {}, {}},
                                     bosnianPersonNameFormats};
}
