#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "AlbanianFirstNames.h"
#include "AlbanianLastNames.h"

namespace faker
{
    const NameFormats albanianPersonNameFormats{{"{firstName} {lastName}", 1}};

    const PeopleNames albanianPeopleNames{{albanianMalesFirstNames, {}, albanianLastNames, {}, {}},
                                     {albanianFemalesFirstNames, {}, albanianLastNames, {}, {}},
                                     albanianPersonNameFormats};
}