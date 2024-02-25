#ifndef FAKER_MODULES_VIDEO_GAME_DATA_H
#define FAKER_MODULES_VIDEO_GAME_DATA_H

#include <array>
#include <string_view>

namespace faker::video_game::data {
extern const std::array<std::string_view, 3152> videoGameNames;
extern const std::array<std::string_view, 28> genres;
extern const std::array<std::string_view, 9> platforms;
extern const std::array<std::string_view, 392> studioNames;
}

#endif