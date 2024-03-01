#include "string_data.h"

namespace faker::string::data {
const std::string_view ascii_upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string_view ascii_lower_letters = "abcdefghijklmnopqrstuvwxyz";
const std::string_view non_zero_digits = "123456789";
const std::string_view digits = "0123456789";
const std::string_view ascii_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const std::string_view ascii_lower_alphanum = "abcdefghijklmnopqrstuvwxyz0123456789";
const std::string_view ascii_upper_alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const std::string_view ascii_alphanum
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
const std::string_view hex_upper_digits = "0123456789ABCDEF";
const std::string_view hex_lower_digits = "0123456789abcdef";
const std::string_view symbols = "~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/";

const std::string_view all_allowed_chars
    = R"(!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|})";
}
