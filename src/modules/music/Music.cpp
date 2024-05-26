#include "faker-cxx/Music.h"

#include "data/Artists.h"
#include "data/Genres.h"
#include "data/SongNames.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Music::artist()
{
    return Helper::arrayElement(artists);
}

std::string_view Music::genre()
{
    return Helper::arrayElement(musicGenres);
}

std::string_view Music::songName()
{
    return Helper::arrayElement(songNames);
}
}
