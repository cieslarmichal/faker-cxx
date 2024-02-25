#ifndef FAKER_MODULES_MUSIC_DATA_H
#define FAKER_MODULES_MUSIC_DATA_H

#include <string_view>
#include <vector>

namespace faker::music::data {
extern const std::vector<std::string_view> artists;
extern const std::vector<std::string_view> genres;
extern const std::vector<std::string_view> songNames;
}

#endif