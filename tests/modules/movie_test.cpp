#include "../test_helpers.h"
#include <faker/movie.h>
#include <modules/movie_data.h>

using namespace faker;

TEST(MovieTest, shouldGenerateGenre)
{
    auto generatedGenre = movie::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::genres, generatedGenre);
}

TEST(MovieTest, shouldGenerateMovieTitle)
{
    auto generatedMovieTitle = movie::movie_title();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::movies, generatedMovieTitle);
}

TEST(MovieTest, shouldGenerateTvShow)
{
    auto generatedTvShow = movie::tv_show();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::tv_shows, generatedTvShow);
}

TEST(MovieTest, shouldGenerateDirector)
{
    auto generatedDirector = movie::director();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::directors, generatedDirector);
}

TEST(MovieTest, shouldGenerateActor)
{
    auto generatedActor = movie::actor();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::actors, generatedActor);
}

TEST(MovieTest, shouldGenerateActress)
{
    auto generatedActress = movie::actress();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::actresses, generatedActress);
}
