#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "IrishFirstNames.h"
#include "IrishLastNames.h"
#include "IrishPrefixes.h"
#include "IrishSuffixes.h"

namespace faker
{
// TODO: add handling lastName-lastName

const NameFormats irishPersonNameFormats{{{"{firstName} {lastName}", 49},
                                          {"{prefix} {firstName} {lastName}", 7},
                                          {"{firstName} {lastName} {suffix}", 7},
                                          {"{prefix} {firstName} {lastName} {suffix}", 1}}};

const PeopleNames irishPeopleNames{{irishMalesFirstNames, {}, irishLastNames, irishMalesPrefixes, irishSuffixes},
                                   {irishFemalesFirstNames, {}, irishLastNames, irishFemalesPrefixes, irishSuffixes},
                                   irishPersonNameFormats};
}
