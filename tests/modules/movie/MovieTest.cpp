#include "faker-cxx/Movie.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "movie/MovieData.h"

using namespace ::testing;
using namespace faker;

class MovieTest : public Test
{
public:
};

TEST_F(MovieTest, shouldGenerateGenre)
{
    const auto generatedGenre = Movie::genre();

    ASSERT_TRUE(std::ranges::any_of(movieGenres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = Movie::movieTitle();

    ASSERT_TRUE(std::ranges::any_of(movies, [generatedMovieTitle](const std::string_view& movieTitle)
                                    { return generatedMovieTitle == movieTitle; }));
}

TEST_F(MovieTest, shouldGenerateTvShow)
{
    const auto generatedTvShow = Movie::tvShow();

    ASSERT_TRUE(std::ranges::any_of(tvShows, [generatedTvShow](const std::string_view& tvShow)
                                    { return generatedTvShow == tvShow; }));
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = Movie::director();

    ASSERT_TRUE(std::ranges::any_of(directors, [generatedDirector](const std::string_view& director)
                                    { return generatedDirector == director; }));
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = Movie::actor();

    ASSERT_TRUE(std::ranges::any_of(actors, [generatedActor](const std::string_view& actor)
                                    { return generatedActor == actor; }));
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = Movie::actress();

    ASSERT_TRUE(std::ranges::any_of(actresses, [generatedActress](const std::string_view& actress)
                                    { return generatedActress == actress; }));
}
