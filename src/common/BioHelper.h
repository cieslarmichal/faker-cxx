#pragma once

#include <functional>
#include <map>
#include <regex>
#include <string>
#include <vector>

namespace faker
{
class BioHelper
{
public:
    static bool checkTokenFormat(const std::string& bio);
};
}
