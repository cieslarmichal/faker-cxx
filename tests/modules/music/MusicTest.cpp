#include "faker-cxx/Music.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "music/data/Artists.h"
#include "music/data/Genres.h"
#include "music/data/SongNames.h"

using namespace ::testing;
using namespace faker;

class MusicTest : public Test
{
public:
};

TEST_F(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = Music::artist();

    ASSERT_TRUE(std::ranges::any_of(artists, [generatedArtist](const std::string& artist)
                                    { return generatedArtist == artist; }));
}

TEST_F(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = Music::genre();

    ASSERT_TRUE(
        std::ranges::any_of(genres, [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = Music::songName();

    ASSERT_TRUE(std::ranges::any_of(songNames, [generatedSongName](const std::string& songName)
                                    { return generatedSongName == songName; }));
}
