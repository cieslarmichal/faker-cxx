#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SyrianPeopleFirstNames.h"
#include "SyrianPeopleLastNames.h"

namespace faker
{
const NameFormats syrianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames syrianPeopleNames{{syrianMalesFirstNames, {}, syrianLastNames, {}, {}},
                                    {syrianFemalesFirstNames, {}, syrianLastNames, {}, {}},
                                    syrianPersonNameFormats};
}