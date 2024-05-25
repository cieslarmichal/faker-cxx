#include <string_view>

#include "faker-cxx/VideoGame.h"

#include "data/VideoGameData.h"

namespace faker
{
std::string VideoGame::gameTitle()
{
    return Helper::arrayElement<std::string_view>(videoGameNames);
}

std::string VideoGame::genre()
{
    return Helper::arrayElement<std::string_view>(genres);
}

std::string VideoGame::platform()
{
    return Helper::arrayElement<std::string_view>(platforms);
}

std::string VideoGame::studioName()
{
    return Helper::arrayElement<std::string_view>(studioNames);
}
}
