#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "RussianFirstNames.h"
#include "RussianLastNames.h"
#include "RussianMiddleNames.h"

namespace faker
{
const NameFormats russianPersonNameFormats{{{"{firstName} {lastName}", 1},
                                            {"{lastName} {firstName}", 1},
                                            {"{lastName} {middleName} {firstName}", 1},
                                            {"{lastName} {firstName} {middleName}", 1}}};

const PeopleNames russianPeopleNames{
    {russianMalesFirstNames, russianMalesMiddleNames, russianMalesLastNames, {}, {}},
    {russianFemalesFirstNames, russianFemalesMiddleNames, russianFemalesLastNames, {}, {}},
    russianPersonNameFormats};
}
