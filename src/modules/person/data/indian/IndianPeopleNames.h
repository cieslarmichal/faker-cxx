#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "IndianFirstNames.h"
#include "IndianLastNames.h"

namespace faker
{
const NameFormats indianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames indianPeopleNames{{indianMalesFirstNames, {}, indianLastNames, {}, {}},
                                    {indianFemalesFirstNames, {}, indianLastNames, {}, {}},
                                    indianPersonNameFormats};

}
