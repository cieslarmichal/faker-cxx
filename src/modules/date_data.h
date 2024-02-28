#ifndef FAKER_MODULES_DATE_DATA_H
#define FAKER_MODULES_DATE_DATA_H

#include <array>
#include <string_view>

namespace faker::date::data {
extern const std::array<std::string_view, 12> month_names;
extern const std::array<std::string_view, 12> month_abbr_names;
extern const std::array<std::string_view, 7> weekday_names;
extern const std::array<std::string_view, 7> weekday_abbr_names;
}

#endif