#include "faker-cxx/VideoGame.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/GameTitles.h"
#include "data/Genres.h"
#include "data/Platforms.h"
#include "data/StudioNames.h"

using namespace ::testing;
using namespace faker;

class VideoGameTest : public Test
{
public:
};

TEST_F(VideoGameTest, shouldGenerateGameTitle)
{
    const auto generatedGameTitle = VideoGame::gameTitle();

    ASSERT_TRUE(std::ranges::any_of(videoGameNames, [generatedGameTitle](const std::string& gameTitle)
                                    { return generatedGameTitle == gameTitle; }));
}

TEST_F(VideoGameTest, shouldGenerateGenre)
{
    const auto generatedGenre = VideoGame::genre();

    ASSERT_TRUE(
        std::ranges::any_of(genres, [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(VideoGameTest, shouldGeneratePlatform)
{
    const auto generatedPlatform = VideoGame::platform();

    ASSERT_TRUE(std::ranges::any_of(platforms, [generatedPlatform](const std::string& platform)
                                    { return generatedPlatform == platform; }));
}

TEST_F(VideoGameTest, shouldGenerateStudioName)
{
    const auto generatedStudioName = VideoGame::studioName();

    ASSERT_TRUE(std::ranges::any_of(studioNames, [generatedStudioName](const std::string& studioName)
                                    { return generatedStudioName == studioName; }));
}
