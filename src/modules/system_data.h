#ifndef FAKER_MODULES_SYSTEM_DATA_H
#define FAKER_MODULES_SYSTEM_DATA_H

#include <string_view>
#include <unordered_map>
#include <vector>

namespace faker::system::data {
extern const std::vector<std::string_view> commonInterfaceTypes;
extern const std::unordered_map<std::string_view, std::string_view> commonInterfaceSchemas;
extern const std::vector<std::string_view> cronDayOfWeek;
extern const std::vector<std::string_view> directoryPaths;
extern const std::vector<std::string_view> mimeTypes;
extern const std::unordered_map<std::string_view, std::string_view> mimeTypesExtensions;
extern const std::vector<std::string_view> commonMimeTypes;
extern const std::vector<std::string_view> commonFileTypes;
}

#endif