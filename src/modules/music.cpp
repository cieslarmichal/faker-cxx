#include "../common/random.h"
#include "music_data.h"
#include <faker/music.h>

namespace faker::music {
std::string_view artist() { return random::element(data::artists); }

std::string_view genre() { return random::element(data::genres); }

std::string_view song_name() { return random::element(data::songNames); }
}
