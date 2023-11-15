#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "EnglishFirstNames.h"
#include "EnglishLastNames.h"
#include "EnglishPrefixes.h"
#include "EnglishSuffixes.h"

namespace faker
{
const NameFormats englishPersonNameFormats{{{"{firstName} {lastName}", 49},
                                            {"{prefix} {firstName} {lastName}", 7},
                                            {"{firstName} {lastName} {suffix}", 7},
                                            {"{prefix} {firstName} {lastName} {suffix}", 1}}};

const PeopleNames englishPeopleNames{
    {englishMalesFirstNames, {}, englishLastNames, englishMalesPrefixes, englishSuffixes},
    {englishFemalesFirstNames, {}, englishLastNames, englishFemalesPrefixes, englishSuffixes},
    englishPersonNameFormats};
}
