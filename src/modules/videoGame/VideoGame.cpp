#include "faker-cxx/VideoGame.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "VideoGameData.h"

namespace faker::videogame
{
std::string_view gameTitle()
{
    return Helper::arrayElement(videoGameNames);
}

std::string_view genre()
{
    return Helper::arrayElement(videoGameGenres);
}

std::string_view platform()
{
    return Helper::arrayElement(platforms);
}

std::string_view studioName()
{
    return Helper::arrayElement(studioNames);
}
}
