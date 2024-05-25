#include <string_view>

#include "faker-cxx/VideoGame.h"

#include "VideoGameData.h"

namespace faker
{
std::string_view VideoGame::gameTitle()
{
    return Helper::arrayElement<std::string_view>(videoGameNames);
}

std::string_view VideoGame::genre()
{
    return Helper::arrayElement<std::string_view>(genres);
}

std::string_view VideoGame::platform()
{
    return Helper::arrayElement<std::string_view>(platforms);
}

std::string_view VideoGame::studioName()
{
    return Helper::arrayElement<std::string_view>(studioNames);
}
}
