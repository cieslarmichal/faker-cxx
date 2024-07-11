#include "faker-cxx/music.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "music_data.h"

namespace faker::music
{
std::string_view artist()
{
    return helper::arrayElement(artists);
}

std::string_view genre()
{
    return helper::arrayElement(musicGenres);
}

std::string_view songName()
{
    return helper::arrayElement(songNames);
}
}
