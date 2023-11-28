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
private:
    const std::regex firstRegex{R"(^[a-zA-Z0-9_]+$)"};
    const std::regex secondRegex{R"((\w+), (\w+))"};
    const std::regex thirdRegex{R"((\w+), (\w+)), (\w+))"};
    const std::regex fourthRegex{R"((\w+) (\w+))"};
    const std::regex fifthRegex{R"((\w+) (\w+), (\w+))"};
    const std::regex sixthRegex{R"((\w+) (\w+), (\w+) (\w+))"};
public:
    static bool checkTokenFormat(const std::string& bio);
};
}
