#include "music_data.h"
#include <faker/helper.h>
#include <faker/music.h>

namespace faker::music {
std::string artist() { return Helper::arrayElement<std::string>(music::artists); }

std::string genre() { return Helper::arrayElement<std::string>(music::genres); }

std::string songName() { return Helper::arrayElement<std::string>(music::songNames); }
}
