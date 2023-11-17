#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PortugueseFirstNames.h"
#include "PortugueseLastNames.h"
#include "PortuguesePrefixes.h"

namespace faker
{
const NameFormats portuguesePersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames portuguesePeopleNames{
    {portugueseMalesFirstNames, {}, portugueseLastNames, portugueseMalesPrefixes, {}},
    {portugueseFemalesFirstNames, {}, portugueseLastNames, portugueseFemalesPrefixes, {}},
    portuguesePersonNameFormats};

}
