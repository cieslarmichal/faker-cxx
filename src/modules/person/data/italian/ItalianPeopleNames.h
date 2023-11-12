#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "ItalianFirstNames.h"
#include "ItalianLastNames.h"
#include "ItalianPrefixes.h"

namespace faker
{
const NameFormats italianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames italianPeopleNames{{italianMalesFirstNames, {}, italianLastNames, italianPrefixes, {}},
                                     {italianFemalesFirstNames, {}, italianLastNames, italianPrefixes, {}},
                                     italianPersonNameFormats};

}
