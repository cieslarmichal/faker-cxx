#include "../test_helpers.h"
#include <faker/video_game.h>
#include <modules/video_game_data.h>

using namespace faker;

TEST(VideoGameTest, shouldGenerateGameTitle)
{
    auto generatedGameTitle = video_game::title();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::video_game_names, generatedGameTitle);
}

TEST(VideoGameTest, shouldGenerateGenre)
{
    auto generatedGenre = video_game::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::genres, generatedGenre);
}

TEST(VideoGameTest, shouldGeneratePlatform)
{
    auto generatedPlatform = video_game::platform();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::platforms, generatedPlatform);
}

TEST(VideoGameTest, shouldGenerateStudioName)
{
    auto generatedStudioName = faker::video_game::studio_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::studio_names, generatedStudioName);
}
