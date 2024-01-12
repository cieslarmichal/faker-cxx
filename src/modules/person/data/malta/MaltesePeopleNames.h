#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MalteseFirstNames.h"
#include "MalteseLastNames.h"

namespace faker
{
const NameFormats maltesePersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames maltesePeopleNames{{malteseMalesFirstNames, {}, malteseLastNames, {}, {}},
                                      {malteseFemalesFirstNames, {}, malteseLastNames, {}, {}},
                                      maltesePersonNameFormats};
}
