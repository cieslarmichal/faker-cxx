#pragma once

#include <string>
#include <vector>

namespace faker
{
struct NameFormat
{
    std::string format;
    unsigned weight;
};

using NameFormats = std::vector<NameFormat>;
}
