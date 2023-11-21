#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SerbianFirstNames.h"
#include "SerbianLastNames.h"

namespace faker
{
const NameFormats serbianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames serbianPeopleNames{{serbianMalesFirstNames, {}, serbianLastNames, {}, {}},
                                     {serbianFemalesFirstNames, {}, serbianLastNames, {}, {}},
                                     serbianPersonNameFormats};

}
