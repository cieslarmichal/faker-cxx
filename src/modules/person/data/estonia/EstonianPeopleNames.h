#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "EstonianFirstNames.h"
#include "EstonianLastNames.h"

namespace faker
{
const NameFormats estonianPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames estonianPeopleNames{{estonianMalesFirstNames, {}, estonianLastNames, {}, {}},
                                      {estonianFemalesFirstNames, {}, estonianLastNames, {}, {}},
                                      estonianPersonNameFormats};

}
