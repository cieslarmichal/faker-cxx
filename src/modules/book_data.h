#ifndef FAKER_MODULES_BOOK_DATA_H
#define FAKER_MODULES_BOOK_DATA_H

#include <array>
#include <string_view>

namespace faker::book::data {
extern const std::array<std::string_view, 100> authors;
extern const std::array<std::string_view, 3> book_formats;
extern const std::array<std::string_view, 25> genres;
extern const std::array<std::string_view, 263> publishers;
extern const std::array<std::string_view, 19> book_series;
extern const std::array<std::string_view, 100> titles;
extern const std::array<std::string_view, 15> translators;
}

#endif