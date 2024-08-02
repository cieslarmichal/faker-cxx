#include "faker-cxx/music.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "music_data.h"

namespace faker::music
{
std::string_view artist()
{
    return helper::randomElement(artists);
}

std::string_view genre()
{
    return helper::randomElement(musicGenres);
}

std::string_view songName()
{
    return helper::randomElement(songNames);
}
}
