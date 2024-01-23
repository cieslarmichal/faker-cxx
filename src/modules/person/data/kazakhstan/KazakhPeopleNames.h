#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "KazakhFirstNames.h"
#include "KazakhLastNames.h"

namespace faker
{
const NameFormats kazakhPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames kazakhPeopleNames{{kazakhMalesFirstNames, {}, kazakhMalesLastNames, {}, {}},
                                    {kazakhFemalesFirstNames, {}, kazakhFemalesLastNames, {}, {}},
                                    kazakhPersonNameFormats};
}
