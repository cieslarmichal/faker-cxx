#include "../test_helpers.h"
#include <faker/music.h>
#include <modules/music_data.h>

using namespace faker;

TEST(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = music::artist();

    FAKER_EXPECT_CONTAINS(music::artists, generatedArtist);
}

TEST(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = music::genre();

    FAKER_EXPECT_CONTAINS(music::genres, generatedGenre);
}

TEST(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = music::songName();

    FAKER_EXPECT_CONTAINS(music::songNames, generatedSongName);
}
