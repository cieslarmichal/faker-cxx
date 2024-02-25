#ifndef FAKER_MODULES_BOOK_DATA_H
#define FAKER_MODULES_BOOK_DATA_H

#include <array>
#include <string_view>

namespace faker::books {
extern const std::array<std::string_view, 100> authors;
extern const std::array<std::string_view, 3> bookFormats;
extern const std::array<std::string_view, 25> genres;
extern const std::array<std::string_view, 263> publishers;
extern const std::array<std::string_view, 19> bookSeries;
extern const std::array<std::string_view, 100> titles;
extern const std::array<std::string_view, 15> translators;
}

#endif