#include "../common/random.h"
#include "video_game_data.h"
#include <faker/video_game.h>

namespace faker::video_game {
std::string_view title() { return random::element(data::videoGameNames); }

std::string_view genre() { return random::element(data::genres); }

std::string_view platform() { return random::element(data::platforms); }

std::string_view studio_name() { return random::element(data::studioNames); }
}
