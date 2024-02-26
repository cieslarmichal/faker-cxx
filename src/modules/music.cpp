#include "../common/helper.h"
#include "music_data.h"
#include <faker/music.h>

namespace faker::music {
std::string_view artist() { return Helper::arrayElement(data::artists); }

std::string_view genre() { return Helper::arrayElement(data::genres); }

std::string_view songName() { return Helper::arrayElement(data::songNames); }
}
