#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "UkrainianFirstNames.h"
#include "UkrainianLastNames.h"
#include "UkrainianMiddleNames.h"
#include "UkrainianPrefixes.h"

namespace faker
{
const NameFormats ukrainianPersonNameFormats{{
    {"{firstName} {lastName}", 1},
    {"{lastName} {firstName}", 1},
    {"{firstName} {middleName} {lastName}", 1},
    {"{lastName} {middleName} {firstName}", 1},
}};

const PeopleNames ukrainianPeopleNames{
    {ukrainianMalesFirstNames, ukrainianMalesMiddleNames, ukrainianMalesLastNames, ukrainianMalesPrefixes, {}},
    {ukrainianFemalesFirstNames, ukrainianFemalesMiddleNames, ukrainianFemalesLastNames, ukrainianFemalesPrefixes, {}},
    ukrainianPersonNameFormats};

}
