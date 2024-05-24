#include "faker-cxx/Movie.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/Actors.h"
#include "data/Actresses.h"
#include "data/Directors.h"
#include "data/Genres.h"
#include "data/Movies.h"
#include "data/TvShows.h"

using namespace ::testing;
using namespace faker;

class MovieTest : public Test
{
public:
};

TEST_F(MovieTest, shouldGenerateGenre)
{
    const auto generatedGenre = Movie::genre();

    ASSERT_TRUE(
        std::ranges::any_of(genres, [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = Movie::movieTitle();

    ASSERT_TRUE(std::ranges::any_of(movies, [generatedMovieTitle](const std::string& movieTitle)
                                    { return generatedMovieTitle == movieTitle; }));
}

TEST_F(MovieTest, shouldGenerateTvShow)
{
    const auto generatedTvShow = Movie::tvShow();

    ASSERT_TRUE(std::ranges::any_of(tvShows, [generatedTvShow](const std::string& tvShow)
                                    { return generatedTvShow == tvShow; }));
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = Movie::director();

    ASSERT_TRUE(std::ranges::any_of(directors, [generatedDirector](const std::string& director)
                                    { return generatedDirector == director; }));
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = Movie::actor();

    ASSERT_TRUE(
        std::ranges::any_of(actors, [generatedActor](const std::string& actor) { return generatedActor == actor; }));
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = Movie::actress();

    ASSERT_TRUE(std::ranges::any_of(actresses, [generatedActress](const std::string& actress)
                                    { return generatedActress == actress; }));
}
