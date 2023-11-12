#pragma once

#include <string>
#include <vector>

namespace faker
{
struct PersonNames
{
    std::vector<std::string> firstNames;
    std::vector<std::string> middleNames;
    std::vector<std::string> lastNames;
    std::vector<std::string> prefixes;
    std::vector<std::string> suffixes;
};

inline bool operator==(const PersonNames& lhs, const PersonNames& rhs)
{
    return lhs.prefixes == rhs.prefixes && lhs.firstNames == rhs.firstNames && lhs.middleNames == rhs.middleNames &&
           lhs.lastNames == rhs.lastNames && lhs.suffixes == rhs.suffixes;
}
}
