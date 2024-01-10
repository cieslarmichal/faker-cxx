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
}
