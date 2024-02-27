#ifndef FAKER_COMMON_STRING_HELPER_H
#define FAKER_COMMON_STRING_HELPER_H

#include <array>
#include <string>
#include <vector>

namespace faker::utils {
extern const std::string_view hex_digits;

std::vector<std::string_view> split(std::string_view data, std::string_view sep = " ");

std::string join(const std::vector<std::string>& data, std::string_view sep = " ");

std::string repeat(const std::string& data, int repetition);

std::string to_lower(const std::string& data);

bool is_punctuation(char c);
std::string remove_punctuation(std::string_view word);

int to_int(std::string_view str);

template <size_t N> static std::string to_hex(const std::array<uint8_t, N>& data)
{
    std::string result;
    result.reserve(N * 2);

    for (uint8_t byte : data) {
        result.push_back(hex_digits[byte >> 4]);
        result.push_back(hex_digits[byte & 0x0f]);
    }

    return result;
}
}

#endif