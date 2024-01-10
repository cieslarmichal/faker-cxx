#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "LebanesePeopleFirstNames.h"
#include "LebanesePeopleLastNames.h"

namespace faker
{
const NameFormats lebanesePersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames lebanesePeopleNames{{lebaneseMalesFirstNames, {}, lebaneseLastNames, {}, {}},
                                      {lebaneseFemalesFirstNames, {}, lebaneseLastNames, {}, {}},
                                      lebanesePersonNameFormats};
}