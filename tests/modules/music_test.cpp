#include "faker-cxx/music.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "music_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::music;

class MusicTest : public Test
{
public:
};

TEST_F(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = artist();

    ASSERT_TRUE(std::ranges::any_of(artists, [generatedArtist](const std::string_view& artist)
                                    { return generatedArtist == artist; }));
}

TEST_F(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = genre();

    ASSERT_TRUE(std::ranges::any_of(musicGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_F(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = songName();

    ASSERT_TRUE(std::ranges::any_of(songNames, [generatedSongName](const std::string_view& songName)
                                    { return generatedSongName == songName; }));
}
