#pragma once

#include "../NameFormats.h"
#include "../PeopleNames.h"
#include "PersianFirstNames.h"
#include "PersianLastNames.h"
#include "PersianPrefixes.h"
<<<<<<< HEAD

=======
#include "../../../../common/StringHelper.h"
>>>>>>> 36de5791406c2238d9c3fae6787ca4e44dc2d55b

namespace faker
{
const NameFormats persianPersonNameFormats{{{"{prefix} {firstName} {lastName}", 1}, {"{firstName} {lastName}", 9}}};

//Convert UTF16 to UTF8 for Persian characters then use the data.
<<<<<<< HEAD
const PeopleNames persianPeopleNames{{persianMalesFirstNames,
                                      {},
                                      persianLastNames,
                                      persianMalesPrefixes,
                                      {}},
                                     {persianFemalesFirstNames,
                                      {},
                                      persianLastNames,
                                      persianFemalesPrefixes,
=======
const PeopleNames persianPeopleNames{{faker::StringHelper::convertToUTF8(persianMalesFirstNames),
                                      {},
                                      faker::StringHelper::convertToUTF8(persianLastNames),
                                      faker::StringHelper::convertToUTF8(persianMalesPrefixes),
                                      {}},
                                     {faker::StringHelper::convertToUTF8(persianFemalesFirstNames),
                                      {},
                                      faker::StringHelper::convertToUTF8(persianLastNames),
                                      faker::StringHelper::convertToUTF8(persianFemalesPrefixes),
>>>>>>> 36de5791406c2238d9c3fae6787ca4e44dc2d55b
                                      {}},
                                     persianPersonNameFormats};

}