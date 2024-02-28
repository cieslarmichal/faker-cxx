#ifndef FAKER_MODULES_INTERNET_DATA_H
#define FAKER_MODULES_INTERNET_DATA_H

#include <array>
#include <string_view>

namespace faker::internet::data {
extern const std::array<std::string_view, 6> domain_suffixes;
extern const std::array<std::string_view, 4> email_hosts;
extern const std::array<std::string_view, 3> email_example_hosts;
extern const std::array<std::string_view, 156> smiley_emojis;
extern const std::array<std::string_view, 246> body_emojis;
extern const std::array<std::string_view, 1803> person_emojis;
extern const std::array<std::string_view, 140> nature_emojis;
extern const std::array<std::string_view, 129> food_emojis;
extern const std::array<std::string_view, 215> travel_emojis;
extern const std::array<std::string_view, 84> activity_emojis;
extern const std::array<std::string_view, 250> object_emojis;
extern const std::array<std::string_view, 220> symbol_emojis;
extern const std::array<std::string_view, 266> flag_emojis;
extern const std::array<std::string_view, 45> http_media_types;
extern const std::array<std::string_view, 41> http_request_headers;
extern const std::array<std::string_view, 44> http_response_headers;
}

#endif