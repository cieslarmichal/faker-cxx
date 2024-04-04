#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MaldiviansFirstNames.h"
#include "MaldiviansLastNames.h"
#include "MaldiviansPrefixes.h"

namespace faker
{
const NameFormats maldiviansPersonNameFormats{{"{firstName} {lastName}", 1}};

const PeopleNames maldiviansPeopleNames{
    {maldiviansMalesFirstNames, {}, maldiviansMalesLastNames, maldiviansMalesPrefixes, {}},
    {maldiviansFemalesFirstNames, {}, maldiviansFemalesLastNames, maldiviansFemalesPrefixes, {}},
    maldiviansPersonNameFormats};
}
