#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "BulgarianFirstNames.h"
#include "BulgarianLastNames.h"

namespace faker
{
const NameFormats bulgarianPersonNameFormats{
    {{"{firstName} {lastName}", 10}}};

const PeopleNames bulgarianPeopleNames{
    {bulgarianMalesFirstNames, {}, bulgarianLastNames, {}, {}},
    {bulgarianFemalesFirstNames, {}, bulgarianLastNames, {}, {}},
    bulgarianPersonNameFormats};

}

