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

    FAKER_EXPECT_CONTAINS(movie::genres, generatedGenre);
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = movie::movieTitle();

    FAKER_EXPECT_CONTAINS(movie::movies, generatedMovieTitle);
}

TEST_F(MovieTest, shouldGenerateTvShow)
{
    const auto generatedTvShow = movie::tvShow();

    FAKER_EXPECT_CONTAINS(movie::tvShows, generatedTvShow);
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = movie::director();

    FAKER_EXPECT_CONTAINS(movie::directors, generatedDirector);
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = movie::actor();

    FAKER_EXPECT_CONTAINS(movie::actors, generatedActor);
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = movie::actress();

    FAKER_EXPECT_CONTAINS(movie::actresses, generatedActress);
}
