#include "faker-cxx/movie.h"
#include <string_view>
#include "faker-cxx/helper.h"
#include "movie_data.h"

namespace faker::movie
{
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
std::string_view genre(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.genres);
}

std::string_view movieTitle(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.movies);
}

std::string_view tvShow(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.tvShows);
}

std::string_view director(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.directors);
}

std::string_view actor(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.actors);
}

std::string_view actress(Locale locale)
{
    const auto& movie = getMovie(locale);

    return helper::randomElement(movie.actresses);
}

}