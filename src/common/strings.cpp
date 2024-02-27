#include "strings.h"
#include <algorithm>
#include <cctype>
#include <charconv>
#include <cstdlib>
#include <stdexcept>

namespace faker::utils {

const std::string_view hex_digits { "0123456789abcdef" };

std::vector<std::string> split(const std::string& data, std::string_view sep)
{
    std::vector<std::string> result;
    size_t start_pos = 0;
    size_t pos_end;

    while ((pos_end = data.find(sep, start_pos)) != std::string::npos) {
        result.push_back(data.substr(start_pos, pos_end - start_pos));
        start_pos = pos_end + sep.size();
    }

    result.push_back(data.substr(start_pos));

    return result;
}

std::vector<std::string_view> split(std::string_view data, std::string_view sep)
{
    std::vector<std::string_view> result;
    size_t start_pos = 0;
    size_t pos_end;

    while ((pos_end = data.find(sep, start_pos)) != std::string::npos) {
        result.push_back(data.substr(start_pos, pos_end - start_pos));
        start_pos = pos_end + sep.size();
    }

    result.push_back(data.substr(start_pos));

    return result;
}

std::string join(const std::vector<std::string>& data, std::string_view sep)
{
    switch (data.size()) {
    case 0:
        return "";
    case 1:
        return data[0];
    default: {
        std::string result { data[0] };
        for (auto it = data.begin() + 1; it != data.end(); ++it) {
            result += sep;
            result += *it;
        }
        return result;
    }
    }
}

std::string repeat(const std::string& data, int repetition)
{
    std::string result;
    result.reserve(data.size() * repetition);

    for (int i = 0; i < repetition; ++i) {
        result += data;
    }

    return result;
}

std::string to_lower(const std::string& data)
{
    std::string lowerData { data };

    std::transform(lowerData.begin(), lowerData.end(), lowerData.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return lowerData;
}

bool is_punctuation(char c)
{
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':');
}

std::string remove_punctuation(std::string_view word)
{
    std::string result { word };

    result.erase(std::remove_if(result.begin(), result.end(), is_punctuation), result.end());

    return result;
}

int to_int(std::string_view str)
{
    int result = 0;
    auto status = std::from_chars(str.data(), str.data() + str.size(), result);
    if (status.ec != std::errc()) {
        throw std::invalid_argument("Invalid number");
    }
    return result;
}

}
