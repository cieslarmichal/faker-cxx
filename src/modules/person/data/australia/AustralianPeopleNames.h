#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "AustralianFirstNames.h"
#include "AustralianLastNames.h"

namespace faker
{
const NameFormats australianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames australianPeopleNames{{australianMalesFirstNames, {}, australianLastNames, {}, {}},
                                        {australianFemalesFirstNames, {}, australianLastNames, {}, {}},
                                        australianPersonNameFormats};

}
