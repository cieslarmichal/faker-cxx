#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/video_game.h"
#include "video_game_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::videogame;

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

class VideoGameTest : public TestWithParam<Locale>
{
public:
};

TEST_P(VideoGameTest, shouldGenerateGameTitle)
{
    const auto locale = GetParam();

    const auto& videoGame = getVideoGame(locale);

    const auto generatedGameTitle = gameTitle(locale);

    ASSERT_TRUE(std::ranges::any_of(videoGame.videoGameNames, [generatedGameTitle](const std::string_view& gameTitle)
                                    { return generatedGameTitle == gameTitle; }));
}

TEST_P(VideoGameTest, shouldGenerateGenre)
{
    const auto locale = GetParam();

    const auto& videoGame = getVideoGame(locale);

    const auto generatedGenre = genre(locale);

    ASSERT_TRUE(std::ranges::any_of(videoGame.videoGameGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_P(VideoGameTest, shouldGeneratePlatform)
{
    const auto locale = GetParam();

    const auto& videoGame = getVideoGame(locale);

    const auto generatedPlatform = platform(locale);

    ASSERT_TRUE(std::ranges::any_of(videoGame.platforms, [generatedPlatform](const std::string_view& platform)
                                    { return generatedPlatform == platform; }));
}

TEST_P(VideoGameTest, shouldGenerateStudioName)
{
    const auto locale = GetParam();

    const auto& videoGame = getVideoGame(locale);

    const auto generatedStudioName = studioName(locale);

    ASSERT_TRUE(std::ranges::any_of(videoGame.studioNames, [generatedStudioName](const std::string_view& studioName)
                                    { return generatedStudioName == studioName; }));
}


INSTANTIATE_TEST_SUITE_P(TestVideoGameByLocale, VideoGameTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
