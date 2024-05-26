#include "faker-cxx/Music.h"

#include "MusicData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Music::artist()
{
    return Helper::arrayElement(music::artists);
}

std::string_view Music::genre()
{
    return Helper::arrayElement(music::musicGenres);
}

std::string_view Music::songName()
{
    return Helper::arrayElement(music::songNames);
}
}
