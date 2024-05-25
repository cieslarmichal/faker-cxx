#include "faker-cxx/VideoGame.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "videoGame/VideoGameData.h"

using namespace ::testing;
using namespace faker;

class VideoGameTest : public Test
{
public:
};

TEST_F(VideoGameTest, shouldGenerateGameTitle)
{
    const auto generatedGameTitle = VideoGame::gameTitle();

    ASSERT_TRUE(std::ranges::any_of(videoGameNames, [generatedGameTitle](const std::string_view& gameTitle)
                                    { return generatedGameTitle == gameTitle; }));
}

TEST_F(VideoGameTest, shouldGenerateGenre)
{
    const auto generatedGenre = VideoGame::genre();

    ASSERT_TRUE(std::ranges::any_of(genres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_F(VideoGameTest, shouldGeneratePlatform)
{
    const auto generatedPlatform = VideoGame::platform();

    ASSERT_TRUE(std::ranges::any_of(platforms, [generatedPlatform](const std::string_view& platform)
                                    { return generatedPlatform == platform; }));
}

TEST_F(VideoGameTest, shouldGenerateStudioName)
{
    const auto generatedStudioName = VideoGame::studioName();

    ASSERT_TRUE(std::ranges::any_of(studioNames, [generatedStudioName](const std::string_view& studioName)
                                    { return generatedStudioName == studioName; }));
}
