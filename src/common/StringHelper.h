#pragma once

#include <string>
#include <vector>

namespace faker
{
class StringHelper
{
public:
    static std::vector<std::string> split(const std::string& data, const std::string& separator = " ");
    static std::string join(const std::vector<std::string>& data, const std::string& separator = " ");
    static std::string repeat(const std::string& data, int repetition);
};
}
