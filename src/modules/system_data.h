#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace faker {
extern const std::vector<std::string> commonInterfaceTypes;
extern const std::unordered_map<std::string, std::string> commonInterfaceSchemas;
extern const std::vector<std::string> cronDayOfWeek;
extern const std::vector<std::string> directoryPaths;
extern const std::vector<std::string> mimeTypes;
extern const std::unordered_map<std::string, std::string> mimeTypesExtensions;
extern const std::vector<std::string> commonMimeTypes;
extern const std::vector<std::string> commonFileTypes;
}
