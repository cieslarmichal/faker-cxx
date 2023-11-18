#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "GreekLastNames.h"
#include "GreekFirstNames.h"

namespace faker
{
const NameFormats greekPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames greekPeopleNames{{greekMalesFirstNames, {}, greekLastNames, {}, {}},
                                     {greekFemalesFirstNames, {}, greekLastNames, {}, {}},
                                     greekPersonNameFormats};
}
