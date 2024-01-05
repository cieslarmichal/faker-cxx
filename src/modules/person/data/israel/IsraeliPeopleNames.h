#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "IsraelisFirstNames.h"
#include "IsraelisLastNames.h"

namespace faker
{

const NameFormats israelisPersonNameFormats{{"{lastName} {firstName}", 1}};

const PeopleNames israeliPeopleNames{ {israelisMalesFirstNames, {}, israelisLastNames, {}, {}},
                                       {israelisFemalesFirstNames, {}, israelisLastNames, {}, {}},
                                       israelisPersonNameFormats};
}
