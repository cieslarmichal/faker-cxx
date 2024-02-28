#ifndef FAKER_MODULES_COMPUTER_DATA_H
#define FAKER_MODULES_COMPUTER_DATA_H

#include <array>
#include <string_view>

namespace faker::computer::data {
extern const std::array<std::string_view, 4> types;
extern const std::array<std::string_view, 20> manufacturers;
extern const std::array<std::string_view, 45> models;
extern const std::array<std::string_view, 5> cpu_manufacturers;
extern const std::array<std::string_view, 12> cpu_types;
extern const std::array<std::string_view, 26> cpu_models;
extern const std::array<std::string_view, 5> gpu_manufacturers;
extern const std::array<std::string_view, 2> gpu_types;
extern const std::array<std::string_view, 23> gpu_models;
}

#endif