#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "GreekFirstNames.h"
#include "GreekLastNames.h"

namespace faker
{
const NameFormats greekPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames greekPeopleNames{{greekMalesFirstNames, {}, greekLastNames, {}, {}},
                                   {greekFemalesFirstNames, {}, greekLastNames, {}, {}},
                                   greekPersonNameFormats};
}
