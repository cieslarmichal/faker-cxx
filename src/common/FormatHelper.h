#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace faker
{
class FormatHelper
{
public:
    static std::string fillTokenValues(const std::string& format,
                                       std::map<std::string, std::function<std::string()>> tokenValueGenerators);
};
}
