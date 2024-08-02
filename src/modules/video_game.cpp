#include "faker-cxx/video_game.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "video_game_data.h"

namespace faker::videogame
{
std::string_view gameTitle()
{
    return helper::randomElement(videoGameNames);
}

std::string_view genre()
{
    return helper::randomElement(videoGameGenres);
}

std::string_view platform()
{
    return helper::randomElement(platforms);
}

std::string_view studioName()
{
    return helper::randomElement(studioNames);
}
}
