#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/movie.h"
#include "movie_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::movie;

namespace
{
const struct MovieDefinition& getMovie(Locale locale)
{
    switch (locale)
    {
        default:
            return enUSmoviesDefinitions;
    }
}
}

class MovieTest : public TestWithParam<Locale>
{
public:
};

TEST_P(MovieTest, shouldGenerateGenreLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto& generatedGenre = genre(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.genres, [generatedGenre](const std::string_view& genre)
                                    { return generatedGenre == genre; }));
}

TEST_P(MovieTest, shouldGenerateMovieTitleLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto generatedMovieTitle = movieTitle(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.movies, [generatedMovieTitle](const std::string_view& movieTitle)
                                    { return generatedMovieTitle == movieTitle; }));
}

TEST_P(MovieTest, shouldGenerateTvShowLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto generatedTvShow = tvShow(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.tvShows, [generatedTvShow](const std::string_view& tvShow)
                                    { return generatedTvShow == tvShow; }));
}

TEST_P(MovieTest, shouldGenerateDirectorLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto generatedDirector = director(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.directors, [generatedDirector](const std::string_view& director)
                                    { return generatedDirector == director; }));
}

TEST_P(MovieTest, shouldGenerateActorLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto generatedActor = actor(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.actors, [generatedActor](const std::string_view& actor)
                                    { return generatedActor == actor; }));
}

TEST_P(MovieTest, shouldGenerateActressLocale)
{
    const auto locale = GetParam();

    const auto& movie = getMovie(locale);

    const auto generatedActress = actress(locale);

    ASSERT_TRUE(std::ranges::any_of(movie.actresses, [generatedActress](const std::string_view& actress)
                                    { return generatedActress == actress; }));
}
