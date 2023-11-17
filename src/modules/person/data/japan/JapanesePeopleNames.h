#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "JapaneseFirstNames.h"
#include "JapaneseLastNames.h"

namespace faker
{
const NameFormats japanesePeopleNameFormats{{"{lastName} {firstName}", 1}};
const PeopleNames japanesePeopleNames{{japaneseMaleFirstNames, {}, japaneseLastNames, {}, {}},
                                      {japaneseFemaleFirstNames, {}, japaneseLastNames, {}, {}},
                                      japanesePeopleNameFormats};
}
