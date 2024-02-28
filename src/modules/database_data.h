#ifndef FAKER_MODULES_DATABASE_DATA_H
#define FAKER_MODULES_DATABASE_DATA_H

#include <array>
#include <string_view>

namespace faker::database::data {
extern const std::array<std::string_view, 7> collations;
extern const std::array<std::string_view, 17> column_names;
extern const std::array<std::string_view, 24> column_types;
extern const std::array<std::string_view, 6> engines;
}

#endif