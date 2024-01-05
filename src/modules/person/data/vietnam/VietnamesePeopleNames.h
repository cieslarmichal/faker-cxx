#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "VietnameseFirstNames.h"
#include "VietnameseLastNames.h"

namespace faker
{
const NameFormats vietnamesePersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames vietnamesePeopleNames{{vietnameseMalesFirstNames, {}, vietnameseLastNames, {}, {}},
                                     {vietnameseFemalesFirstNames, {}, vietnameseLastNames, {}, {}},
                                     vietnamesePersonNameFormats};

}
