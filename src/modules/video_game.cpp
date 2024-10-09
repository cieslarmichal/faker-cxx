#include "faker-cxx/video_game.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "video_game_data.h"

namespace faker::videogame
{
namespace
{
const struct VideoGames& getVideoGame(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSVideoGames;
    }
}
}

std::string_view gameTitle(Locale locale)
{
    const auto& videoGame = getVideoGame(locale);

    return helper::randomElement(videoGame.videoGameNames);
}

std::string_view genre(Locale locale)
{
    const auto& videoGame = getVideoGame(locale);

    return helper::randomElement(videoGame.videoGameGenres);
}

std::string_view platform(Locale locale)
{
    const auto& videoGame = getVideoGame(locale);

    return helper::randomElement(videoGame.platforms);
}

std::string_view studioName(Locale locale)
{
    const auto& videoGame = getVideoGame(locale);

    return helper::randomElement(videoGame.studioNames);
}
}
