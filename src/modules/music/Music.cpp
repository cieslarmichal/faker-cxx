#include "faker-cxx/Music.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MusicData.h"

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
