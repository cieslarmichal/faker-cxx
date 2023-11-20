#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "ChineseFirstNames.h"
#include "ChineseLastNames.h"

namespace faker
{
const NameFormats chinesePersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames chinesePeopleNames{{chineseMalesFirstNames, {}, chineseLastNames, {}, {}},
                                     {chineseFemalesFirstNames, {}, chineseLastNames, {}, {}},
                                     chinesePersonNameFormats};

}
