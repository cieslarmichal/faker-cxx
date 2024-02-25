#ifndef FAKER_MODULES_VEHICLE_DATA_H
#define FAKER_MODULES_VEHICLE_DATA_H

#include <string>
#include <vector>

namespace faker::vehicle::data {
extern const std::array<std::string_view, 10> bicycle_types;
extern const std::array<std::string_view, 7> vehicle_colors;
extern const std::array<std::string_view, 10> fuel_types;
extern const std::array<std::string_view, 40> manufacturers;
extern const std::array<std::string_view, 14> models;
extern const std::array<std::string_view, 10> vehicle_types;
}

#endif