#pragma once

#include "../england/EnglishFirstNames.h"
#include "../england/EnglishLastNames.h"
#include "../england/EnglishPrefixes.h"
#include "../england/EnglishSuffixes.h"
#include "../NameFormats.h"
#include "../PeopleNames.h"

namespace faker
{
const NameFormats usaPersonNameFormats{{{"{firstName} {lastName}", 49},
                                        {"{firstName} {lastName}-{lastName}", 7},
                                        {"{prefix} {firstName} {lastName}", 7},
                                        {"{firstName} {lastName} {suffix}", 7},
                                        {"{prefix} {firstName} {lastName} {suffix}", 1}}};

const PeopleNames usaPeopleNames{
    {englishMalesFirstNames, {}, englishLastNames, englishMalesPrefixes, englishSuffixes},
    {englishFemalesFirstNames, {}, englishLastNames, englishFemalesPrefixes, englishSuffixes},
    usaPersonNameFormats};
}
