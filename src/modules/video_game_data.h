#ifndef FAKER_MODULES_VIDEO_GAME_DATA_H
#define FAKER_MODULES_VIDEO_GAME_DATA_H

#include <string_view>
#include <vector>

namespace faker::video_game::data {
extern const std::vector<std::string_view> videoGameNames;
extern const std::vector<std::string_view> genres;
extern const std::vector<std::string_view> platforms;
extern const std::vector<std::string_view> studioNames;
}

#endif