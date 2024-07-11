#include "faker-cxx/video_game.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "video_game_data.h"

namespace faker::videogame
{
std::string_view gameTitle()
{
    return helper::arrayElement(videoGameNames);
}

std::string_view genre()
{
    return helper::arrayElement(videoGameGenres);
}

std::string_view platform()
{
    return helper::arrayElement(platforms);
}

std::string_view studioName()
{
    return helper::arrayElement(studioNames);
}
}
