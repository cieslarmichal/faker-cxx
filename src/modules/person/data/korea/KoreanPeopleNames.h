#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "KoreanFirstNames.h"
#include "KoreanLastNames.h"

namespace faker
{
const NameFormats koreanPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames koreanPeopleNames{{koreanFirstNames, {}, koreanLastNames, {}, {}},
                                    {koreanFirstNames, {}, koreanLastNames, {}, {}},
                                    koreanPersonNameFormats};

}
