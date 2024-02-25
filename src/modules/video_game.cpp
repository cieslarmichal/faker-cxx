#include "video_game_data.h"
#include <faker/helper.h>
#include <faker/video_game.h>

namespace faker::video_game {
std::string_view gameTitle() { return Helper::arrayElement(data::videoGameNames); }

std::string_view genre() { return Helper::arrayElement(data::genres); }

std::string_view platform() { return Helper::arrayElement(data::platforms); }

std::string_view studioName() { return Helper::arrayElement(data::studioNames); }
}
