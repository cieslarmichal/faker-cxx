#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MonacanFirstNames.h"
#include "MonacanLastNames.h"

namespace faker
{
const NameFormats monacanPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames monacanPeopleNames{{monacanMalesFirstNames, {}, monacanLastNames, {}, {}},
                                     {monacanFemalesFirstNames, {}, monacanLastNames, {}, {}},
                                     monacanPersonNameFormats};
}
