#ifndef FAKER_MODULES_PHONE_DATA_H
#define FAKER_MODULES_PHONE_DATA_H

#include <array>
#include <faker/phone.h>
#include <string_view>
#include <utility>

namespace faker::phone::data {
extern const std::array<std::string_view, 6> platforms;
extern const std::array<std::string_view, 15> model_names;
extern const std::array<std::string_view, 9> manufacturers;
extern const std::array<std::pair<phone_number_format_t, std::string_view>, 230> number_formats;
}

#endif