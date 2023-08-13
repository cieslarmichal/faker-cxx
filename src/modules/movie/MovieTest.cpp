#include "faker-cxx/Movie.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/Actors.h"
#include "data/Actresses.h"
#include "data/Directors.h"
#include "data/Genres.h"
#include "data/MovieTitles.h"

using namespace ::testing;
using namespace faker;

class MovieTest : public Test
{
public:
};

TEST_F(MovieTest, shouldGenerateGenre)
{
    const auto generatedGenre = Movie::genre();

    ASSERT_TRUE(std::any_of(genres.begin(), genres.end(),
                            [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(MovieTest, shouldGenerateMovieTitle)
{
    const auto generatedMovieTitle = Movie::movieTitle();

    ASSERT_TRUE(std::any_of(movieTitles.begin(), movieTitles.end(),
                            [generatedMovieTitle](const std::string& movieTitle)
                            { return generatedMovieTitle == movieTitle; }));
}

TEST_F(MovieTest, shouldGenerateDirector)
{
    const auto generatedDirector = Movie::director();

    ASSERT_TRUE(std::any_of(directors.begin(), directors.end(),
                            [generatedDirector](const std::string& director)
                            { return generatedDirector == director; }));
}

TEST_F(MovieTest, shouldGenerateActor)
{
    const auto generatedActor = Movie::actor();

    ASSERT_TRUE(std::any_of(actors.begin(), actors.end(),
                            [generatedActor](const std::string& actor) { return generatedActor == actor; }));
}

TEST_F(MovieTest, shouldGenerateActress)
{
    const auto generatedActress = Movie::actress();

    ASSERT_TRUE(std::any_of(actresses.begin(), actresses.end(),
                            [generatedActress](const std::string& actress) { return generatedActress == actress; }));
}
