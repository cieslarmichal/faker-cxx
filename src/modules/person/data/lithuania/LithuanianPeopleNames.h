#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "LithuanianFirstNames.h"
#include "LithuanianLastNames.h"

namespace faker
{
const NameFormats lithuanianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames lithuanianPeopleNames{{lithuanianMalesFirstNames, {}, lithuanianLastNames, {}, {}},
                                        {lithuanianFemalesFirstNames, {}, lithuanianLastNames, {}, {}},
                                        lithuanianPersonNameFormats};
}
