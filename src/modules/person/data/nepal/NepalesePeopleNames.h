#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "NepaleseFirstNames.h"
#include "NepaleseLastNames.h"

namespace faker
{
const NameFormats nepalesePersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames nepalesePeopleNames{{nepaleseMalesFirstNames, {}, nepaleseLastNames, {}, {}},
                                      {nepaleseFemalesFirstNames, {}, nepaleseLastNames, {}, {}},
                                      nepalesePersonNameFormats};
}
