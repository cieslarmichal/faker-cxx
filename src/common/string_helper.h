#ifndef FAKER_COMMON_STRING_HELPER_H
#define FAKER_COMMON_STRING_HELPER_H

#include <array>
#include <string>
#include <vector>

namespace faker {
class StringHelper {
public:
    static bool compareNoCase(const std::string& str1, const std::string_view& str2);

    static std::vector<std::string> split(
        const std::string& data, const std::string& separator = " ");
    static std::string join(
        const std::vector<std::string>& data, const std::string& separator = " ");
    static std::string repeat(const std::string& data, int repetition);
    static std::string toLower(const std::string& data);
    static bool isPunctuation(char c);
    static std::string removePunctuation(const std::string& word);

    template <size_t N> static std::string toHex(const std::array<uint8_t, N>& data)
    {
        static std::string_view hexDigits { "0123456789abcdef" };

        std::string result;
        result.reserve(N * 2);

        for (uint8_t byte : data) {
            result.push_back(hexDigits[byte >> 4]);
            result.push_back(hexDigits[byte & 0x0f]);
        }

        return result;
    }
};
}

#endif