#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/music.h"
#include "music_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::music;

namespace
{
const struct MusicDefinition& getMusicDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSMusicDefinition;
    }
}
}

class MusicTest : public TestWithParam<Locale>
{
public:
};

TEST_P(MusicTest, shouldGenerateArtist)
{
    const auto locale = GetParam();
    const auto& musicDefinition = getMusicDefinition(locale);
    const auto generatedArtist = artist();

    ASSERT_TRUE(std::ranges::any_of(musicDefinition.artists, [generatedArtist](const std::string_view& artist)
                                    { return generatedArtist == artist; }));
}

TEST_P(MusicTest, shouldGenerateGenre)
{
    const auto locale = GetParam();
    const auto& musicDefinition = getMusicDefinition(locale);
    const auto generatedGenre = genre();

    ASSERT_TRUE(std::ranges::any_of(musicDefinition.musicGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_P(MusicTest, shouldGenerateSongName)
{
    const auto locale = GetParam();
    const auto& musicDefinition = getMusicDefinition(locale);
    const auto generatedSongName = songName();

    ASSERT_TRUE(std::ranges::any_of(musicDefinition.songNames, [generatedSongName](const std::string_view& songName)
                                    { return generatedSongName == songName; }));
}

INSTANTIATE_TEST_SUITE_P(TestMusicByLocale, MusicTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
