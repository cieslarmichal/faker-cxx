#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "LiechtensteinerPeopleFirstNames.h"
#include "LiechtensteinerPeopleLastNames.h"

namespace faker
{
const NameFormats liechtensteinerPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames liechtensteinerPeopleNames{{liechtensteinerMalesFirstNames, {}, liechtensteinerLastNames, {}, {}},
                                      {liechtensteinerFemalesFirstNames, {}, liechtensteinerLastNames, {}, {}},
                                      liechtensteinerPersonNameFormats};
}