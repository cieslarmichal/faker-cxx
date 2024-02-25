#ifndef FAKER_MODULES_WEATHER_DATA_H
#define FAKER_MODULES_WEATHER_DATA_H

#include <string_view>
#include <array>

namespace faker::weather::data {
extern const std::array<std::string_view, 16> weatherDescriptions;
}

#endif