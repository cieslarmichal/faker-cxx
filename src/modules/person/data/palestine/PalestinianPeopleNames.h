#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PalestinianFirstNames.h"
#include "PalestinianLastNames.h"

namespace faker
{
const NameFormats palestinianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames palestinianPeopleNames{{palestinianMalesFirstNames, {}, palestinianLastNames, {}, {}},
                                         {palestinianFemalesFirstNames, {}, palestinianLastNames, {}, {}},
                                         palestinianPersonNameFormats};
}
