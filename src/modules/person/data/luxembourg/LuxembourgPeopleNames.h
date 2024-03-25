#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "LuxembourgFirstNames.h"
#include "LuxembourgLastNames.h"

namespace faker
{
const NameFormats luxembourgPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames luxembourgPeopleNames{{luxembourgMalesFirstNames, {}, luxembourgLastNames, {}, {}},
                                        {luxembourgFemalesFirstNames, {}, luxembourgLastNames, {}, {}},
                                        luxembourgPersonNameFormats};
}
