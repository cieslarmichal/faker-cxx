#include "faker-cxx/VideoGame.h"

#include "data/GameTitles.h"
#include "data/Genres.h"
#include "data/Platforms.h"
#include "data/StudioNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string VideoGame::gameTitle()
{
    return Helper::arrayElement<std::string>(videoGameNames);
}

std::string VideoGame::genre()
{
    return Helper::arrayElement<std::string>(genres);
}

std::string VideoGame::platform()
{
    return Helper::arrayElement<std::string>(platforms);
}

std::string VideoGame::studioName()
{
    return Helper::arrayElement<std::string>(studioNames);
}
}
