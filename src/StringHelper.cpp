#include "StringHelper.h"

#include <regex>

namespace faker
{
std::vector<std::string> StringHelper::split(const std::string& data, const std::string& separator)
{
    std::regex splitRegex(separator);

    return {std::sregex_token_iterator(data.begin(), data.end(), splitRegex, -1), std::sregex_token_iterator()};
}

std::string StringHelper::join(const std::vector<std::string>& data, const std::string& separator)
{
    std::ostringstream result;

    for (size_t i = 0; i < (data.size() - 1); ++i)
    {
        result << data[i] << separator;
    }

    if (!data.empty()) [[likely]]
    {
        result << data[data.size() - 1];
    }

    return result.str();
}
}
