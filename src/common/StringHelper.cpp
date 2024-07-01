#include "StringHelper.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

namespace faker::common
{
std::vector<std::string> split(const std::string& data, const std::string& separator)
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

std::string joinString(const std::vector<std::string>& data, const std::string& separator)
{
    switch (data.size())
    {
    case 0:
        return "";
    case 1:
        return data[0];
    default:
    {
        std::string result{data[0]};

        for (auto it = data.begin() + 1; it != data.end(); ++it)
        {
            result += separator;
            result += *it;
        }

        return result;
    }
    }
}

std::string join(const std::vector<std::string_view>& data, const std::string& separator)
{
    switch (data.size())
    {
    case 0:
        return "";
    case 1:
        return std::string{data[0]};
    default:
    {
        std::string result{data[0]};

        for (auto it = data.begin() + 1; it != data.end(); ++it)
        {
            result += separator;
            result += *it;
        }

        return result;
    }
    }
}

std::string repeat(const std::string& data, int repetition)
{
    std::string result;

    result.reserve(data.size() * static_cast<unsigned long>(repetition));

    for (int i = 0; i < repetition; ++i)
    {
        result += data;
    }

    return result;
}

std::string toLower(const std::string& data)
{
    std::string lowerData{data};

    std::ranges::transform(lowerData, lowerData.begin(), [](unsigned char c) { return std::tolower(c); });

    return lowerData;
}

bool isPunctuation(char c)
{
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':');
}

std::string removePunctuation(const std::string& word)
{
    std::string result{word};

    result.erase(std::remove_if(result.begin(), result.end(), isPunctuation), result.end());

    return result;
}
}
