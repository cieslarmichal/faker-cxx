#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PersianFirstNames.h"
#include "PersianLastNames.h"
#include "PersianPrefixes.h"
#include "../../../../common/StringHelper.h"

namespace faker
{
const NameFormats persianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

//Convert UTF16 to UTF8 for Persian characters then use the data.
const PeopleNames persianPeopleNames{{faker::StringHelper::convertToUTF8(persianMalesFirstNames),
                                      {},
                                      faker::StringHelper::convertToUTF8(persianLastNames),
                                      faker::StringHelper::convertToUTF8(persianMalesPrefixes),
                                      {}},
                                     {faker::StringHelper::convertToUTF8(persianFemalesFirstNames),
                                      {},
                                      faker::StringHelper::convertToUTF8(persianLastNames),
                                      faker::StringHelper::convertToUTF8(persianFemalesPrefixes),
                                      {}},
                                     persianPersonNameFormats};

}