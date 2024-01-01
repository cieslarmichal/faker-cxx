#pragma once

#include "../../../../common/StringHelper.h"
#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PersianFirstNames.h"
#include "PersianLastNames.h"
#include "PersianPrefixes.h"

namespace faker
{
const NameFormats persianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

// Convert UTF16 to UTF8 for Persian characters then use the data.
const PeopleNames persianPeopleNames{{persianMalesFirstNames, {}, persianLastNames, persianMalesPrefixes, {}},
                                     {persianFemalesFirstNames, {}, persianLastNames, persianFemalesPrefixes, {}},
                                     persianPersonNameFormats};

}