#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "CanadianFirstNames.h"
#include "CanadianLastNames.h"

namespace faker
{
const NameFormats canadianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames canadianPeopleNames{{canadianMalesFirstNames, {}, canadianLastNames, {}, {}},
                                     {canadianFemalesFirstNames, {}, canadianLastNames, {}, {}},
                                     canadianPersonNameFormats};

}
