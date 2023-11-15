#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "FinnishFirstNames.h"
#include "FinnishLastNames.h"

namespace faker
{
const NameFormats finnishPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames finnishPeopleNames{{finnishMalesFirstNames, {}, finnishLastNames, {}, {}},
                                     {finnishFemalesFirstNames, {}, finnishLastNames, {}, {}},
                                     finnishPersonNameFormats};
}
