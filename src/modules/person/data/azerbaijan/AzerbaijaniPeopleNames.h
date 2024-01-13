#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "AzerbaijaniFirstNames.h"
#include "AzerbaijaniLastNames.h"

namespace faker
{
const NameFormats azerbaijaniPersonNameFormats{{
    {"{lastName} {firstName}", 1},
    {"{firstName} {lastName}", 1},
}};

const PeopleNames azerbaijaniPeopleNames{
    {azerbaijaniMalesFirstNames, {}, azerbaijaniMalesLastNames, {}, {}},
    {azerbaijaniFemalesFirstNames, {}, azerbaijaniFemalesLastNames, {}, {}},
    azerbaijaniPersonNameFormats};

}
