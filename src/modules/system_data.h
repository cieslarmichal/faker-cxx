#ifndef FAKER_MODULES_SYSTEM_DATA_H
#define FAKER_MODULES_SYSTEM_DATA_H

#include <array>
#include <string_view>
#include <unordered_map>

namespace faker::system::data {
extern const std::array<std::string_view, 3> common_interface_types;
extern const std::unordered_map<std::string_view, std::string_view> common_interface_schemas;
extern const std::array<std::string_view, 7> non_standard_cron_expressions;
extern const std::array<std::string_view, 7> cron_day_of_week;
extern const std::array<std::string_view, 50> directory_paths;
extern const std::array<std::string_view, 64> mime_types;
extern const std::unordered_map<std::string_view, std::string_view> mime_types_extensions;
extern const std::array<std::string_view, 9> common_mime_types;
extern const std::array<std::string_view, 5> common_file_types;
}

#endif