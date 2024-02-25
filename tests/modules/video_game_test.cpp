#include "../test_helpers.h"
#include <algorithm>
#include <faker/video_game.h>
#include <modules/video_game_data.h>

using namespace ::testing;
using namespace faker;

class VideoGameTest : public Test {
public:
};

TEST_F(VideoGameTest, shouldGenerateGameTitle)
{
    const auto generatedGameTitle = video_game::gameTitle();

    ASSERT_TRUE(
        faker::testing::any_of(videoGameNames, [generatedGameTitle](const std::string& gameTitle) {
            return generatedGameTitle == gameTitle;
        }));
}

TEST_F(VideoGameTest, shouldGenerateGenre)
{
    const auto generatedGenre = video_game::genre();

    ASSERT_TRUE(faker::testing::any_of(
        genres, [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(VideoGameTest, shouldGeneratePlatform)
{
    const auto generatedPlatform = video_game::platform();

    ASSERT_TRUE(faker::testing::any_of(platforms, [generatedPlatform](const std::string& platform) {
        return generatedPlatform == platform;
    }));
}

TEST_F(VideoGameTest, shouldGenerateStudioName)
{
    const auto generatedStudioName = video_game::studioName();

    ASSERT_TRUE(
        faker::testing::any_of(studioNames, [generatedStudioName](const std::string& studioName) {
            return generatedStudioName == studioName;
        }));
}
