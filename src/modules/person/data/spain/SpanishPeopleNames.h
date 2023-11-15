#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "SpanishFirstNames.h"
#include "SpanishLastNames.h"
#include "SpanishPrefixes.h"

namespace faker
{
const NameFormats spanishPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

const PeopleNames spanishPeopleNames{{spanishMalesFirstNames, {}, spanishLastNames, spanishMalesPrefixes, {}},
                                     {spanishFemalesFirstNames, {}, spanishLastNames, spanishFemalesPrefixes, {}},
                                     spanishPersonNameFormats};

}
