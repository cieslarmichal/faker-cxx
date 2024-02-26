#include "string_helper.h"
#include <algorithm>
#include <cctype>

namespace faker {

bool StringHelper::compareNoCase(const std::string& str1, const std::string_view& str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }

    return std::equal(str1.begin(), str1.end(), str2.begin(),
        [](char a, char b) { return std::tolower(a) == std::tolower(b); });
}

std::vector<std::string> StringHelper::split(const std::string& data, const std::string& separator)
{
    size_t positionStart = 0;
    size_t positionEnd;
    size_t separatorLength = separator.length();

    std::string token;
    std::vector<std::string> result;

    while ((positionEnd = data.find(separator, positionStart)) != std::string::npos) {
        token = data.substr(positionStart, positionEnd - positionStart);
        positionStart = positionEnd + separatorLength;
        result.push_back(token);
    }

    result.push_back(data.substr(positionStart));

    return result;
}

std::string StringHelper::join(const std::vector<std::string>& data, const std::string& separator)
{
    switch (data.size()) {
    case 0:
        return "";
    case 1:
        return data[0];
    default: {
        std::string result { data[0] };
        for (auto it = data.begin() + 1; it != data.end(); ++it) {
            result += separator;
            result += *it;
        }
        return result;
    }
    }
}

std::string StringHelper::repeat(const std::string& data, int repetition)
{
    std::string result;
    result.reserve(data.size() * repetition);

    for (int i = 0; i < repetition; ++i) {
        result += data;
    }

    return result;
}

std::string StringHelper::toLower(const std::string& data)
{
    std::string lowerData { data };

    std::transform(lowerData.begin(), lowerData.end(), lowerData.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return lowerData;
}

bool StringHelper::isPunctuation(char c)
{
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':');
}

std::string StringHelper::removePunctuation(const std::string& word)
{
    std::string result { word };

    result.erase(std::remove_if(result.begin(), result.end(), isPunctuation), result.end());

    return result;
}
}
