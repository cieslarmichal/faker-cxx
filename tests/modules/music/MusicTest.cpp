#include "faker-cxx/Music.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "music/MusicData.h"

using namespace ::testing;
using namespace faker;

class MusicTest : public Test
{
public:
};

TEST_F(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = Music::artist();

    ASSERT_TRUE(std::ranges::any_of(music::artists, [generatedArtist](const std::string_view& artist)
                                    { return generatedArtist == artist; }));
}

TEST_F(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = Music::genre();

    ASSERT_TRUE(std::ranges::any_of(music::musicGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_F(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = Music::songName();

    ASSERT_TRUE(std::ranges::any_of(music::songNames, [generatedSongName](const std::string_view& songName)
                                    { return generatedSongName == songName; }));
}
