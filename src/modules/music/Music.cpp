#include "faker-cxx/Music.h"

#include "data/Artists.h"
#include "data/Genres.h"
#include "data/SongNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Music::artist()
{
    return Helper::arrayElement<std::string>(artists);
}

std::string Music::genre()
{
    return Helper::arrayElement<std::string>(genres);
}

std::string Music::songName()
{
    return Helper::arrayElement<std::string>(songNames);
}
}
