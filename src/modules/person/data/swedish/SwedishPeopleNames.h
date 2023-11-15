#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SwedishFirstNames.h"
#include "SwedishLastNames.h"
#include "SwedishPrefixes.h"

namespace faker
{
const NameFormats swedishPersonNameFormats{{{"{firstName} {lastName}", 10}, {"{prefix} {firstName} {lastName}", 1}}};

const PeopleNames swedishPeopleNames{{swedishMalesFirstNames, {}, swedishLastNames, swedishPrefixes, {}},
                                     {swedishFemalesFirstNames, {}, swedishLastNames, swedishPrefixes, {}},
                                     swedishPersonNameFormats};

}
