#include "../test_helpers.h"
#include <algorithm>
#include <faker/movie.h>
#include <modules/movie_data.h>

using namespace ::testing;
using namespace faker;

class MovieTest : public Test {
public:
};

TEST_F(MovieTest, shouldGenerateGenre)
{
    const auto generatedGenre = movie::genre();

    ASSERT_TRUE(faker::testing::contains(movie::genres, generatedGenre));
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = movie::movieTitle();

    ASSERT_TRUE(faker::testing::contains(movie::movies, generatedMovieTitle));
}

TEST_F(MovieTest, shouldGenerateTvShow)
{
    const auto generatedTvShow = movie::tvShow();

    ASSERT_TRUE(faker::testing::contains(movie::tvShows, generatedTvShow));
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = movie::director();

    ASSERT_TRUE(faker::testing::contains(movie::directors, generatedDirector));
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = movie::actor();

    ASSERT_TRUE(faker::testing::contains(movie::actors, generatedActor));
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = movie::actress();

    ASSERT_TRUE(faker::testing::contains(movie::actresses, generatedActress));
}
