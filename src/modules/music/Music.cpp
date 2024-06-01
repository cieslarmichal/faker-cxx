#include "faker-cxx/Music.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MusicData.h"

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
