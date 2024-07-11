#include "faker-cxx/movie.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "movie/movie_data.h"

using namespace ::testing;
using namespace faker::movie;

class MovieTest : public Test
{
public:
};

TEST_F(MovieTest, shouldGenerateGenre)
{
    const auto generatedGenre = genre();

    ASSERT_TRUE(std::ranges::any_of(movieGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = movieTitle();

    ASSERT_TRUE(std::ranges::any_of(movies, [generatedMovieTitle](const std::string_view& movieTitle)
                                    { return generatedMovieTitle == movieTitle; }));
}

TEST_F(MovieTest, shouldGenerateTvShow)
{
    const auto generatedTvShow = tvShow();

    ASSERT_TRUE(std::ranges::any_of(tvShows, [generatedTvShow](const std::string_view& tvShow)
                                    { return generatedTvShow == tvShow; }));
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = director();

    ASSERT_TRUE(std::ranges::any_of(directors, [generatedDirector](const std::string_view& director)
                                    { return generatedDirector == director; }));
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = actor();

    ASSERT_TRUE(std::ranges::any_of(actors, [generatedActor](const std::string_view& actor)
                                    { return generatedActor == actor; }));
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = actress();

    ASSERT_TRUE(std::ranges::any_of(actresses, [generatedActress](const std::string_view& actress)
                                    { return generatedActress == actress; }));
}
