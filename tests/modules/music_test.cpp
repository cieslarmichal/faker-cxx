#include "../test_helpers.h"
#include <algorithm>
#include <faker/music.h>
#include <modules/music_data.h>

using namespace ::testing;
using namespace faker;

class MusicTest : public Test {
public:
};

TEST_F(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = music::artist();

    ASSERT_TRUE(faker::testing::contains(music::artists, generatedArtist));
}

TEST_F(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = music::genre();

    ASSERT_TRUE(faker::testing::contains(music::genres, generatedGenre));
}

TEST_F(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = music::songName();

    ASSERT_TRUE(faker::testing::contains(music::songNames, generatedSongName));
}
