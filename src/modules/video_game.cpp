#include "video_game_data.h"
#include <faker/helper.h>
#include <faker/video_game.h>

namespace faker::video_game {
std::string gameTitle() { return Helper::arrayElement<std::string>(videoGameNames); }

std::string genre() { return Helper::arrayElement<std::string>(genres); }

std::string platform() { return Helper::arrayElement<std::string>(platforms); }

std::string studioName() { return Helper::arrayElement<std::string>(studioNames); }
}
