#pragma once

#include <string>
#include <vector>

#ifdef __clang__
    #include "fmt/format.h"
#else
    #include <format>
#endif

namespace faker
{
class StringHelper
{
public:
    static std::vector<std::string> split(const std::string& data, const std::string& separator = " ");
    static std::string join(const std::vector<std::string>& data, const std::string& separator = " ");
    static std::string repeat(const std::string& data, int repetition);
    static std::string toLower(const std::string& data);
    static bool isPunctuation(char c);
    static std::string removePunctuation(const std::string& word);
};
}
