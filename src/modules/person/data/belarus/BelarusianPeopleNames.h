#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BelarusianFirstNames.h"
#include "BelarusianLastNames.h"

namespace faker
{
const NameFormats belarusianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames belarusianPeopleNames{{belarusianMalesFirstNames, {}, belarusianMalesLastNames, {}, {}},
                                        {belarusianFemalesFirstNames, {}, belarusianFemalesLastNames, {}, {}},
                                        belarusianPersonNameFormats};

}
