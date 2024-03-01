#ifndef FAKER_MODULES_STRING_DATA_H
#define FAKER_MODULES_STRING_DATA_H

#include <string_view>

namespace faker::string::data {
extern const std::string_view ascii_upper_letters;
extern const std::string_view ascii_lower_letters;
extern const std::string_view non_zero_digits;
extern const std::string_view digits;
extern const std::string_view ascii_letters;
extern const std::string_view ascii_lower_alphanum;
extern const std::string_view ascii_upper_alphanum;
extern const std::string_view ascii_alphanum;
extern const std::string_view hex_upper_digits;
extern const std::string_view hex_lower_digits;
extern const std::string_view symbols;
extern const std::string_view all_allowed_chars;
}

#endif