#pragma once

#include <array>
#include <unordered_map>

#include "faker-cxx/System.h"

namespace faker
{
extern const std::array<std::string_view, 3> commonInterfaceTypes;
extern const std::unordered_map<std::string_view, std::string_view> commonInterfaceSchemas;
extern const std::array<std::string_view, 7> cronDayOfWeek;
extern const std::array<std::string_view, 50> directoryPaths;
extern const std::array<std::string_view, 64> mimeTypes;
extern const std::unordered_map<std::string_view, std::string_view> mimeTypesExtensions;
extern const std::array<std::string_view, 9> commonMimeTypes;
extern const std::array<std::string_view, 5> commonFileTypes;
}
