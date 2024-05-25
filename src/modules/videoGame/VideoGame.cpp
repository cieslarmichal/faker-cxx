#include "faker-cxx/VideoGame.h"

#include "VideoGameData.h"
#include "faker-cxx/Helper.h"


namespace faker
{
std::string_view VideoGame::gameTitle()
{
    return Helper::arrayElement(videoGame::videoGameNames);
}

std::string_view VideoGame::genre()
{
    return Helper::arrayElement(videoGame::genres);
}

std::string_view VideoGame::platform()
{
    return Helper::arrayElement(videoGame::platforms);
}

std::string_view VideoGame::studioName()
{
    return Helper::arrayElement(videoGame::studioNames);
}
}
