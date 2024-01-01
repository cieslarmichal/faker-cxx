#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MoldovanFirstNames.h"
#include "MoldovanLastNames.h"

namespace faker
{
const NameFormats moldovanPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames moldovanPeopleNames{{moldovanMalesFirstNames, {}, moldovanLastNames, {}, {}},
                                      {moldovanFemalesFirstNames, {}, moldovanLastNames, {}, {}},
                                      moldovanPersonNameFormats};
}
