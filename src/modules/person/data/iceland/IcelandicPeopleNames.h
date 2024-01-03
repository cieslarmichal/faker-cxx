#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "IcelandicFirstNames.h"
#include "IcelandicLastNames.h"

namespace faker
{
const NameFormats icelandicPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames icelandicPeopleNames{{icelandicMalesFirstNames, {}, icelandicLastNames, {}, {}},
                                       {icelandicFemalesFirstNames, {}, icelandicLastNames, {}, {}},
                                       icelandicPersonNameFormats};
}
