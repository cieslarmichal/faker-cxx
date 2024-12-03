#include "faker-cxx/music.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "music_data.h"

namespace faker::music
{
namespace
{
const struct MusicDefinition& getMusicDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSMusicDefinition;
    }
}
}

std::string_view artist(Locale locale)
{
    const auto& musicDefinition = getMusicDefinition(locale);
    return helper::randomElement(musicDefinition.artists);
}

std::string_view genre(Locale locale)
{
    const auto& musicDefinition = getMusicDefinition(locale);
    return helper::randomElement(musicDefinition.musicGenres);
}

std::string_view songName(Locale locale)
{
    const auto& musicDefinition = getMusicDefinition(locale);
    return helper::randomElement(musicDefinition.songNames);
}
}
