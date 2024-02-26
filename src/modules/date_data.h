#ifndef FAKER_MODULES_DATE_DATA_H
#define FAKER_MODULES_DATE_DATA_H

#include <array>
#include <string_view>

namespace faker::date::data {
extern const std::array<std::string_view, 12> monthNames;
extern const std::array<std::string_view, 12> monthAbbreviatedNames;
extern const std::array<std::string_view, 7> weekdayNames;
extern const std::array<std::string_view, 7> weekdayAbbreviatedNames;
}

#endif