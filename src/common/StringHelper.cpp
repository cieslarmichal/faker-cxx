#include "StringHelper.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>

namespace faker
{
std::vector<std::string> StringHelper::split(const std::string& data, const std::string& separator)
{
    size_t positionStart = 0;
    size_t positionEnd;
    size_t separatorLength = separator.length();

    std::string token;
    std::vector<std::string> result;

    while ((positionEnd = data.find(separator, positionStart)) != std::string::npos)
    {
        token = data.substr(positionStart, positionEnd - positionStart);
        positionStart = positionEnd + separatorLength;
        result.push_back(token);
    }

    result.push_back(data.substr(positionStart));

    return result;
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

std::string StringHelper::repeat(const std::string& data, int repetition)
{
    std::string result;
    for (int i = 0; i < repetition; ++i)
    {
        result += data;
    }
    return result;
}

std::string StringHelper::toLower(const std::string& data)
{
    std::string lowerData{data};

    std::transform(lowerData.begin(), lowerData.end(), lowerData.begin(), [](unsigned char c) { return std::tolower(c); });

    return lowerData;
}
}
