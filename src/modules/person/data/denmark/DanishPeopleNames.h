#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "DanishFirstNames.h"
#include "DanishLastNames.h"
#include "DanishMiddleNames.h"
#include "DanishPrefixes.h"

namespace faker
{
const NameFormats danishPersonNameFormats{{{"{firstName} {lastName}", 1}, {"{firstName} {middleName} {lastName}", 1}}};

const PeopleNames danishPeopleNames{
    {danishMalesFirstNames, danishMiddleNames, danishLastNames, danishMalesPrefixes, {}},
    {danishFemalesFirstNames, danishMiddleNames, danishLastNames, danishFemalesPrefixes, {}},
    danishPersonNameFormats};

}
