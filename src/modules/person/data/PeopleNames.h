#pragma once

#include "PersonNames.h"

namespace faker
{
struct PeopleNames
{
    PersonNames malesNames;
    PersonNames femalesNames;
    NameFormats nameFormats;
};

inline bool operator==(const PeopleNames& lhs, const PeopleNames& rhs)
{
    return lhs.malesNames == rhs.malesNames && lhs.femalesNames == rhs.femalesNames;
}
}
