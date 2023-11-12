#pragma once

#include "PersonNames.h"

namespace faker
{
struct PeopleNames
{
    PersonNames malesNames;
    PersonNames femalesNames;
};

inline bool operator==(const PeopleNames& lhs, const PeopleNames& rhs)
{
    return lhs.malesNames == rhs.malesNames && lhs.femalesNames == rhs.femalesNames;
}
}
