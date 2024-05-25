#include "faker-cxx/VideoGame.h"

#include "VideoGameData.h"
#include "faker-cxx/Helper.h"


namespace faker
{
std::string_view VideoGame::gameTitle()
{
    return Helper::arrayElement(videoGameNames);
}

std::string_view VideoGame::genre()
{
    return Helper::arrayElement(genres);
}

std::string_view VideoGame::platform()
{
    return Helper::arrayElement(platforms);
}

std::string_view VideoGame::studioName()
{
    return Helper::arrayElement(studioNames);
}
}
