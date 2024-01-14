#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "GhanaianFirstNames.h"
#include "GhanaianLastNames.h"

namespace faker
{
const NameFormats ghanaianPersonNameFormats{{{"{firstName} {lastName}"}, 1}};

const PeopleNames ghanaianPeopleNames{{ghanaianMalesFirstNames, {}, ghanaianLastNames, {}, {}},
                                    {ghanaianFemalesFirstNames, {}, ghanaianLastNames, {}, {}},
                                    ghanaianPersonNameFormats};

}
