#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "MexicanFirstNames.h"
#include "MexicanLastNames.h"
#include "MexicanPrefixes.h"
#include "MexicanSuffixes.h"

namespace faker
{
const NameFormats mexicanPersonNameFormats{
    {{"{firstName} {lastName}", 8}, {"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName} {suffix}", 1}}};

const PeopleNames mexicanPeopleNames{
    {mexicanMalesFirstNames, {}, mexicanLastNames, mexicanMalesPrefixes, mexicanSuffixes},
    {mexicanFemalesFirstNames, {}, mexicanLastNames, mexicanFemalesPrefixes, mexicanSuffixes},
    mexicanPersonNameFormats};

}
