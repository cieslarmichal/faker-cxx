#ifndef FAKER_MODULES_WEATHER_DATA_H
#define FAKER_MODULES_WEATHER_DATA_H

#include <array>
#include <string_view>

namespace faker::weather::data {
extern const std::array<std::string_view, 16> weather_descriptions;
}

#endif