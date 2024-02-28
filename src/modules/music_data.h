#ifndef FAKER_MODULES_MUSIC_DATA_H
#define FAKER_MODULES_MUSIC_DATA_H

#include <array>
#include <string_view>

namespace faker::music::data {
extern const std::array<std::string_view, 298> artists;
extern const std::array<std::string_view, 17> genres;
extern const std::array<std::string_view, 971> song_names;
}

#endif